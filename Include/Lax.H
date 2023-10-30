#ifndef LAX_H
#define LAX_H

#include "Solvers.H"

class Lax : public Solvers {
public:
protected:
    void initializeU(SchemesData& data) override;
    void iterateU(SchemesData& data) override;
};

#endif