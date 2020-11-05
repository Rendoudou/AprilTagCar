//
// Created by doudou on 2020/11/5.
//

#ifndef APRILTAG_TEST_COMMON_PARAM_H

#define APRILTAG_TEST_COMMON_PARAM_H

#define SCREEN_SAVER_PATH "../source/screen_saver.jpg"
#define VIDEO_PATH  "../source/video.mp4"

typedef enum {

    GET_FRAME = 1,
    DETECT_TAG,
    TRANSLATE_ID,
    CAR_CONTROL,
    USER_INTERFACE

}CarStatus;

#endif //APRILTAG_TEST_COMMON_PARAM_H
