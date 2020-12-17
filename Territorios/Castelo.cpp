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
}

void Castelo::updateValues(int turn, int year) {
	productProduction = turn <= 2 ? 3 : 0;
}
