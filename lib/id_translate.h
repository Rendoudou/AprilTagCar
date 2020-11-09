//
// Created by doudou on 2020/11/5.
//
#ifndef _ID_TRANSLATE_H_
#define _ID_TRANSLATE_H_

#include <map>
#include <Eigen/Core>
#include "common_param.h"


/*小车运行状态枚举*/
typedef enum {

    STOP = 100,
    GO_STRAIGHT,        //直行
    GO_BACK,            //倒退
    TURN,               //任意角度
    TURN_RIGHT,         //右转
    TURN_LEFT,          //左转
    TURN_AROUND,        //转回头

} MoveStatus;

/*info return*/
typedef struct {
    MoveStatus move_status;
} IdTranslateInfo;


/* bool id_translate_init()
 * describe: 初始化id与运行指令的转化
 * param: void
 * return: bool,初始化是否成功
 */
bool id_translate_init();


/* IdTranslateInfo &get_id_translate_info()
 * describe: 返回本文件对外信息结构
 * param: void
 * return: IdTranslateInfo &
 */
IdTranslateInfo &get_id_translate_info();


/* MoveStatus &get_move_status()
 * describe: 返回行动状态
 * param: void
 * return: MoveStatus &
 */
MoveStatus &get_move_status();


/* bool renew_move_status();
 * describe: 更新状态
 * param: void
 * return: bool, 是否更新
 */
bool renew_move_status();


#endif//_ID_TRANSLATE_H_