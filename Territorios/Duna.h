//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_DUNA_H
#define TRABALHOPRATICO_DUNA_H

#include "Continente.h"

class Duna : public Continente {

	static int idCounter;

public:
    std::string getType() const override { return Continente::getType() + "_Duna"; }

    Duna();

	Territorio *createCopy() const override;
};


#endif //TRABALHOPRATICO_DUNA_H
