//
// Created by doudou on 2020/11/5.
//
#include "car_control.h"

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
}