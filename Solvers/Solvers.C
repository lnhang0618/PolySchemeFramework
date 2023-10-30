#include "Solvers.H"


// Public methods

std::vector<TimeStepData> Solvers::run_and_get_data_double(double dx,double dt, double T_end) {
    SchemesData data;
    data.dx = dx;
    data.dt = dt;
    data.T_end = T_end;
    this->solveEqn(data);

    return data.timeSteps;
}

// Protected methods

void Solvers::solveEqn(SchemesData& data) {
    this->initializeU(data);
    this->iterateU(data);
}

void Solvers::initializeU(SchemesData& data) {
   // virtual function
   // any derived class can override this function
}

void Solvers::iterateU(SchemesData& data) {
   // virtual function
   // any derived class can override this function
}