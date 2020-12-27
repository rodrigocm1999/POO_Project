//
// Created by Rodrigo on 17/12/2020.
//

#include "DroneMilitar.h"
#include "Technology.h"
#include "../Kingdom.h"

void DroneMilitar::makeChanges(Kingdom *kingdom) const {
	kingdom->setMilitaryForceCapacity(5);
}

Technology *DroneMilitar::createCopy() const {
	auto temp = new DroneMilitar;
	*temp = *this;
	return temp;
}
