# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yin/src/record

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yin/src/record/build

# Include any dependencies generated for this target.
include CMakeFiles/record.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/record.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/record.dir/flags.make

CMakeFiles/record.dir/record.cpp.o: CMakeFiles/record.dir/flags.make
CMakeFiles/record.dir/record.cpp.o: ../record.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yin/src/record/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/record.dir/record.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/record.dir/record.cpp.o -c /home/yin/src/record/record.cpp

CMakeFiles/record.dir/record.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/record.dir/record.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yin/src/record/record.cpp > CMakeFiles/record.dir/record.cpp.i

CMakeFiles/record.dir/record.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/record.dir/record.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yin/src/record/record.cpp -o CMakeFiles/record.dir/record.cpp.s

CMakeFiles/record.dir/record.cpp.o.requires:
.PHONY : CMakeFiles/record.dir/record.cpp.o.requires

CMakeFiles/record.dir/record.cpp.o.provides: CMakeFiles/record.dir/record.cpp.o.requires
	$(MAKE) -f CMakeFiles/record.dir/build.make CMakeFiles/record.dir/record.cpp.o.provides.build
.PHONY : CMakeFiles/record.dir/record.cpp.o.provides

CMakeFiles/record.dir/record.cpp.o.provides.build: CMakeFiles/record.dir/record.cpp.o

# Object files for target record
record_OBJECTS = \
"CMakeFiles/record.dir/record.cpp.o"

# External object files for target record
record_EXTERNAL_OBJECTS =

record: CMakeFiles/record.dir/record.cpp.o
record: CMakeFiles/record.dir/build.make
record: /usr/lib/x86_64-linux-gnu/libboost_system.so
record: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
record: /usr/lib/x86_64-linux-gnu/libboost_thread.so
record: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
record: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
record: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
record: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
record: /usr/lib/x86_64-linux-gnu/libpthread.so
record: /usr/lib/x86_64-linux-gnu/libpcl_common.so
record: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
record: /usr/lib/x86_64-linux-gnu/libpcl_kdtree.so
record: /usr/lib/x86_64-linux-gnu/libpcl_octree.so
record: /usr/lib/x86_64-linux-gnu/libpcl_search.so
record: /usr/lib/x86_64-linux-gnu/libpcl_sample_consensus.so
record: /usr/lib/x86_64-linux-gnu/libpcl_filters.so
record: /usr/lib/x86_64-linux-gnu/libpcl_features.so
record: /usr/lib/x86_64-linux-gnu/libpcl_registration.so
record: /usr/lib/libOpenNI.so
record: /usr/lib/libvtkCommon.so.5.8.0
record: /usr/lib/libvtkFiltering.so.5.8.0
record: /usr/lib/libvtkImaging.so.5.8.0
record: /usr/lib/libvtkGraphics.so.5.8.0
record: /usr/lib/libvtkGenericFiltering.so.5.8.0
record: /usr/lib/libvtkIO.so.5.8.0
record: /usr/lib/libvtkRendering.so.5.8.0
record: /usr/lib/libvtkVolumeRendering.so.5.8.0
record: /usr/lib/libvtkHybrid.so.5.8.0
record: /usr/lib/libvtkWidgets.so.5.8.0
record: /usr/lib/libvtkParallel.so.5.8.0
record: /usr/lib/libvtkInfovis.so.5.8.0
record: /usr/lib/libvtkGeovis.so.5.8.0
record: /usr/lib/libvtkViews.so.5.8.0
record: /usr/lib/libvtkCharts.so.5.8.0
record: /usr/lib/x86_64-linux-gnu/libpcl_io.so
record: /usr/lib/x86_64-linux-gnu/libpcl_visualization.so
record: /usr/lib/x86_64-linux-gnu/libpcl_segmentation.so
record: /usr/lib/x86_64-linux-gnu/libpcl_people.so
record: /usr/lib/x86_64-linux-gnu/libqhull.so
record: /usr/lib/x86_64-linux-gnu/libpcl_surface.so
record: /usr/lib/x86_64-linux-gnu/libpcl_outofcore.so
record: /usr/lib/x86_64-linux-gnu/libpcl_recognition.so
record: /usr/lib/x86_64-linux-gnu/libpcl_keypoints.so
record: /usr/lib/x86_64-linux-gnu/libpcl_tracking.so
record: /usr/lib/x86_64-linux-gnu/libboost_system.so
record: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
record: /usr/lib/x86_64-linux-gnu/libboost_thread.so
record: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
record: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
record: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
record: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
record: /usr/lib/x86_64-linux-gnu/libpthread.so
record: /usr/lib/x86_64-linux-gnu/libqhull.so
record: /usr/lib/libOpenNI.so
record: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
record: /usr/lib/libvtkCommon.so.5.8.0
record: /usr/lib/libvtkFiltering.so.5.8.0
record: /usr/lib/libvtkImaging.so.5.8.0
record: /usr/lib/libvtkGraphics.so.5.8.0
record: /usr/lib/libvtkGenericFiltering.so.5.8.0
record: /usr/lib/libvtkIO.so.5.8.0
record: /usr/lib/libvtkRendering.so.5.8.0
record: /usr/lib/libvtkVolumeRendering.so.5.8.0
record: /usr/lib/libvtkHybrid.so.5.8.0
record: /usr/lib/libvtkWidgets.so.5.8.0
record: /usr/lib/libvtkParallel.so.5.8.0
record: /usr/lib/libvtkInfovis.so.5.8.0
record: /usr/lib/libvtkGeovis.so.5.8.0
record: /usr/lib/libvtkViews.so.5.8.0
record: /usr/lib/libvtkCharts.so.5.8.0
record: /usr/lib/x86_64-linux-gnu/libpcl_common.so
record: /usr/lib/x86_64-linux-gnu/libpcl_kdtree.so
record: /usr/lib/x86_64-linux-gnu/libpcl_octree.so
record: /usr/lib/x86_64-linux-gnu/libpcl_search.so
record: /usr/lib/x86_64-linux-gnu/libpcl_sample_consensus.so
record: /usr/lib/x86_64-linux-gnu/libpcl_filters.so
record: /usr/lib/x86_64-linux-gnu/libpcl_features.so
record: /usr/lib/x86_64-linux-gnu/libpcl_registration.so
record: /usr/lib/x86_64-linux-gnu/libpcl_io.so
record: /usr/lib/x86_64-linux-gnu/libpcl_visualization.so
record: /usr/lib/x86_64-linux-gnu/libpcl_segmentation.so
record: /usr/lib/x86_64-linux-gnu/libpcl_people.so
record: /usr/lib/x86_64-linux-gnu/libpcl_surface.so
record: /usr/lib/x86_64-linux-gnu/libpcl_outofcore.so
record: /usr/lib/x86_64-linux-gnu/libpcl_recognition.so
record: /usr/lib/x86_64-linux-gnu/libpcl_keypoints.so
record: /usr/lib/x86_64-linux-gnu/libpcl_tracking.so
record: /usr/lib/libvtkViews.so.5.8.0
record: /usr/lib/libvtkInfovis.so.5.8.0
record: /usr/lib/libvtkWidgets.so.5.8.0
record: /usr/lib/libvtkVolumeRendering.so.5.8.0
record: /usr/lib/libvtkHybrid.so.5.8.0
record: /usr/lib/libvtkParallel.so.5.8.0
record: /usr/lib/libvtkRendering.so.5.8.0
record: /usr/lib/libvtkImaging.so.5.8.0
record: /usr/lib/libvtkGraphics.so.5.8.0
record: /usr/lib/libvtkIO.so.5.8.0
record: /usr/lib/libvtkFiltering.so.5.8.0
record: /usr/lib/libvtkCommon.so.5.8.0
record: /usr/lib/libvtksys.so.5.8.0
record: CMakeFiles/record.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable record"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/record.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/record.dir/build: record
.PHONY : CMakeFiles/record.dir/build

CMakeFiles/record.dir/requires: CMakeFiles/record.dir/record.cpp.o.requires
.PHONY : CMakeFiles/record.dir/requires

CMakeFiles/record.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/record.dir/cmake_clean.cmake
.PHONY : CMakeFiles/record.dir/clean

CMakeFiles/record.dir/depend:
	cd /home/yin/src/record/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yin/src/record /home/yin/src/record /home/yin/src/record/build /home/yin/src/record/build /home/yin/src/record/build/CMakeFiles/record.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/record.dir/depend
