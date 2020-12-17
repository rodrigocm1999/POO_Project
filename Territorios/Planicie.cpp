//
// Created by cenas on 17/11/2020.
//

#include "Planicie.h"
#include "../Utils.h"

int Planicie::idCounter = 0;

Planicie::Planicie() {
	this->name = "Planicie" + std::to_string(++idCounter);
	this->resistance = 5;
	this->goldProduction = 1;
	this->productProduction = 1;
}

void Planicie::updateValues(int turn, int year) {
	int value = year == 1 ? 1 : 2;
	goldProduction = value;
	productProduction = value;
}
