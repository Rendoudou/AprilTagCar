#设置最小cmake版本
cmake_minimum_required(VERSION 3.1)

#编译器要求
add_compile_options(-std=c++11)

#DEBUG
set(CMAKE_BUILD_TYPE DEBUG)

#项目名称
project(apriltag_test)

#package
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(apriltag REQUIRED)

#子目录
add_subdirectory(lib)

#包含头文件
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${apriltag_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIRS})
include_directories(lib)

#MY Lib
set( My_LIBS
  camera_shared
  tag_detect_shared
)

#找到apriltag
message(STATUS "apriltag_include dirs:${apriltag_INCLUDE_DIRS}")
message(STATUS "apriltag_dir:${apriltag_DIR}")
message(STATUS "apriltag_libs:${apriltag_LIBS}")

#可执行文件
add_executable(apriltag_detect_demo opencv_demo.cpp)
add_executable(test_lib test_lib.cpp)

#链接
target_link_libraries(apriltag_detect_demo ${apriltag_LIBS} ${OpenCV_LIBS})
target_link_libraries(test_lib ${OpenCV_LIBS} ${My_LIBS})

