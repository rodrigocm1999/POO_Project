//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_TERRITORIO_H
#define TRABALHOPRATICO_TERRITORIO_H


#include <string>
#include <ostream>
#include <iostream>

class Territorio {

protected:

	std::string name;
	int resistance = 0;
	int productProduction = 0;
	int goldProduction = 0;
	int victoryPoints = 0;

public:

	Territorio() = default;

	virtual bool isContinent() const { return false; }

	virtual bool isIsland() const { return false; }

	virtual std::string getType() const { return ""; }

	const std::string &getName() const { return name; }

	int getResistance() const { return resistance; }

	int getProductProduction() const { return productProduction; }

	int getGoldProduction() const { return goldProduction; }

	int getVictoryPoints() const { return victoryPoints; }

	friend std::ostream &operator<<(std::ostream &os, const Territorio &terr);

};

//std::ostream &operator<<(std::ostream &os, const Territorio &territory);


#endif //TRABALHOPRATICO_TERRITORIO_H
