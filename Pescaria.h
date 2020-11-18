//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_PESCARIA_H
#define TRABALHOPRATICO_PESCARIA_H

#include "Ilha.h"

class Pescaria : public Ilha{

public:
    std::string getType() const override { return Ilha::getType() + "_Pescaria"; }

    Pescaria() {
		static int idCounter = 0;
    	this->name = "Pescaria" + std::to_string(++idCounter);
        this->resistance = 6;
        this->productProduction = 0;
        //TODO regra especial
    }
};


#endif //TRABALHOPRATICO_PESCARIA_H
