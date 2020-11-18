//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_DUNA_H
#define TRABALHOPRATICO_DUNA_H

#include "Continente.h"

class Duna : public Continente {

public:
    std::string getType() const override { return Continente::getType() + "_Duna"; }

    Duna() {
		static int idCounter = 0;
		this->name = "Duna" + std::to_string(++idCounter);
        this->resistance = 4;
        this->productProduction = 1;
    }


};


#endif //TRABALHOPRATICO_DUNA_H
