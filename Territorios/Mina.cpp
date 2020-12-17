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
	//TODO regra especial prozus 2 a partir do 4 turno
}

void Mina::updateValues(int turn, int year) {
	goldProduction = turn <= 3 ? 1 : 2;
}
