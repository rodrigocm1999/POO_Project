//
// Created by cenas on 17/11/2020.
//

#include "Montanha.h"

Montanha::Montanha() {
	static int idCounter = 0;
	this->name = "Montanha" + std::to_string(++idCounter);
	this->resistance = 9;
	this->goldProduction = 1;
	this->productProduction = 1;
}
