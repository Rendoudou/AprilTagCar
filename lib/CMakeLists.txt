#找包
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(apriltag REQUIRED)

#包含头文件
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${apriltag_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIRS})

#添加库
add_library(camera_shared SHARED camera.cpp common_param.h)
add_library(tag_detect_shared SHARED tag_detect.cpp)

#链接
target_link_libraries(tag_detect_shared ${apriltag_LIBS} ${OpenCV_LIBS})
target_link_libraries(camera_shared ${OpenCV_LIBS})