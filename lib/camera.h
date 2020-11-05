#ifndef _CAMERA_H_
#define _CAMERA_H_

//include
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "common_param.h"

/* bool video_input_init();
 * 初始化检测视频的输入方式,默认为从摄像头采集。
 * param: void
 * return: bool, false 初始化失败， true 初始化成功
 */
bool video_input_init();


/* bool video_input_init(const std::string& video_path);
 * 重载为读取视频的方式,overload。
 * param: video_path, std::string, 视频文件的路径
 * return: bool. false 初始化失败， true 初始化成功
 */
bool
video_input_init(const std::string &video_path, const std::string &saver_path = SCREEN_SAVER_PATH);


/* cv::Mat& get_frame();
 * 返回一帧图片
 * param: void 
 * return: cv::Mat& 返回图片的引用
 */
cv::Mat &get_frame();


/* bool update_frame();
 * update frame
 * param: void
 * return : bool
 */
bool update_frame();


#endif 