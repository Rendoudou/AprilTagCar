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
CMAKE_SOURCE_DIR = /home/doudou/apriltag_car

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/doudou/apriltag_car/cmake-build-debug

# Include any dependencies generated for this target.
include lib/CMakeFiles/user_interface_shared.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/user_interface_shared.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/user_interface_shared.dir/flags.make

lib/CMakeFiles/user_interface_shared.dir/user_interface.cpp.o: lib/CMakeFiles/user_interface_shared.dir/flags.make
lib/CMakeFiles/user_interface_shared.dir/user_interface.cpp.o: ../lib/user_interface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/doudou/apriltag_car/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/user_interface_shared.dir/user_interface.cpp.o"
	cd /home/doudou/apriltag_car/cmake-build-debug/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/user_interface_shared.dir/user_interface.cpp.o -c /home/doudou/apriltag_car/lib/user_interface.cpp

lib/CMakeFiles/user_interface_shared.dir/user_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/user_interface_shared.dir/user_interface.cpp.i"
	cd /home/doudou/apriltag_car/cmake-build-debug/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/doudou/apriltag_car/lib/user_interface.cpp > CMakeFiles/user_interface_shared.dir/user_interface.cpp.i

lib/CMakeFiles/user_interface_shared.dir/user_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/user_interface_shared.dir/user_interface.cpp.s"
	cd /home/doudou/apriltag_car/cmake-build-debug/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/doudou/apriltag_car/lib/user_interface.cpp -o CMakeFiles/user_interface_shared.dir/user_interface.cpp.s

# Object files for target user_interface_shared
user_interface_shared_OBJECTS = \
"CMakeFiles/user_interface_shared.dir/user_interface.cpp.o"

# External object files for target user_interface_shared
user_interface_shared_EXTERNAL_OBJECTS =

lib/libuser_interface_shared.so: lib/CMakeFiles/user_interface_shared.dir/user_interface.cpp.o
lib/libuser_interface_shared.so: lib/CMakeFiles/user_interface_shared.dir/build.make
lib/libuser_interface_shared.so: lib/libtag_detect_shared.so
lib/libuser_interface_shared.so: /usr/local/lib/libapriltag.so
lib/libuser_interface_shared.so: /usr/local/lib/libapriltag.so.3
lib/libuser_interface_shared.so: /usr/local/lib/libapriltag.so.3.1.0
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_objdetect.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_superres.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_videostab.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_dnn.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_stitching.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_shape.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_video.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_photo.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_calib3d.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_ml.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_viz.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_features2d.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_flann.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_highgui.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_videoio.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_imgcodecs.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_imgproc.so.3.4.5
lib/libuser_interface_shared.so: /usr/local/lib/libopencv_core.so.3.4.5
lib/libuser_interface_shared.so: lib/CMakeFiles/user_interface_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/doudou/apriltag_car/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libuser_interface_shared.so"
	cd /home/doudou/apriltag_car/cmake-build-debug/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/user_interface_shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/user_interface_shared.dir/build: lib/libuser_interface_shared.so

.PHONY : lib/CMakeFiles/user_interface_shared.dir/build

lib/CMakeFiles/user_interface_shared.dir/clean:
	cd /home/doudou/apriltag_car/cmake-build-debug/lib && $(CMAKE_COMMAND) -P CMakeFiles/user_interface_shared.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/user_interface_shared.dir/clean

lib/CMakeFiles/user_interface_shared.dir/depend:
	cd /home/doudou/apriltag_car/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/doudou/apriltag_car /home/doudou/apriltag_car/lib /home/doudou/apriltag_car/cmake-build-debug /home/doudou/apriltag_car/cmake-build-debug/lib /home/doudou/apriltag_car/cmake-build-debug/lib/CMakeFiles/user_interface_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/user_interface_shared.dir/depend

