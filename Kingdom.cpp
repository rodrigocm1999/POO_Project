//
// Created by Rodrigo on 17/11/2020.
//

#include "Kingdom.h"

using namespace std;

const std::vector<Territorio *> &Kingdom::getTerritories() const {
	return territories;
}

int Kingdom::getProducts() const {
	return warehouse;
}

void Kingdom::addProducts(int amount) {
	warehouse += amount;
	int limit = getProductsCapacity();
	if (warehouse > limit)
		warehouse = limit;
}

int Kingdom::getGold() const {
	return safe;
}

void Kingdom::addGold(int amount) {
	safe += amount;
	int limit = getGoldCapacity();
	if (safe > limit)
		safe = limit;
}

int Kingdom::getProductsCapacity() const {
	return 3; // TODO calculate capacity from technologies
}

int Kingdom::getGoldCapacity() const {
	return 3; // TODO calculate capacity from technologies
}

int Kingdom::getMilitaryForce() const {
	return militaryForce;
}

void Kingdom::addMilitaryForce(int amount) {
	militaryForce += amount;
	int limit = getMaxMilitaryForce();
	if (militaryForce > limit)
		militaryForce = limit;
}

int Kingdom::getMaxMilitaryForce() {
	return 3;// TODO calculate capacity from technologies
}

Kingdom::~Kingdom() {
	for (Territorio *item : territories) {
		delete item;
	}
}

int Kingdom::getSize() const {
	return territories.size();
}

void Kingdom::addTerritory(Territorio *conquered) {
	territories.push_back(conquered);
}

void Kingdom::lostTerritory(const Territorio *territory) {
	for (auto item = territories.begin(); item != territories.end(); ++item) {
		if (*item == territory) {
			territories.erase(item);
			return;
		}
	}
}

Territorio *Kingdom::getLastConquered() const {
	return territories[territories.size() - 1];
}

void Kingdom::print(std::ostream &out) const {
	out << "Kingdom --------------------- \nArmazem : " << getProducts() << " \t Capacidade : " << getProductsCapacity()
		<< "\nCofre : " << getGold() << " \t Capacidade : " << getGoldCapacity()
		<< "\nForca Militar : " << getMilitaryForce() << "\n"
		<< "Todos os territorios do Kingdom (quantidade : " << getSize() << " ) : \n";
	for (Territorio *territory : territories) {
		out << "\t" << *territory << "\n";
	}
}

Territorio *Kingdom::getTerritoryByName(const string &name) {
	for (auto &territory : territories) {
		if (territory->getName() == name) return territory;
	}
	return nullptr;
}

void Kingdom::foundAbandonedResource(int year) {
	if (year == 1) {
		addProducts(1);
	} else {
		addGold(1);
	}
}
