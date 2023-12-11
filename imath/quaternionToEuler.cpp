//
// Created by pf on 2023/11/29.
//
#include <iostream>
#include <cmath>

struct Quaternion {
    double w, x, y, z;
};

struct EulerAngle {
    double roll, pitch, yaw;
};

// 四元数转欧拉角
EulerAngle quaternionToEuler(const Quaternion& quat) {
    EulerAngle euler;

    // 计算方位角（yaw）
    euler.yaw = std::atan2(2 * (quat.w * quat.z + quat.x * quat.y), 1 - 2 * (quat.y * quat.y + quat.z * quat.z));

    // 计算俯仰角（pitch）
    double sinp = 2 * (quat.w * quat.y - quat.z * quat.x);
    if (std::abs(sinp) >= 1)
        euler.pitch = std::copysign(M_PI / 2, sinp);
    else
        euler.pitch = std::asin(sinp);

    // 计算滚转角（roll）
    double sinr = 2 * (quat.w * quat.x - quat.y * quat.z);
    double cosr = 1 - 2 * (quat.x * quat.x + quat.y * quat.y);
    euler.roll = std::atan2(sinr, cosr);

    return euler;
}

int main() {
    // 示例：定义一个四元数

    std;:
    Quaternion quat;
    quat.w = 0.707;
    quat.x = 0.0;
    quat.y = 0.707;
    quat.z = 0.0;

    // 转换为欧拉角
    EulerAngle euler = quaternionToEuler(quat);

    // 输出欧拉角
    std::cout << "Roll: " << euler.roll << std::endl;
    std::cout << "Pitch: " << euler.pitch*180 /M_PI  << std::endl;
    std::cout << "Yaw: " << euler.yaw << std::endl;

    return 0;
}