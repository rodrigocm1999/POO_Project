//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_PLANICIE_H
#define TRABALHOPRATICO_PLANICIE_H

#include "Continente.h"

class Planicie : public Continente {

public:
    std::string getType() const override { return Continente::getType() + "_Planicie"; }

    Planicie() {
    	static int idCounter = 0;
		this->name = "Planicie" + std::to_string(++idCounter);
        this->resistance = 5;
        this->goldProduction = 1;
        // TODO regras especiais. 2º anos produz 2 de ouro
    }

};


#endif //TRABALHOPRATICO_PLANICIE_H
