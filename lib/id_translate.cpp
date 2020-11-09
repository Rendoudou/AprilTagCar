//
// Created by doudou on 2020/11/5.
//
#include "id_translate.h"
#include "tag_detect.h"
using namespace std;

/*
 * static params
 */
static const map<unsigned int, Eigen::Matrix<float, 3, 1>> *id_t_map_p;
static IdTranslateInfo id_translate_info;
/*id与位置对应的 hash map*/
static map<int, int> id_pos_map ={

};
/*id与动作对应的 hash map*/
static map<int, MoveStatus> id_move_map = { /* NOLINT */
        {16, STOP},
        {17, GO_STRAIGHT},
        {18, GO_BACK},
        {19, TURN},
        {20, TURN_AROUND}
};


/* bool id_translate_init()
 * 初始化
 */
bool id_translate_init() {
    id_translate_info.move_status = STOP;
    id_t_map_p = &(get_tag_detect_info().id_t_map);
    return true;
}


/* IdTranslateInfo &get_id_translate_info()
 * 返回本文间对外信息结构
 */
IdTranslateInfo &get_id_translate_info(){
    return id_translate_info;
}


/* MoveStatus &get_move_status()
 * 返回行动状态
 */
MoveStatus &get_move_status() {
    return id_translate_info.move_status;
}


/* bool renew_move_status()
 * 更新状态
 */
bool renew_move_status() {
    if (id_t_map_p->empty()) //没有检测到标签
        return false;
    else {
        for(const auto & p : *id_t_map_p){
            if((p.second).norm() < TAG_CONFIRM_DISTANCE_LIMIT){ //标签距离限制
                auto temp = id_move_map.find(p.first);
                if(temp != id_move_map.end()) {
                    if(id_translate_info.move_status != temp->second) {
                        id_translate_info.move_status = temp->second;
                        return true;
                    }
                    else
                        return false;
                }
            }
        }
    }
    return false;
}

