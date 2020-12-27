//
// Created by cenas on 17/11/2020.
//

#include "Fortaleza.h"

int Fortaleza::idCounter = 0;

Fortaleza::Fortaleza() {
	this->name = "Fortaleza" + std::to_string(++idCounter);
	this->resistance = 8;
}

Territorio *Fortaleza::createCopy() const {
	auto * temp = new Fortaleza;
	*temp = *this;
	return temp;
}
