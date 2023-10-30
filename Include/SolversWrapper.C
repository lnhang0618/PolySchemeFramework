#include "SolversWrapper.H"


// Public methods

Solvers* SolversWrapper::createLaxSolver() {
    return new Lax();
}

Solvers* SolversWrapper::createLax_WendroffSolver() {
    return new Lax_Wendroff();
}

Solvers* SolversWrapper::createFirstOrderUpwindSolver() {
    return new FirstOrderUpwind();
}

void SolversWrapper::destroyLaxSolver(Solvers* solver) {
    delete solver;
    solver = nullptr;
}

void SolversWrapper::destroyLax_WendroffSolver(Solvers* solver) {
    delete solver;
    solver = nullptr;
}

void SolversWrapper::destroyFirstOrderUpwindSolver(Solvers* solver) {
    delete solver;
    solver = nullptr;
}


