//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_CASTELO_H
#define TRABALHOPRATICO_CASTELO_H


#include "Continente.h"

class Castelo : public Continente {

public:
    std::string getType() const override { return Continente::getType() + "_Castelo"; }

    Castelo() {
		static int idCounter = 0;
		this->name = "Castelo" + std::to_string(++idCounter);
        this->resistance = 7;
        this->goldProduction = 1;
        this->productProduction = 3;
        //TODO special rule for this one too. produuct production 0 after 2 turns of the year
    }
};


#endif //TRABALHOPRATICO_CASTELO_H
