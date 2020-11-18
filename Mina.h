//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_MINA_H
#define TRABALHOPRATICO_MINA_H

#include "Continente.h"

class Mina : public Continente {

public:
    std::string getType() const override { return Continente::getType() + "_Mina"; }

    Mina() {
		static int idCounter = 0;
		this->name = "Mina" + std::to_string(++idCounter);
        this->resistance = 5;
        this->goldProduction = 1;
        //TODO regra especial prozus 2 a partir do 4 turno
    }
};

#endif //TRABALHOPRATICO_MINA_H
