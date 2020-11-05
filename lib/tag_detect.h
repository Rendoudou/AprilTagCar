#ifndef _TAG_DETECT_H_
#define _TAG_DETECT_H_

//include
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <map>
#include <Eigen/Core>

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
 * 标签检测
 * param: cv::Mat&, frame_in, 输入图像。
 * return: cv::Mat&, 处理后结果。
 */
cv::Mat &tag_detect(cv::Mat &frame_in);


/* bool tag_detect_init(void);
 * 检测初始化
 * param: void
 * return: bool,  false 初始化失败， true 初始化成功
 */
bool tag_detect_init();


/* release_tdtfopt(void);
 * 释放内存
 * param: void
 * return: void
 */
bool release_tdtfopt();


/* show_id_H(void);
 * 单应性矩阵
 * param: void
 * return: void
 */
void show_id_H();


/* show_id_t(void);
 * 平移矩阵
 * param: void
 * return: void
 */
void show_id_t();


/* show_id_R(void);
 * 旋转矩阵
 * param: void
 * return: void
 */
void show_id_R();


#endif


