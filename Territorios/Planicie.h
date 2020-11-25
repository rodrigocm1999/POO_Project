//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_PLANICIE_H
#define TRABALHOPRATICO_PLANICIE_H

#include "Continente.h"

class Planicie : public Continente {

public:
    std::string getType() const override { return Continente::getType() + "_Planicie"; }

    Planicie();

};


#endif //TRABALHOPRATICO_PLANICIE_H
