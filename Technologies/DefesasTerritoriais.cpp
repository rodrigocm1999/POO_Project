//
// Created by Rodrigo on 17/12/2020.
//

#include "DefesasTerritoriais.h"

Technology *DefesasTerritoriais::createCopy() const {
	auto temp = new DefesasTerritoriais;
	*temp = *this;
	return temp;
}
