//
// Created by Rodrigo on 17/12/2020.
//

#include "BolsaValores.h"

Technology *BolsaValores::createCopy() const {
	return new BolsaValores(*this);
}
