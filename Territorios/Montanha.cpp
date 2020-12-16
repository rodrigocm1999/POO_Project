//
// Created by cenas on 17/11/2020.
//

#include "Montanha.h"

int Montanha::idCounter = 0;

Montanha::Montanha() {
	this->name = "Montanha" + std::to_string(++idCounter);
	this->resistance = 9;
	this->goldProduction = 1;
	this->productProduction = 1;
}
