//
// Created by doudou on 2020/11/5.
//
#ifndef _CAR_CONTROL_H_
#define _CAR_CONTROL_H_

#include <iostream>
#include "id_translate.h"

/*
 * limit
 */
#define MAX_SPEED 100
#define MIN_SPEED 0
#define LIMIT_MIN_SPEED(X) ((X) < MIN_SPEED ? MIN_SPEED : (X))
#define LIMIT_MAX_SPEED(X) ((X) > MAX_SPEED ? MAX_SPEED : (X))


/*
 * ApriltagCar类
 */
class ApriltagCar {

public:

    ApriltagCar(const ApriltagCar &) = delete;

    ApriltagCar &operator=(const ApriltagCar &) = delete;

    /* static ApriltagCar& get_instance(double speed)
     * describe: get instance
     * param: speed,初始速度
     * return: void
     */
    static ApriltagCar &get_instance(double speed);

    /* ~ApriltagCar();
     * describe: deconstruct
     * param: void
     * return: void
     */
    ~ApriltagCar();

private:

    /* ApriltagCar(double speed);
     * describe: 构造函数
     * param: int speed：初始化速度
     */
    explicit ApriltagCar(double speed);

    /*private params*/
    static ApriltagCar *apriltag_car_p;
    MoveStatus move_status;
    double speed;
    double x;
    double y;
    double z;
    double angle_x;
    double angle_y;
    double angle_z;
};

/* bool car_control_init()
 * describe: 初始化car control
 * param: void
 * return: bool,初始化结果
 */
bool car_control_init();


#endif //_CAR_CONTROL_H_