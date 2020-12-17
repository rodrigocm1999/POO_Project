//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_WORLD_H
#define TRABALHOPRATICO_WORLD_H


#include <vector>
#include "Territorios/Territorio.h"

class World {

	std::vector<Territorio *> territories;

public:

	virtual ~World();

	const std::vector<Territorio *> &getTerritories() const;

	void setTerritories(const std::vector<Territorio *> &territories);

	void addTerritory(Territorio *territory);

	void lostTerritory(const Territorio *territory);

	int getSize() const { return territories.size(); }

	void print(std::ostream &out) const;

	Territorio *getTerritoryByName(const std::string &name);

};


#endif //TRABALHOPRATICO_WORLD_H
