//
// Created by cenas on 17/11/2020.
//

#include "Refugio.h"

int Refugio::idCounter = 0;

Refugio::Refugio() {
	this->name = "Refugio" + std::to_string(++idCounter);
	this->resistance = 9;
	this->goldProduction = 1;
}

Territorio *Refugio::createCopy() const {
	auto * temp = new Refugio;
	*temp = *this;
	return temp;
}
