#include "camera.h"

using namespace std;
using namespace cv;

//static params, return to outside
static cv::Mat frame;
static cv::Mat screen_saver;
static cv::VideoCapture cap;

//static function
static bool load_screen_saver(const std::string &path);


/* static bool load_screen_saver(const std::string& path);
 * discribe: 加载保护壁纸
 * params: path, const std::string&, the path of screen_saver
 * return: bool, false 初始化失败， true 初始化成功
 */
static bool load_screen_saver(const std::string &path) {
    screen_saver = cv::imread(path, CV_LOAD_IMAGE_COLOR);
    return (!screen_saver.empty());
}


/* bool video_input_init();
 * discribe: 初始化检测视频的输入方式,默认为从摄像头采集。
 * param: void
 * return: bool, false 初始化失败， true 初始化成功
 */
bool video_input_init() {
    cap.open(0); //open camera
    if (!cap.isOpened())
        std::cerr << "Couldn't open video capture device" << std::endl;
    return cap.isOpened();
}


/* bool video_input_init(const std::string& vedio_path);
 * describe: overload, 重载为读取视频的方式。
 * param: video_path, std::string, 视频文件的路径
 * return: bool. false 初始化失败， true 初始化成功
 */
static int frame_num = 0;
static int frame_count = 0;

bool video_input_init(const std::string &video_path, const std::string &saver_path) {
    cap.open(video_path); // open video
    if (!cap.isOpened())
        std::cerr << "Couldn't open video capture device" << std::endl;
    if (load_screen_saver(saver_path))
        cv::imshow("screen saver", screen_saver);

    frame_num = int(cap.get(cv::CAP_PROP_FRAME_COUNT));
    std::cout << "Video frame num : " << frame_num << std::endl;
    return cap.isOpened();
}


/* cv::Mat& get_frame();
 * 返回一帧图片
 */
cv::Mat &get_frame() {
    return frame;
}


/* bool update_frame();
 * update frame
 */
bool update_frame(){
    if (frame_num == 0) //camera
        cap >> frame;
    else { //video
        if (frame_count < 50 - 1) {
            cap >> frame;
            frame_count++;
        } else {
            std::cerr << "It is the end of the video, return " << std::endl;
            frame = screen_saver;
        }
    }
    return true;
}