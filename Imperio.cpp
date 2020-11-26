//
// Created by Rodrigo on 17/11/2020.
//

#include "Imperio.h"

const std::vector<Territorio *> &Imperio::getTerritories() const {
	return territories;
}

int Imperio::getProducts() const {
	return warehouse;
}

int Imperio::getGold() const {
	return safe;
}

int Imperio::getProductsCapacity() const {
	return 3; // TODO calculate capacity from technologies
}

int Imperio::getGoldCapacity() const {
	return 3; // TODO calculate capacity from technologies
}

int Imperio::getMilitaryForce() const {
	return militaryForce;
}

Imperio::~Imperio() {
	for (Territorio *item : territories) {
		delete item;
	}
}

int Imperio::getSize() const {
	return territories.size();
}

void Imperio::gotConquered(Territorio *conquered) {
	territories.push_back(conquered);
}

void Imperio::print(std::ostream &out) const {
	out << "Imperio --------------------- \nArmazem : " << getProducts() << " \t Capacidade : " << getProductsCapacity()
		<< "\nCofre : " << getGold() << " \t Capacidade : " << getGoldCapacity()
		<< "\nForca Militar : " << getMilitaryForce() << "\n"
		<< "Todos os territorios do Imperio (quantidade : " << getSize() << " ) : \n";
	for (Territorio *territory : territories) {
		out << "\t" << *territory << "\n";
	}
}