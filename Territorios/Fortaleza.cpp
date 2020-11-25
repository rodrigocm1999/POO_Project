//
// Created by cenas on 17/11/2020.
//

#include "Fortaleza.h"

Fortaleza::Fortaleza() {
	static int idCounter = 0;
	this->name = "Fortaleza" + std::to_string(++idCounter);
	this->resistance = 8;
}
