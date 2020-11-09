//
// Created by doudou on 2020/11/5.
//
#include "car_control.h"
using namespace std;

/*static params*/
static const ApriltagCar *apriltag_car_p = nullptr;


/* static ApriltagCar& get_instance(double speed)
 * describe: get instance
 */
ApriltagCar& ApriltagCar::get_instance(double speed) {
    static ApriltagCar instance(speed);
    return instance;
}


/* ~ApriltagCar()
 * describe: 析构函数
 */
ApriltagCar::~ApriltagCar(){
    cout << "ApriltagCar instance deconstruct called." << endl;
}


/* ApriltagCar(int speed);
 * describe: 构造函数
 */
ApriltagCar::ApriltagCar(double speed) {
    this->speed = LIMIT_MIN_SPEED(speed);
    this->speed = LIMIT_MAX_SPEED(speed);
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->angle_x = 0;
    this->angle_y = 0;
    this->angle_z = 0;
    this->move_status = STOP;
    cout << "ApriltagCar instance construct called." << endl;
}


/* bool car_control_init()
 * describe: 初始化car control
 */
bool car_control_init(){
    apriltag_car_p = &ApriltagCar::get_instance(BASIC_SPEED);
    return true;
}