#define MEASURE_FUNCTION_TIME
#include <pcl/common/time.h> //fps calculations
#include <pcl/io/openni_grabber.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/boost.h>
#include <pcl/visualization/image_viewer.h>
#include <pcl/common/transforms.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/console/time.h>

#define SHOW_FPS 1
#if SHOW_FPS
#define FPS_CALC(_WHAT_) \
do \
{ \
    static unsigned count = 0;\
    static double last = pcl::getTime ();\
    double now = pcl::getTime (); \
    ++count; \
    if (now - last >= 1.0) \
    { \
      std::cout << "Average framerate("<< _WHAT_ << "): " << double(count)/double(now - last) << " Hz" <<  std::endl; \
      count = 0; \
      last = now; \
    } \
}while(false)
#else
#define FPS_CALC(_WHAT_) \
do \
{ \
}while(false)
#endif

void
printHelp (int, char **argv)
{
  using pcl::console::print_error;
  using pcl::console::print_info;

  print_error ("Syntax is: %s [((<device_id> | <path-to-oni-file>) [-depthmode <mode>] [-imagemode <mode>] [-xyz] | -l [<device_id>]| -h | --help)]\n", argv [0]);
  print_info ("%s -h | --help : shows this help\n", argv [0]);
  print_info ("%s -xyz : use only XYZ values and ignore RGB components (this flag is required for use with ASUS Xtion Pro) \n", argv [0]);
  print_info ("%s -l : list all available devices\n", argv [0]);
  print_info ("%s -l <device-id> :list all available modes for specified device\n", argv [0]);
  print_info ("\t\t<device_id> may be \"#1\", \"#2\", ... for the first, second etc device in the list\n");
#ifndef _WIN32
  print_info ("\t\t                   bus@address for the device connected to a specific usb-bus / address combination\n");
  print_info ("\t\t                   <serial-number>\n");
#endif
  print_info ("\n\nexamples:\n");
  print_info ("%s \"#1\"\n", argv [0]);
  print_info ("\t\t uses the first device.\n");
  print_info ("%s  \"./temp/test.oni\"\n", argv [0]);
  print_info ("\t\t uses the oni-player device to play back oni file given by path.\n");
  print_info ("%s -l\n", argv [0]);
  print_info ("\t\t list all available devices.\n");
  print_info ("%s -l \"#2\"\n", argv [0]);
  print_info ("\t\t list all available modes for the second device.\n");
  #ifndef _WIN32
  print_info ("%s A00361800903049A\n", argv [0]);
  print_info ("\t\t uses the device with the serial number \'A00361800903049A\'.\n");
  print_info ("%s 1@16\n", argv [0]);
  print_info ("\t\t uses the device on address 16 at USB bus 1.\n");
  #endif
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename PointType>
class OpenNIViewer
{
  public:
    typedef pcl::PointCloud<PointType> Cloud;
    typedef typename Cloud::ConstPtr CloudConstPtr;

    OpenNIViewer (pcl::Grabber& grabber,pcl::Grabber& grabber2)
      : cloud_viewer_ (new pcl::visualization::PCLVisualizer ("PCL OpenNI cloud"))
      , image_viewer_()
      //, image2_viewer()
      , grabber_ (grabber)
      , grabber2_ (grabber2)
      , rgb_data_ (0), rgb_data_size_ (0)
    {
    }

    void
    cloud_callback (const CloudConstPtr& cloud)
    {
      FPS_CALC ("cloud callback");
      boost::mutex::scoped_lock lock (cloud_mutex_);
      cloud_ = cloud;
    }
    
    void
    cloud_callback2 (const CloudConstPtr& cloud)
    {
      FPS_CALC ("cloud callback");
      boost::mutex::scoped_lock lock (cloud2_mutex_);
      cloud2_ = cloud;
    }

    void
    image_callback (const boost::shared_ptr<openni_wrapper::Image>& image)
    {
      FPS_CALC ("image callback");
      boost::mutex::scoped_lock lock (image_mutex_);
      image_ = image;
      
      if (image->getEncoding () != openni_wrapper::Image::RGB)
      {
        if (rgb_data_size_ < image->getWidth () * image->getHeight ())
        {
          if (rgb_data_)
            delete [] rgb_data_;
          rgb_data_size_ = image->getWidth () * image->getHeight ();
          rgb_data_ = new unsigned char [rgb_data_size_ * 3];
        }
        image_->fillRGB (image_->getWidth (), image_->getHeight (), rgb_data_);
        }
    }
 
    /*void
    image2_callback (const boost::shared_ptr<openni_wrapper::Image>& image2)
    {
      FPS_CALC ("image2 callback");
      boost::mutex::scoped_lock lock (image2_mutex_);
      image2_ = image2;
      if (image2->getEncoding () != openni_wrapper::Image::RGB)
      {
        if (rgb_data_size_ < image2->getWidth () * image2->getHeight ())
        {
          if (rgb_data_)
            delete [] rgb_data_;
          rgb_data_size_ = image2->getWidth () * image2->getHeight ();
          rgb_data_ = new unsigned char [rgb_data_size_ * 3];
        }
        image2_->fillRGB (image2_->getWidth (), image2_->getHeight (), rgb_data_);
        }
     }
     */
    
    void 
    keyboard_callback (const pcl::visualization::KeyboardEvent& event, void*)
    {
      if (event.getKeyCode ())
        cout << "the key \'" << event.getKeyCode() << "\' (" << event.getKeyCode() << ") was";
      else
        cout << "the special key \'" << event.getKeySym() << "\' was";
      if (event.keyDown())
        cout << " pressed" << endl;
      else
        cout << " released" << endl;
    }
    
    void 
    mouse_callback (const pcl::visualization::MouseEvent& mouse_event, void*)
    {
      if (mouse_event.getType() == pcl::visualization::MouseEvent::MouseButtonPress && mouse_event.getButton() == pcl::visualization::MouseEvent::LeftButton)
      {
        cout << "left button pressed @ " << mouse_event.getX () << " , " << mouse_event.getY () << endl;
      }
    }

    /**
     * @brief starts the main loop
     */
    void
    run ()
    {
      cloud_viewer_->registerMouseCallback (&OpenNIViewer::mouse_callback, *this);
      cloud_viewer_->registerKeyboardCallback(&OpenNIViewer::keyboard_callback, *this);
      boost::function<void (const CloudConstPtr&) > cloud_cb = boost::bind (&OpenNIViewer::cloud_callback, this, _1);
            boost::function<void (const CloudConstPtr&) > cloud_cb2 = boost::bind (&OpenNIViewer::cloud_callback2, this, _1);
      boost::signals2::connection cloud_connection = grabber_.registerCallback (cloud_cb);
      boost::signals2::connection cloud_connection2 = grabber2_.registerCallback (cloud_cb2);
      
      boost::signals2::connection image_connection; boost::signals2::connection image_connection2;
      if (grabber_.providesCallback<void (const boost::shared_ptr<openni_wrapper::Image>&)>())
      {
        image_viewer_.reset (new pcl::visualization::ImageViewer ("PCL OpenNI image"));
      //image2_viewer_.reset (new pcl::visualization::ImageViewer ("PCL OpenNI image2"));
        image_viewer_->registerMouseCallback (&OpenNIViewer::mouse_callback, *this);
        image_viewer_->registerKeyboardCallback(&OpenNIViewer::keyboard_callback, *this);
      //image2_viewer_->registerMouseCallback (&OpenNIViewer::mouse_callback, *this);
      //image2_viewer_->registerKeyboardCallback(&OpenNIViewer::keyboard_callback, *this);
        boost::function<void (const boost::shared_ptr<openni_wrapper::Image>&) > image_cb = boost::bind (&OpenNIViewer::image_callback, this, _1);
      //boost::function<void (const boost::shared_ptr<openni_wrapper::Image>&) > image2_cb = boost::bind (&OpenNIViewer::image2_callback, this, _2);
        image_connection = grabber_.registerCallback (image_cb);
      //image2_connection = grabber2_.registerCallback (image2_cb);
      }
      
      bool image_init = false, cloud_init = false;
      
      grabber_.start ();grabber2_.start ();

      while (!cloud_viewer_->wasStopped () && (image_viewer_ && !image_viewer_->wasStopped ()))
      {
        boost::shared_ptr<openni_wrapper::Image> image,image2;
        CloudConstPtr cloud, cloud2;

        cloud_viewer_->spinOnce ();

        // See if we can get a cloud
        if (cloud_mutex_.try_lock ())
        {
          cloud_.swap (cloud);
          cloud_mutex_.unlock ();
        }
        
        // See if we can get a cloud
        if (cloud2_mutex_.try_lock ())
        {
          cloud2_.swap (cloud2);
          cloud2_mutex_.unlock ();
        }

        if (!cloud_init)
        {
          cloud_viewer_->setPosition (0, 0);
          cloud_viewer_->setSize (cloud->width * 2, cloud->height * 2);
          cloud_init = !cloud_init;
        }

        if (cloud)
        {
          if (!cloud_viewer_->updatePointCloud (cloud, "OpenNICloud"))
		  {
		    cloud_viewer_->addPointCloud (cloud, "OpenNICloud");
		    cloud_viewer_->resetCameraViewpoint ("OpenNICloud");
		  }
        }
        
        if(cloud2){
		    // Eigen::Matrix4f cloud2 = Eigen::Matrix4f::Identity();
		   // transform_1(0, 3) = 5.0f;
		    
		    //pcl::PointCloud<pcl::PointXYZRGBA>::Ptr transformed_cloud (new pcl::PointCloud<pcl::PointXYZRGBA> ());
		    // pcl::transformPointCloud (*cloud2, *transformed_cloud, cloud2);

		    if (!cloud_viewer_->updatePointCloud (cloud2, "OpenNICloud2"))
		    {
		      cloud_viewer_->addPointCloud (cloud2, "OpenNICloud2");
//		      cloud_viewer_->resetCameraViewpoint ("OpenNICloud");
		    }
        }
        cloud_viewer_->addCoordinateSystem(1.0, "reference", 0);
        FPS_CALC ("drawing cloud");

        // See if we can get an image
        if (image_mutex_.try_lock ())
        {
          image_.swap (image);
          image_mutex_.unlock ();
        }

        if (image)
        {
          if (!image_init && cloud && cloud->width != 0)
          {
            image_viewer_->setPosition (cloud->width, 0);
            image_viewer_->setSize (cloud->width, cloud->height);
            image_init = !image_init;
          }

          if (image->getEncoding() == openni_wrapper::Image::RGB)
            image_viewer_->addRGBImage (image->getMetaData ().Data (), image->getWidth (), image->getHeight ());
          else
            image_viewer_->addRGBImage (rgb_data_, image->getWidth (), image->getHeight ());
          image_viewer_->spinOnce ();
        }
      /* // See if we can get an image
        if (image_mutex_.try_lock ())
        {
          image_.swap (image2);
          image_mutex2_.unlock ();
        }

        if (image2)
        {
          if (!image_init && cloud && cloud->width != 0)
          {
            image2_viewer_->setPosition (cloud->width, 0);
            image2_viewer_->setSize (cloud->width, cloud->height);
            image_init = !image_init;
          }

          if (image2->getEncoding() == openni_wrapper::Image::RGB)
            image2_viewer_->addRGBImage (image2->getMetaData ().Data (), image2->getWidth (), image2->getHeight ());
          else
            image2_viewer_->addRGBImage (rgb_data_, image2->getWidth (), image2->getHeight ());
          image2_viewer_->spinOnce ();
        }     
        */
      }

      grabber_.stop ();grabber2_.stop ();
      
      cloud_connection.disconnect ();
      image_connection.disconnect ();
     // image2_connection.disconnect ();
      if (rgb_data_)
        delete[] rgb_data_;
    }
    
    boost::shared_ptr<pcl::visualization::PCLVisualizer> cloud_viewer_;
    boost::shared_ptr<pcl::visualization::ImageViewer> image_viewer_;
   // boost::shared_ptr<pcl::visualization::ImageViewer> image2_viewer_;
    pcl::Grabber& grabber_; pcl::Grabber& grabber2_;
    boost::mutex cloud_mutex_, cloud2_mutex_;
    boost::mutex image_mutex_, image2_mutex;
    
    CloudConstPtr cloud_, cloud2_;
    boost::shared_ptr<openni_wrapper::Image> image_,image2_;
    unsigned char* rgb_data_;
    unsigned rgb_data_size_;
};

// Create the PCLVisualizer object
boost::shared_ptr<pcl::visualization::PCLVisualizer> cld;
boost::shared_ptr<pcl::visualization::ImageViewer> img;

void* showpreview(void* p_did){
  std::string device_id((char*)p_did);
  pcl::OpenNIGrabber::Mode depth_mode = pcl::OpenNIGrabber::OpenNI_Default_Mode;
  pcl::OpenNIGrabber::Mode image_mode = pcl::OpenNIGrabber::OpenNI_Default_Mode;
  bool xyz = false;
  
  pcl::OpenNIGrabber grabber ("#1", depth_mode, image_mode);pcl::OpenNIGrabber grabber2 ("#2", depth_mode, image_mode);
  
  if (xyz || !grabber.providesCallback<pcl::OpenNIGrabber::sig_cb_openni_point_cloud_rgb> ())
  {
    OpenNIViewer<pcl::PointXYZRGBA> openni_viewer (grabber, grabber2);
    openni_viewer.run ();
  }
  else
  {
    OpenNIViewer<pcl::PointXYZRGBA> openni_viewer (grabber, grabber2);
    openni_viewer.run ();
  }
}

/* ---[ */
int
main (int argc, char** argv)
{
  pthread_t t1 = 0;
  pthread_create(&t1, NULL, showpreview, (void*)"#1");

  pthread_join(t1, NULL);
  return (0);
}

