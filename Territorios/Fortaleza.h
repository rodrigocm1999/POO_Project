//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_FORTALEZA_H
#define TRABALHOPRATICO_FORTALEZA_H

#include "Continente.h"

class Fortaleza : public Continente {

	static int idCounter;

public:
    std::string getType() const override { return Continente::getType() + "_Fortaleza"; }

    Fortaleza();

	Territorio *createCopy() const override;
};


#endif //TRABALHOPRATICO_FORTALEZA_H
