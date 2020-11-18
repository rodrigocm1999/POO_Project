//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_FORTALEZA_H
#define TRABALHOPRATICO_FORTALEZA_H

#include "Continente.h"

class Fortaleza : public Continente {

public:
    std::string getType() const override { return Continente::getType() + "_Fortaleza"; }

    Fortaleza() {
		static int idCounter = 0;
		this->name = "Fortaleza" + std::to_string(++idCounter);
        this->resistance = 8;
    }
};


#endif //TRABALHOPRATICO_FORTALEZA_H
