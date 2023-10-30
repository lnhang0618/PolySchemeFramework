#ifndef LAX_WENDROFF_H
#define LAX_WENDROFF_H

#include "Solvers.H"

class Lax_Wendroff : public Solvers {
public:
protected:
    void initializeU(SchemesData& data) override;
    void iterateU(SchemesData& data) override;
};

#endif