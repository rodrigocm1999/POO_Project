//
// Created by cenas on 17/11/2020.
//

#include "Territorio.h"

std::ostream &operator<<(std::ostream &os, const Territorio &terr) {
	os << "tipo : " << terr.getType()
	   << ", nome: " << terr.name
	   << ", resistencia: " << terr.resistance
	   << ", produtos: " << terr.productProduction
	   << ", ouro: " << terr.goldProduction
	   << ", pontos: " << terr.victoryPoints;
	return os;
}
