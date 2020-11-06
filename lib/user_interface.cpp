//
// Created by doudou on 2020/11/5.
//
#include "user_interface.h"
using namespace std;

//static param
static const TagDetectInfo *tag_detect_p = nullptr;
static const CameraInfo *camera_p = nullptr;

//static func
static bool show_id_H(const TagDetectInfo &info);
static bool show_id_R(const TagDetectInfo &info);
static bool show_id_t(const TagDetectInfo &info);


/* bool summary_info_init();
 * 信息汇总
 */
bool summary_info_init(){
    tag_detect_p = &get_tag_detect_info();
    camera_p = &get_camera_info();
    return true;
}


/* void show_tag_info();
 * 展示汇总
 */
void show_tag_info() {
    if(nullptr != tag_detect_p){
        show_id_t(*tag_detect_p);
    }
    printf("Fps is %.2lf.\n\n",camera_p->fps);
}


/* static bool show_id_H(TagDetectInfo &info)
 * 显示id单应性矩阵
 */
static bool show_id_H(const TagDetectInfo &info) {
    auto pm = info.id_H_map.begin();/* NOLINT */
    if (!info.id_H_map.empty()) {
        for (; pm != info.id_H_map.end(); pm++) {
            std::cout << "Tag id " << pm->first << +" Homography matrix:" << std::endl;
            std::cout << pm->second << std::endl;
        }
    } else
        std::cout << "Id_H_map is empty!" << std::endl;

    std::cout << std::endl;
    return true;
}


/* static bool show_id_R(TagDetectInfo &info)
 * 显示id旋转矩阵
 */
static bool show_id_R(const TagDetectInfo &info) {
    auto pm = info.id_R_map.begin();/* NOLINT */
    if (!info.id_R_map.empty()) {
        for (; pm != info.id_R_map.end(); pm++) {
            std::cout << "Tag id " << pm->first << +" Rotation matrix:" << std::endl;
            std::cout << pm->second << std::endl;
        }
    } else
        std::cout << "Id_R_map is empty!" << std::endl;

    std::cout << std::endl;
    return true;
}


/* static bool show_id_t(TagDetectInfo &info)
 * 显示id平移信息
 */
static bool show_id_t(const TagDetectInfo &info) {
    auto pm = info.id_t_map.begin();/* NOLINT */
    if (!info.id_t_map.empty()) {
        for (; pm != info.id_t_map.end(); pm++) {
            std::cout << "Tag id " << pm->first << +" t vector: ";
            std::cout << (pm->second).transpose() << " length: " << (pm->second).norm() << std::endl;
        }
    } else
        std::cout << "Id_t_map is empty!" << std::endl;

    std::cout << std::endl;
    return true;
}