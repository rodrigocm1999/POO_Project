//
// Created by cenas on 17/11/2020.
//

#include "Mina.h"

Mina::Mina() {
	static int idCounter = 0;
	this->name = "Mina" + std::to_string(++idCounter);
	this->resistance = 5;
	this->goldProduction = 1;
	//TODO regra especial prozus 2 a partir do 4 turno
}
