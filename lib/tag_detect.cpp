//
// Created by doudou on 2020/11/4.
//
#include "tag_detect.h"
using namespace cv;

//static params
//init
static getopt_t *getopt_tag = nullptr;
static apriltag_family_t *tf = nullptr;
static apriltag_detector_t *td = nullptr;
static const char *family_name = nullptr;
static const char *famname = nullptr;
static apriltag_detection_info_t camera_calib_info; // parameters of the camera calibrations
//detect
static Eigen::Matrix<float, 3, 3> H_matrix;/* NOLINT */
static Eigen::Matrix<float, 3, 3> R_matrix;/* NOLINT */
static Eigen::Matrix<float, 3, 1> t_matrix;/* NOLINT */
static cv::Mat frame_copy;/* NOLINT */
static cv::Mat frame_gray;/* NOLINT */
static apriltag_pose_t tag_pose; // parameters of the tag pose R and t
static zarray_t *detections;
static apriltag_detection_t *det;
static TagDetectInfo tag_detect_info;

//static function
static bool init_tf();
static bool init_td();


/* static bool init_tf(void);
 * 初始化tf
 */
static bool init_tf() {
    getopt_add_bool(getopt_tag, 'h', "help", 0, "Show this help");
    getopt_add_bool(getopt_tag, 'd', "debug", 0, "Enable debugging output (slow)");
    getopt_add_bool(getopt_tag, 'q', "quiet", 0, "Reduce output");
    getopt_add_string(getopt_tag, 'f', "family", family_name, "Tag family to use");
    getopt_add_int(getopt_tag, 't', "threads", "1", "Use this many CPU threads");
    getopt_add_double(getopt_tag, 'x', "decimate", "2.0", "Decimate input image by this factor");
    getopt_add_double(getopt_tag, 'b', "blur", "0.0", "Apply low-pass blur to input");
    getopt_add_bool(getopt_tag, '0', "refine-edges", 1, "Spend more time trying to align edges of tags");

    famname = getopt_get_string(getopt_tag, "family");
    if (!strcmp(famname, "tag36h11")) {
        tf = tag36h11_create();
    } else if (!strcmp(famname, "tag25h9")) {
        tf = tag25h9_create();
    } else if (!strcmp(famname, "tag16h5")) {
        tf = tag16h5_create();
    } else if (!strcmp(famname, "tagCircle21h7")) {
        tf = tagCircle21h7_create();
    } else if (!strcmp(famname, "tagCircle49h12")) {
        tf = tagCircle49h12_create();
    } else if (!strcmp(famname, "tagStandard41h12")) {
        tf = tagStandard41h12_create();
    } else if (!strcmp(famname, "tagStandard52h13")) {
        tf = tagStandard52h13_create();
    } else if (!strcmp(famname, "tagCustom48h12")) {
        tf = tagCustom48h12_create();
    } else {
        std::cout << "Unrecognized tag family name. Use e.g. \"tag36h11\".\n";
        return false;
    }
    return true;
}


/* static bool init_td(void);
 * 初始化td
 */
static bool init_td() {
    apriltag_detector_add_family(td, tf);
    td->quad_decimate = getopt_get_double(getopt_tag, "decimate");
    td->quad_sigma = getopt_get_double(getopt_tag, "blur");
    td->nthreads = getopt_get_int(getopt_tag, "threads");
    td->debug = getopt_get_bool(getopt_tag, "debug");
    td->refine_edges = getopt_get_bool(getopt_tag, "refine-edges");
    return true;
}


/* bool init_tag_detect(void)
 * init tag detection
 */
bool tag_detect_init() {
    if (tf != nullptr)
        return true;

    family_name = FAMILY; //set tag family
    camera_calib_info.tagsize = TAG_SIZE;
    camera_calib_info.fx = CAMERA_FX;
    camera_calib_info.fy = CAMERA_FY;
    camera_calib_info.cx = CAMERA_CX;
    camera_calib_info.cy = CAMERA_CY;

    getopt_tag = getopt_create(); //opt operation

    if (init_tf()) {
        td = apriltag_detector_create(); //tag detector init
        init_td();
    } else
        return false;

    return true;
}


/* cv::Mat& tag_detect(cv::Mat& frame_in);
 * 标签检测
 */
cv::Mat& tag_detect(cv::Mat& frame_in) {
    frame_copy = frame_in.clone();
    cv::cvtColor(frame_copy, frame_gray, cv::COLOR_BGR2GRAY);

    // Make an image_u8_t header for the Mat data
    image_u8_t im = {.width = frame_gray.cols,
            .height = frame_gray.rows,
            .stride = frame_gray.cols,
            .buf = frame_gray.data
    };

    //检测图标，清空上次检测留下的数据
    detections = apriltag_detector_detect(td, &im);
    tag_detect_info.id_H_map.clear();
    tag_detect_info.id_R_map.clear();
    tag_detect_info.id_t_map.clear();

    // Draw detection outlines
    for (int i = 0; i < zarray_size(detections); i++) {
        zarray_get(detections, i, &det);
        line(frame_copy, Point(det->p[0][0], det->p[0][1]),
             Point(det->p[1][0], det->p[1][1]),
             Scalar(0, 0xff, 0), 2);
        line(frame_copy, Point(det->p[0][0], det->p[0][1]),
             Point(det->p[3][0], det->p[3][1]),
             Scalar(0, 0, 0xff), 2);
        line(frame_copy, Point(det->p[1][0], det->p[1][1]),
             Point(det->p[2][0], det->p[2][1]),
             Scalar(0xff, 0, 0), 2);
        line(frame_copy, Point(det->p[2][0], det->p[2][1]),
             Point(det->p[3][0], det->p[3][1]),
             Scalar(0xff, 0, 0), 2);

        std::stringstream ss;
        ss << det->id;
        String text = ss.str();
        int fontface = FONT_HERSHEY_SCRIPT_SIMPLEX;
        double fontscale = 1.0;
        int baseline;
        Size textsize = getTextSize(text, fontface, fontscale, 2,
                                    &baseline);
        putText(frame_copy, text, Point(det->c[0] - textsize.width / 2,
                                        det->c[1] + textsize.height / 2),
                fontface, fontscale, Scalar(0xff, 0x99, 0), 2);

        //save data
        for (int m = 0; m < (det->H)->nrows; m++)
            for (int n = 0; n < (det->H)->ncols; n++)
                H_matrix(m, n) = (det->H)->data[m * (det->H)->ncols + n];
        tag_detect_info.id_H_map[det->id] = H_matrix; //H

        camera_calib_info.det = det;
        estimate_pose_for_tag_homography(&camera_calib_info, &tag_pose); //estimate_pose

        for (int m = 0; m < (tag_pose.R)->nrows; m++)
            for (int n = 0; n < (tag_pose.R)->ncols; n++)
                R_matrix(m, n) = (tag_pose.R)->data[m * (tag_pose.R)->ncols + n];
        tag_detect_info.id_R_map[det->id] = R_matrix; //R

        for (int k = 0; k < 3; k++)
            t_matrix(k, 0) = (tag_pose.t)->data[k];
        tag_detect_info.id_t_map[det->id] = t_matrix; //t
    }
    apriltag_detections_destroy(detections);
    return frame_copy;
}


/* release_tdtfopt();
 * 释放内存
 */
bool release_tdtfopt() {
    apriltag_detector_destroy(td);

    if (!strcmp(famname, "tag36h11")) {
        tag36h11_destroy(tf);
    } else if (!strcmp(famname, "tag25h9")) {
        tag25h9_destroy(tf);
    } else if (!strcmp(famname, "tag16h5")) {
        tag16h5_destroy(tf);
    } else if (!strcmp(famname, "tagCircle21h7")) {
        tagCircle21h7_destroy(tf);
    } else if (!strcmp(famname, "tagCircle49h12")) {
        tagCircle49h12_destroy(tf);
    } else if (!strcmp(famname, "tagStandard41h12")) {
        tagStandard41h12_destroy(tf);
    } else if (!strcmp(famname, "tagStandard52h13")) {
        tagStandard52h13_destroy(tf);
    } else if (!strcmp(famname, "tagCustom48h12")) {
        tagCustom48h12_destroy(tf);
    }

    getopt_destroy(getopt_tag);
    std::cout << "Source release successfully." << std::endl;
    return true;
}


/* TagDetectInfo &get_tag_detect_info();
 * 返回外部需要的本文件信息
 */
TagDetectInfo &get_tag_detect_info(){
    return tag_detect_info;
}