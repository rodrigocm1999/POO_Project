//
// Created by Rodrigo on 17/12/2020.
//

#include "Technology.h"

#include "../Kingdom.h"

Technology::Technology(const std::string &name,int cost) : name(name),cost(cost) {}

void Technology::makeChanges(Kingdom *kingdom) const {}

Technology *Technology::createCopy() const {
	std::cout << "create copy technology";
	return nullptr;
}
