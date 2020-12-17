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

//TODO O que acontece se um territorio for conquistado e depois perder e voltar a conquistar?
void Montanha::updateValues(int turn, int year) {
	turnCounter++;
	if (turnCounter == 2) {
		goldProduction = 1;
		productProduction = 1;
	}
}
