//
// Created by doudou on 2020/11/4.
//
#ifndef _TAG_DETECT_H_
#define _TAG_DETECT_H_

//include
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <map>
#include <Eigen/Core>
#include "common_param.h"

extern "C" {
#include "apriltag.h"
#include "apriltag_pose.h"
#include "tag36h11.h"
#include "tag25h9.h"
#include "tag16h5.h"
#include "tagCircle21h7.h"
#include "tagCircle49h12.h"
#include "tagCustom48h12.h"
#include "tagStandard41h12.h"
#include "tagStandard52h13.h"
#include "common/getopt.h"
#include "common/homography.h"
}


/* cv::Mat& tag_detect(cv::Mat& frame_in);
 * describe: 标签检测
 * param: cv::Mat&, frame_in, 输入图像。
 * return: cv::Mat&, 处理后结果。
 */
cv::Mat &tag_detect(cv::Mat &frame_in);


/* bool tag_detect_init(void);
 * describe: 检测初始化
 * param: void
 * return: bool,  false 初始化失败， true 初始化成功
 */
bool tag_detect_init();


/* release_tdtfopt();
 * describe: 释放内存
 * param: void
 * return: bool
 */
bool release_tdtfopt();


/* std::map<unsigned int, Eigen::Matrix<float, 3, 3>> &get_H_map();
 * describe: 返回单应性矩阵信息
 * param: void
 * return: std::map<unsigned int, Eigen::Matrix<float, 3, 3>>&,矩阵map
 */
std::map<unsigned int, Eigen::Matrix<float, 3, 3>> &get_H_map();

void show_id_H();


/* std::map<unsigned int, Eigen::Matrix<float, 3, 3>> &get_R_map();
 * describe: 返回估算旋转矩阵信息
 * param: void
 * return: std::map<unsigned int, Eigen::Matrix<float, 3, 3>>&,矩阵map
 */
std::map<unsigned int, Eigen::Matrix<float, 3, 3>> &get_R_map();

void show_id_R();


/* std::map<unsigned int, Eigen::Matrix<float, 3, 1>> &get_t_map();
 * describe: 返回估算平移向量信息
 * param: void
 * return: std::map<unsigned int, Eigen::Matrix<float, 3, 1>>&,向量map
 */
std::map<unsigned int, Eigen::Matrix<float, 3, 1>> &get_t_map();

void show_id_t();


#endif
