#include "iostream"
#include "camera.h"
#include "tag_detect.h"
#include "id_translate.h"
#include "car_control.h"
#include "user_interface.h"
using namespace std;

/*apriltag_car*/
typedef enum {

    GET_FRAME = 1,
    DETECT_TAG,
    TRANSLATE_ID,
    CAR_CONTROL,
    USER_INTERFACE

}MainStatus;


/*init*/
bool initialize_component(){
    //init
    if (video_input_init(VIDEO_PATH))
        cout << "init camera success" << endl;
    else
        return false;
    if (tag_detect_init())
        cout << "init detect success" << endl;
    else
        return false;
    if(id_translate_init())
        cout << "init id translate success" << endl;
    else
        return false;
    if(car_control_init())
        cout << "init car control success" << endl;
    else
        return false;
    if (summary_info_init())
        cout << "init user interface success" << endl;
    else
        return false;


    return true;
}

/* main
 *  
 */
int main() {

    if(!initialize_component()) {
        cout << "initialization failed." << endl;
        return -1;
    }

    //status
    MainStatus status = GET_FRAME;

    //main loop
    while (true) {
        switch (status) {
            case(GET_FRAME):
                update_frame();
                status = DETECT_TAG;
                break;
            case (DETECT_TAG):
                imshow("test", tag_detect());
                status = TRANSLATE_ID;
                break;
            case (TRANSLATE_ID):
                renew_move_status();
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
        if(DETECT_TAG == status)
            if (cv::waitKey(5) == 'q')
                break;
    }

    //release source
    release_tdtfopt();
    return 0;
} 