//
// Created by cenas on 17/11/2020.
//

#include "Territorio.h"

std::ostream &operator<<(std::ostream &os, const Territorio &terr) {
	os << "tipo : " << terr.getType()
	   << ", nome: " << terr.name
	   << ", resistencia: " << terr.resistance
	   << ", produtos: " << terr.productProduction
	   << ", ouro: " << terr.goldProduction
	   << ", pontos: " << terr.victoryPoints;
	return os;
}

void Territorio::updateValues(int turn, int year) {
	//std::cout << "Territorio update values\n";
}

/*Territorio &Territorio::operator=(const Territorio *other) {
	std::cout << "copy territory\n";
	this->name = other->name;
	this->resistance = other->resistance;
	this->productProduction = other->productProduction;
	this->goldProduction = other->goldProduction;
	this->victoryPoints = other->victoryPoints;
	return *this;
}
*/
