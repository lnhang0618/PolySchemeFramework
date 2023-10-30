#ifndef SOLVERSWRAPPER_H
#define SOLVERSWRAPPER_H

#include "Solvers.H"
#include "Lax.H"
#include "Lax-Wendroff.H"
#include "FirstOrderUpwind.H"

class SolversWrapper {
public:
    Solvers* createLaxSolver();

    Solvers* createLax_WendroffSolver();

    Solvers* createFirstOrderUpwindSolver();

    void destroyLaxSolver(Solvers* solver);

    void destroyLax_WendroffSolver(Solvers* solver);

    void destroyFirstOrderUpwindSolver(Solvers* solver);
};

#endif
