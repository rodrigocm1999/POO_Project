//
// Created by cenas on 17/11/2020.
//

#include "Montanha.h"

int Montanha::idCounter = 0;

Montanha::Montanha() {
	this->name = "Montanha" + std::to_string(++idCounter);
	this->resistance = 9;
	this->goldProduction = 0;
	this->productProduction = 0;
	this->turnCounter = 0;
}

void Montanha::updateValues(int turn, int year) {
	//std::cout << "Montanha update values\n";
	turnCounter++;
	if (turnCounter == 2) {
		goldProduction = 1;
		productProduction = 1;
	}
}

/*Territorio &Montanha::operator=(const Territorio *other) {
	std::cout << "Montanha copia\n";
	auto *otherRightType = (Montanha *) other;
	Territorio::operator=(otherRightType);
	this->turnCounter = otherRightType->turnCounter;
	return *this;
}*/

Territorio *Montanha::createCopy() const {
	return new Montanha(*this);
}
