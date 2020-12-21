//
// Created by Rodrigo on 21/12/2020.
//

#ifndef TRABALHOPRATICO_FACTORY_H
#define TRABALHOPRATICO_FACTORY_H


#include "Technologies/Technology.h"
#include "Territorios/Territorio.h"

class Factory {
public:

	static Territorio *createTerritoryFromType(const std::string &type);
	static Technology *createTechnologyFromType(const std::string &type);
};


#endif //TRABALHOPRATICO_FACTORY_H
