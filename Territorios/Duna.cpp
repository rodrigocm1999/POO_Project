//
// Created by cenas on 17/11/2020.
//

#include "Duna.h"

Duna::Duna() {
	static int idCounter = 0;
	this->name = "Duna" + std::to_string(++idCounter);
	this->resistance = 4;
	this->productProduction = 1;
}
