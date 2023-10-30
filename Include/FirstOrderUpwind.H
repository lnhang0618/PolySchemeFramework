#ifndef FirstOrderUpwind_H
#define FirstOrderUpwind_H

#include "Solvers.H"

class FirstOrderUpwind : public Solvers {
public:
protected:
    void initializeU(SchemesData& data) override;
    void iterateU(SchemesData& data) override;
};

#endif