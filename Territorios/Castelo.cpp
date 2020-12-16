//
// Created by cenas on 17/11/2020.
//

#include "Castelo.h"

int Castelo::idCounter = 0;

Castelo::Castelo() {
	this->name = "Castelo" + std::to_string(++idCounter);
	this->resistance = 7;
	this->goldProduction = 1;
	this->productProduction = 3;
	//TODO special rule for this one too. produuct production 0 after 2 turns of the year
}
