//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_IMPERIO_H
#define TRABALHOPRATICO_IMPERIO_H

#include <vector>
#include "Territorios/Territorio.h"

class Imperio {

    std::vector<Territorio *> territories;
    int warehouse = 3;
    int safe = 3;
    int militaryForce = 0;

public:

    const std::vector<Territorio *> &getTerritories() const;

    virtual ~Imperio();

    int getWarehouse() const;

    void setWarehouse(int warehouse);

    int getSafe() const;

    void setSafe(int safe);

    int getMilitaryForce() const;

    void setMilitaryForce(int militaryForce);

    int getSize() const;

    void gotConquered(Territorio *conquered);

    void print(std::ostream &out) const;
};


#endif //TRABALHOPRATICO_IMPERIO_H
