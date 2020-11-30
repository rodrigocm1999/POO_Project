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

int Kingdom::getGold() const {
	return safe;
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

Kingdom::~Kingdom() {
	for (Territorio *item : territories) {
		delete item;
	}
}

int Kingdom::getSize() const {
	return territories.size();
}

void Kingdom::gotConquered(Territorio *conquered) {
	territories.push_back(conquered);
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
