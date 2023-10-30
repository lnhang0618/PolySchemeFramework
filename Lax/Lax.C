#include "Lax.H"
#include <cmath>

// No Public methods to override

// Protected methods
// override the method in the base class

void Lax::initializeU(SchemesData& data) {
    for (int i = 0; i < data.N; i++) {
        double x = i * data.dx;
        data.u[i] = sin(2 * M_PI * x);
    }
}

void Lax::iterateU(SchemesData& data) {
    TimeStepData currentData;
    for(; data.T < data.T_end; data.T += data.dt) {
        // 更新u using Lax方法
        for (int i = 1; i < data.N - 1; i++) {
            data.u_new[i] = 0.5 * (data.u[i + 1] + data.u[i - 1]) 
                            - 0.5 * data.c * data.dt / data.dx 
                            * (data.u[i + 1] - data.u[i - 1]);
        }

        // 使用循环边界条件
        data.u_new[0] = 0.5 * (data.u[1] + data.u[data.N - 1]) 
                        - 0.5 * data.c * data.dt / data.dx 
                        * (data.u[1] - data.u[data.N - 1]);
        data.u_new[data.N - 1] = 0.5 * (data.u[0] + data.u[data.N - 2]) 
                                - 0.5 * data.c * data.dt / data.dx 
                                * (data.u[0] - data.u[data.N - 2]);

        // 更新u
        for (int i = 0; i < data.N; i++) {
            data.u[i] = data.u_new[i];
        }

        // 保存当前时间步的数据
        currentData.T = data.T;
        for (int i = 0; i < data.N; i++) {
            currentData.u[i] = data.u[i];
            currentData.u_analy[i] = sin(2 * M_PI * (i * data.dx - data.c * data.T));
        }
        data.timeSteps.push_back(currentData);
    }
}








