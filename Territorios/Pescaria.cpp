//
// Created by cenas on 17/11/2020.
//

#include "Pescaria.h"

int Pescaria::idCounter = 0;

Pescaria::Pescaria() {
	this->name = "Pescaria" + std::to_string(++idCounter);
	this->resistance = 6;
	this->productProduction = 0;
	//TODO regra especial
}
