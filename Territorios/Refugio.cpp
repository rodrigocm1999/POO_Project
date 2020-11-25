//
// Created by cenas on 17/11/2020.
//

#include "Refugio.h"

Refugio::Refugio() {
	static int idCounter = 0;
	this->name = "Refugio" + std::to_string(++idCounter);
	this->resistance = 9;
	this->goldProduction = 1;
}
