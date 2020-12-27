//
// Created by Rodrigo on 17/12/2020.
//

#include "BancoCentral.h"
#include "../Kingdom.h"

void BancoCentral::makeChanges(Kingdom *kingdom) const {
	kingdom->setSafeCapacity(5);
	kingdom->setWarehouseCapacity(5);
}

Technology *BancoCentral::createCopy() const {
	auto temp = new BancoCentral;
	*temp = *this;
	return temp;
}
