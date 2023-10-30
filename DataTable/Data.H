#ifndef DATA_H
#define DATA_H

#include <vector>
#include <tuple>

struct TimeStepData {
    double T;
    double u[100];
    double u_analy[100];
};

// 主数据结构
struct SchemesData {
    int N;
    double T_end;
    double L, c, T, dx, dt;
    double u[100];
    double u_new[100];
    double u_analy[100];
    std::vector<TimeStepData> timeSteps;  // 新增：保存所有的时间步数据

    // 构造函数，设置默认值
    SchemesData() : N(100), L(1), c(1), T(0), dx(L / N), dt(0.5* c * dx) {
        // 如果需要，还可以初始化其他成员
        for(int i = 0; i < 100; i++) {
            u[i] = 0;
            u_analy[i] = 0;
        }
    }
};


#endif