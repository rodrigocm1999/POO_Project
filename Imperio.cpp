//
// Created by Rodrigo on 17/11/2020.
//

#include "Imperio.h"

const std::vector<Territorio *> &Imperio::getTerritories() const {
	return territories;
}

int Imperio::getWarehouse() const {
	return warehouse;
}

void Imperio::setWarehouse(int warehouse) {
	Imperio::warehouse = warehouse;
}

int Imperio::getSafe() const {
	return safe;
}

void Imperio::setSafe(int safe) {
	Imperio::safe = safe;
}

int Imperio::getMilitaryForce() const {
	return militaryForce;
}

void Imperio::setMilitaryForce(int militaryForce) {
	Imperio::militaryForce = militaryForce;
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
	out << "Imperio --------------------- \nArmazem : " << getWarehouse() << "\tCofre : " << getSafe()
		<< "\tForca Militar : " << getMilitaryForce() << "\n";
	out << "Todos os territorios do Imperio (quantidade : " << getSize() << " ) : \n";
	for (Territorio *territory : territories) {
		out << "\t" << *territory << "\n";
	}
	out << "------------------------------ \n";
}
