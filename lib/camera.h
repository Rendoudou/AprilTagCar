//
// Created by doudou on 2020/11/4.
//
#ifndef _CAMERA_H_
#define _CAMERA_H_

//include
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <ctime>
#include "common_param.h"


/*info return*/
typedef struct {
    double fps;
    cv::Mat frame;
} CameraInfo;


/* bool video_input_init();
 * describe: 初始化检测视频的输入方式,默认为从摄像头采集。
 * param: void
 * return: bool, false 初始化失败， true 初始化成功
 */
bool video_input_init();


/* bool video_input_init(const std::string& video_path);
 * describe: 重载为读取视频的方式,overload。
 * param: video_path, std::string, 视频文件的路径
 * return: bool. false 初始化失败， true 初始化成功
 */
bool video_input_init(const std::string &video_path, const std::string &saver_path = SCREEN_SAVER_PATH);


/* CameraInfo &get_camera_info();
 * describe: 返回外部需要的本文件信息
 * param: void
 * return: CameraInfo &,本文件部分信息
 */
CameraInfo &get_camera_info();


/* cv::Mat& get_frame();
 * describe: 返回一帧图片
 * param: void
 * return: cv::Mat &,返回一帧需要处理的图片
 */
cv::Mat &get_frame();


/* bool update_frame();
 * describe: update frame
 * param: void
 * return: bool,更新一帧图片是否成功
 */
bool update_frame();


#endif 