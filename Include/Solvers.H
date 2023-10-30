#ifndef Solver_H
#define Solver_H

#include <Data.H>

class Solvers {
public:
    std::vector<TimeStepData> run_and_get_data_double(double dx,double dt, double T_end); 

    virtual ~Solvers() {}

protected:
    virtual void solveEqn(SchemesData& data);
    virtual void initializeU(SchemesData& data)=0;
    virtual void iterateU(SchemesData& data)=0;
};

#endif