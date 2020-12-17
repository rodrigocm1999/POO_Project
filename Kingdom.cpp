//
// Created by Rodrigo on 17/11/2020.
//

#include "Kingdom.h"

#define TEC_DRONE "DroneMilitar"
#define TEC_MISSEIS "MisseisTeleguiados"
#define TEC_DEFESAS "DefesasTerritoriais"
#define TEC_BANCO "BancoCentral"
#define TEC_BOLSA "BolsaValores"

using namespace std;

const std::vector<Territorio *> &Kingdom::getTerritories() const {
	return territories;
}

int Kingdom::getProducts() const {
	return warehouseAmount;
}

void Kingdom::addProducts(int amount) {
	warehouseAmount += amount;
	int limit = getProductsCapacity();
	if (warehouseAmount > limit)
		warehouseAmount = limit;
}

int Kingdom::getProductsCapacity() const {
	return warehouseCapacity;
}

int Kingdom::getGold() const {
	return safeAmount;
}

void Kingdom::addGold(int amount) {
	safeAmount += amount;
	int limit = getGoldCapacity();
	if (safeAmount > limit)
		safeAmount = limit;
}

int Kingdom::getGoldCapacity() const {
	return safeCapacity;
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
	return militaryForceCapacity;
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

bool Kingdom::hasTechnology(const string &name) const {
	for (auto tec : technologies) {
		if (tec->getName() == name) {
			return true;
		}
	}
	return false;
}

void Kingdom::setWarehouseCapacity(int warehouseCapacity) {
	Kingdom::warehouseCapacity = warehouseCapacity;
}

void Kingdom::setSafeCapacity(int safeCapacity) {
	Kingdom::safeCapacity = safeCapacity;
}

void Kingdom::setMilitaryForceCapacity(int militaryForceCapacity) {
	Kingdom::militaryForceCapacity = militaryForceCapacity;
}
