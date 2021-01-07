//
// Created by Rodrigo on 17/12/2020.
//

#include "DefesasTerritoriais.h"

Technology *DefesasTerritoriais::createCopy() const {
	return new DefesasTerritoriais(*this);
}
