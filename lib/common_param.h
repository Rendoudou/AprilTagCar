//
// Created by doudou on 2020/11/5.
//
#ifndef APRILTAG_TEST_COMMON_PARAM_H
#define APRILTAG_TEST_COMMON_PARAM_H

/*****init*****/
/*camera*/
#define FPS
#define SCREEN_SAVER_PATH "../source/screen_saver.jpg"
#define VIDEO_PATH        "../source/test.mp4"

/*tag_detect*/
#define FAMILY     "tag36h11" //tag family
#define TAG_SIZE   0.0465 //camera calibration
#define CAMERA_FX  3029.6
#define CAMERA_FY  3027.1
#define CAMERA_CX  1517.2
#define CAMERA_CY  2032.7

/*apriltag_car*/
typedef enum {

    GET_FRAME = 1,
    DETECT_TAG,
    TRANSLATE_ID,
    CAR_CONTROL,
    USER_INTERFACE

}CarStatus;

#endif //APRILTAG_TEST_COMMON_PARAM_H
