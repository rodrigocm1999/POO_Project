//
// Created by cenas on 17/11/2020.
//

#include "Duna.h"

int Duna::idCounter = 0;

Duna::Duna() {
	this->name = "Duna" + std::to_string(++idCounter);
	this->resistance = 4;
	this->productProduction = 1;
}

Territorio *Duna::createCopy() const {
	Duna * temp = new Duna;
	*temp = *this;
	return temp;
}
