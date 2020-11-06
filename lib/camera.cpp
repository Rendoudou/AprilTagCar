//
// Created by doudou on 2020/11/4.
//
#include "camera.h"
using namespace std;
using namespace cv;

//static params, return to outside
static cv::Mat frame;/* NOLINT */
static cv::Mat screen_saver;/* NOLINT */
static cv::VideoCapture cap;/* NOLINT */
static CameraInfo camera_info;

//static function
static bool load_screen_saver(const std::string &path);


/* static bool load_screen_saver(const std::string& path);
 * describe: 加载保护壁纸
 */
static bool load_screen_saver(const std::string &path) {
    screen_saver = cv::imread(path, CV_LOAD_IMAGE_COLOR);
    return (!screen_saver.empty());
}


/* bool video_input_init();
 * describe: 初始化检测视频的输入方式,默认为从摄像头采集。
 */
bool video_input_init() {
    cap.open(0); //open camera
    if (!cap.isOpened())
        std::cerr << "Couldn't open video capture device" << std::endl;
    return cap.isOpened();
}


/* bool video_input_init(const std::string& vedio_path);
 * describe: overload, 重载为读取视频的方式。
 */
static int frame_num = 0;
static int frame_count = 0;
bool video_input_init(const std::string &video_path, const std::string &saver_path) {
    cap.open(video_path); // open video
    if (!cap.isOpened())
        std::cerr << "Couldn't open video capture device" << std::endl;
    if (load_screen_saver(saver_path))
        //cv::imshow("screen saver", screen_saver);
        std::cout << "Load screen saver pig successfully." << std::endl;
    frame_num = int(cap.get(cv::CAP_PROP_FRAME_COUNT));
    std::cout << "Video frame num : " << frame_num << std::endl;
    return cap.isOpened();
}


/* cv::Mat& get_frame();
 * describe: 返回一帧图片
 */
cv::Mat &get_frame() {
    return frame;
}


/* bool update_frame();
 * describe: update frame
 */
static bool load_saver_flag = true;
static clock_t t_start, t_end;
static bool time_record_flag = true;
bool update_frame(){
    if(time_record_flag){
        t_start = clock();
        time_record_flag = false;
    }
    else{
        t_end = clock();
        camera_info.fps = 1.0 / ((double)(t_end - t_start)/CLOCKS_PER_SEC);
        time_record_flag = true;
    }

    if (frame_num == 0) //camera
        cap >> frame;
    else { //video
        if (frame_count < frame_num - 1) {
            cap >> frame;
            frame_count++;
        } else {
            //std::cerr << "It is the end of the video, return " << std::endl;
            if(load_saver_flag){
                frame = screen_saver.clone();
                load_saver_flag = false;
            }
        }
    }
    return true;
}


/* CameraInfo &get_camera_info();
 * 返回外部需要的本文件信息
 */
CameraInfo &get_camera_info(){
    return camera_info;
}