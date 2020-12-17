//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_KINGDOM_H
#define TRABALHOPRATICO_KINGDOM_H

#include <vector>
#include "Territorios/Territorio.h"

class Kingdom {

	std::vector<Territorio *> territories;
	int warehouse = 3;
	int safe = 3;
	int militaryForce = 0;

public:

	const std::vector<Territorio *> &getTerritories() const;

	virtual ~Kingdom();

	int getProducts() const;

	int getProductsCapacity() const;

	void addProducts(int amount);

	int getGold() const;

	int getGoldCapacity() const;

	void addGold(int amount);

	int getMilitaryForce() const;

	int getSize() const;

	void addTerritory(Territorio *conquered);

	void addMilitaryForce(int amount);

	int getMaxMilitaryForce();

	void print(std::ostream &out) const;

	Territorio *getTerritoryByName(const std::string &name);

	void lostTerritory(const Territorio *territory);

	Territorio *getLastConquered() const;

	void foundAbandonedResource(int year);

};


#endif //TRABALHOPRATICO_KINGDOM_H
