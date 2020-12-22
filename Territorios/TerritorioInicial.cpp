//
// Created by cenas on 17/11/2020.
//

#include "TerritorioInicial.h"

TerritorioInicial::TerritorioInicial() {
	this->name = "TerritorioInicial";
	this->resistance = 9;
	this->goldProduction = 1;
	this->productProduction = 1;
}

Territorio *TerritorioInicial::createCopy() const {
	TerritorioInicial * temp = new TerritorioInicial;
	*temp = *this;
	return temp;
}
