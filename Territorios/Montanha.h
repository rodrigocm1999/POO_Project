//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_MONTANHA_H
#define TRABALHOPRATICO_MONTANHA_H

#include "Continente.h"

class Montanha : public Continente {

public:
    std::string getType() const override { return Continente::getType() + "_Montanha"; }

    Montanha();
};


#endif //TRABALHOPRATICO_MONTANHA_H
