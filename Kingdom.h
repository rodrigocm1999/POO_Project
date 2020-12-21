//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_KINGDOM_H
#define TRABALHOPRATICO_KINGDOM_H

#include <vector>
#include "Territorios/Territorio.h"
#include "Technologies/Technology.h"
#include "World.h"


class Kingdom {

	std::vector<Territorio *> territories;
	std::vector<Technology *> technologies;
	int warehouseAmount = 0;
	int warehouseCapacity = 3;
	int safeAmount = 0;
	int safeCapacity = 3;
	int militaryForce = 0;
	int militaryForceCapacity = 3;
	bool canMakeTrades = false;

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

	void addMilitaryForce(int amount);

	int getMaxMilitaryForce();

	int getSize() const;

	void addTerritory(Territorio *conquered);

	void print(std::ostream &out) const;

	Territorio *getTerritoryByName(const std::string &name);

	void lostTerritory(const Territorio *territory);

	Territorio *getLastConquered() const;

	void foundAbandonedResource(int year);

	bool hasTechnology(const std::string &name) const;

	void setWarehouseCapacity(int warehouseCapacity);

	void setSafeCapacity(int safeCapacity);

	void setMilitaryForceCapacity(int militaryForceCapacity);

	Kingdom &operator=(const Kingdom &other);

	int getFinalPoints(World &world);
};


#endif //TRABALHOPRATICO_KINGDOM_H
