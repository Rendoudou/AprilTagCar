//
// Created by doudou on 2020/11/5.
//
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
class ApriltagCar{

public:
    /* ApriltagCar(int speed);
     * describe: 构造函数
     * param: int speed：初始化速度
     */
    ApriltagCar(double speed);

private:
    MoveStatus move_status;
    double speed;
    double x;
    double y;
    double z;
    double angle_x;
    double angle_y;
    double angle_z;
};