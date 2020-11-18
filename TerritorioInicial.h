//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_TERRITORIOINICIAL_H
#define TRABALHOPRATICO_TERRITORIOINICIAL_H

#include "Territorio.h"

class TerritorioInicial : public Territorio {

public:
	std::string getType() const override { return "Inicial"; }

	TerritorioInicial() {
		this->name = "territorio_inicial";
		this->resistance = 9;
		this->goldProduction = 1;
		this->productProduction = 1;
	}
};


#endif //TRABALHOPRATICO_TERRITORIOINICIAL_H
