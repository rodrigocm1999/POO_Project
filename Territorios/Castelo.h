//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_CASTELO_H
#define TRABALHOPRATICO_CASTELO_H


#include "Continente.h"

class Castelo : public Continente {

	static int idCounter;

public:
    std::string getType() const override { return Continente::getType() + "_Castelo"; }

    Castelo();
};


#endif //TRABALHOPRATICO_CASTELO_H
