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
include lib/CMakeFiles/id_translate_shared.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/id_translate_shared.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/id_translate_shared.dir/flags.make

lib/CMakeFiles/id_translate_shared.dir/id_translate.cpp.o: lib/CMakeFiles/id_translate_shared.dir/flags.make
lib/CMakeFiles/id_translate_shared.dir/id_translate.cpp.o: ../lib/id_translate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/doudou/apriltag_car/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/id_translate_shared.dir/id_translate.cpp.o"
	cd /home/doudou/apriltag_car/cmake-build-debug/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/id_translate_shared.dir/id_translate.cpp.o -c /home/doudou/apriltag_car/lib/id_translate.cpp

lib/CMakeFiles/id_translate_shared.dir/id_translate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/id_translate_shared.dir/id_translate.cpp.i"
	cd /home/doudou/apriltag_car/cmake-build-debug/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/doudou/apriltag_car/lib/id_translate.cpp > CMakeFiles/id_translate_shared.dir/id_translate.cpp.i

lib/CMakeFiles/id_translate_shared.dir/id_translate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/id_translate_shared.dir/id_translate.cpp.s"
	cd /home/doudou/apriltag_car/cmake-build-debug/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/doudou/apriltag_car/lib/id_translate.cpp -o CMakeFiles/id_translate_shared.dir/id_translate.cpp.s

# Object files for target id_translate_shared
id_translate_shared_OBJECTS = \
"CMakeFiles/id_translate_shared.dir/id_translate.cpp.o"

# External object files for target id_translate_shared
id_translate_shared_EXTERNAL_OBJECTS =

lib/libid_translate_shared.so: lib/CMakeFiles/id_translate_shared.dir/id_translate.cpp.o
lib/libid_translate_shared.so: lib/CMakeFiles/id_translate_shared.dir/build.make
lib/libid_translate_shared.so: lib/CMakeFiles/id_translate_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/doudou/apriltag_car/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libid_translate_shared.so"
	cd /home/doudou/apriltag_car/cmake-build-debug/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/id_translate_shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/id_translate_shared.dir/build: lib/libid_translate_shared.so

.PHONY : lib/CMakeFiles/id_translate_shared.dir/build

lib/CMakeFiles/id_translate_shared.dir/clean:
	cd /home/doudou/apriltag_car/cmake-build-debug/lib && $(CMAKE_COMMAND) -P CMakeFiles/id_translate_shared.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/id_translate_shared.dir/clean

lib/CMakeFiles/id_translate_shared.dir/depend:
	cd /home/doudou/apriltag_car/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/doudou/apriltag_car /home/doudou/apriltag_car/lib /home/doudou/apriltag_car/cmake-build-debug /home/doudou/apriltag_car/cmake-build-debug/lib /home/doudou/apriltag_car/cmake-build-debug/lib/CMakeFiles/id_translate_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/id_translate_shared.dir/depend

