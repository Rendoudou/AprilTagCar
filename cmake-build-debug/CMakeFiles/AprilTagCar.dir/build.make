# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/doudou/apriltag_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/doudou/apriltag_test/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AprilTagCar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AprilTagCar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AprilTagCar.dir/flags.make

CMakeFiles/AprilTagCar.dir/apriltag_car.cpp.o: CMakeFiles/AprilTagCar.dir/flags.make
CMakeFiles/AprilTagCar.dir/apriltag_car.cpp.o: ../apriltag_car.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/doudou/apriltag_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AprilTagCar.dir/apriltag_car.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AprilTagCar.dir/apriltag_car.cpp.o -c /home/doudou/apriltag_test/apriltag_car.cpp

CMakeFiles/AprilTagCar.dir/apriltag_car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AprilTagCar.dir/apriltag_car.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/doudou/apriltag_test/apriltag_car.cpp > CMakeFiles/AprilTagCar.dir/apriltag_car.cpp.i

CMakeFiles/AprilTagCar.dir/apriltag_car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AprilTagCar.dir/apriltag_car.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/doudou/apriltag_test/apriltag_car.cpp -o CMakeFiles/AprilTagCar.dir/apriltag_car.cpp.s

# Object files for target AprilTagCar
AprilTagCar_OBJECTS = \
"CMakeFiles/AprilTagCar.dir/apriltag_car.cpp.o"

# External object files for target AprilTagCar
AprilTagCar_EXTERNAL_OBJECTS =

AprilTagCar: CMakeFiles/AprilTagCar.dir/apriltag_car.cpp.o
AprilTagCar: CMakeFiles/AprilTagCar.dir/build.make
AprilTagCar: lib/libcamera_shared.so
AprilTagCar: lib/libuser_interface_shared.so
AprilTagCar: lib/libtag_detect_shared.so
AprilTagCar: /usr/local/lib/libopencv_objdetect.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_superres.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_videostab.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_dnn.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_stitching.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_shape.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_video.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_photo.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_calib3d.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_ml.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_viz.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_features2d.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_flann.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_highgui.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_videoio.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_imgcodecs.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_imgproc.so.3.4.5
AprilTagCar: /usr/local/lib/libopencv_core.so.3.4.5
AprilTagCar: /usr/local/lib/libapriltag.so
AprilTagCar: /usr/local/lib/libapriltag.so.3
AprilTagCar: /usr/local/lib/libapriltag.so.3.1.0
AprilTagCar: CMakeFiles/AprilTagCar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/doudou/apriltag_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AprilTagCar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AprilTagCar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AprilTagCar.dir/build: AprilTagCar

.PHONY : CMakeFiles/AprilTagCar.dir/build

CMakeFiles/AprilTagCar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AprilTagCar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AprilTagCar.dir/clean

CMakeFiles/AprilTagCar.dir/depend:
	cd /home/doudou/apriltag_test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/doudou/apriltag_test /home/doudou/apriltag_test /home/doudou/apriltag_test/cmake-build-debug /home/doudou/apriltag_test/cmake-build-debug /home/doudou/apriltag_test/cmake-build-debug/CMakeFiles/AprilTagCar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AprilTagCar.dir/depend
