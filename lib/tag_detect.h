//
// Created by doudou on 2020/11/4.
//
#ifndef _TAG_DETECT_H_
#define _TAG_DETECT_H_

//include
#include <iostream>
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


/*info return*/
typedef struct {
    std::map<unsigned int, Eigen::Matrix<float, 3, 3>> id_H_map;
    std::map<unsigned int, Eigen::Matrix<float, 3, 3>> id_R_map;
    std::map<unsigned int, Eigen::Matrix<float, 3, 1>> id_t_map;
    std::vector<int> ids;
} TagDetectInfo;


/* bool tag_detect_init(void);
 * describe: 检测初始化
 * param: void
 * return: bool,  false 初始化失败， true 初始化成功
 */
bool tag_detect_init();


/* TagDetectInfo &get_tag_detect_info();
 * describe: 返回外部需要的本文件信息
 * param: void
 * return: TagDetectInfo &,本文件部分信息
 */
TagDetectInfo &get_tag_detect_info();



/* cv::Mat& tag_detect();
 * describe: 标签检测
 * param: void 内部设置图像源。
 * return: cv::Mat&, 处理后结果。
 */
cv::Mat &tag_detect();


/* release_tdtfopt();
 * describe: 释放内存
 * param: void
 * return: bool
 */
bool release_tdtfopt();


#endif
