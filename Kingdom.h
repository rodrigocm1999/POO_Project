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

	int getGold() const;

	int getGoldCapacity() const;

	int getMilitaryForce() const;

	int getSize() const;

	void gotConquered(Territorio *conquered);

	void print(std::ostream &out) const;

	Territorio *getTerritoryByName(const std::string &name) ;
};


#endif //TRABALHOPRATICO_KINGDOM_H
