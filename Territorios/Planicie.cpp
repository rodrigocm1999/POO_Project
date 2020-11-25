//
// Created by cenas on 17/11/2020.
//

#include "Planicie.h"

Planicie::Planicie() {
	static int idCounter = 0;
	this->name = "Planicie" + std::to_string(++idCounter);
	this->resistance = 5;
	this->goldProduction = 1;
	// TODO regras especiais. 2º anos produz 2 de ouro
}
