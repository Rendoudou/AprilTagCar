#include "camera.h"
#include "tag_detect.h"
#include "user_interface.h"
#include "common_param.h"

/* main
 *  
 */
int main() {

    //init
    if (video_input_init())
        std::cout << "init camera success" << std::endl;
    else
        return -1;
    if (tag_detect_init())
        std::cout << "init detect success" << std::endl;
    else
        return -1;
    if (summary_info_init())
        std::cout << "init user success" << std::endl;
    else
        return -1;

    //status
    CarStatus status = GET_FRAME;

    //main loop
    while (true) {
        switch (status) {
            case(GET_FRAME):
                update_frame();
                status = DETECT_TAG;
                break;
            case (DETECT_TAG):
                imshow("test", tag_detect(get_frame()));
                status = TRANSLATE_ID;
                break;
            case (TRANSLATE_ID):

                status = CAR_CONTROL;
                break;
            case (CAR_CONTROL):

                status = USER_INTERFACE;
                break;
            case (USER_INTERFACE):
                show_tag_info();
                status = GET_FRAME;
                break;
        }
        if (cv::waitKey(5) == 'q')
            break;
    }

    //release source
    release_tdtfopt();
    return 0;
} 