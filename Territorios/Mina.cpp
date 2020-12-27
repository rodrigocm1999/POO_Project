//
// Created by cenas on 17/11/2020.
//

#include "Mina.h"
#include "../Utils.h"

int Mina::idCounter = 0;

Mina::Mina() {
	this->name = "Mina" + std::to_string(++idCounter);
	this->resistance = 5;
	this->goldProduction = 1;
}

void Mina::updateValues(int turn, int year) {
	goldProduction = turn <= 3 ? 1 : 2;
}

Territorio *Mina::createCopy() const {
	auto *temp = new Mina;
	*temp = *this;
	return temp;
}
