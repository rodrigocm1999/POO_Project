//
// Created by Rodrigo on 17/11/2020.
//

#include "Kingdom.h"

using namespace std;

const std::vector<Territorio *> &Kingdom::getTerritories() const {
	return territories;
}

const std::vector<Technology *> &Kingdom::getTechnologies() const {
	return technologies;
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

bool Kingdom::addMilitaryForce(int amount) {
	militaryForce += amount;
	int limit = getMaxMilitaryForce();
	if (militaryForce > limit) {
		militaryForce = limit;
		return false;
	}
	if (militaryForce < 0) {
		militaryForce = 0;
		return false;
	}
	return true;
}

int Kingdom::getMaxMilitaryForce() const {
	return militaryForceCapacity;
}

Kingdom::~Kingdom() {
	for (Territorio *item : territories) {
		delete item;
	}
	for (Technology *item : technologies) {
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
	simplePrint(out);
	out << "Todos os territorios do Kingdom (quantidade : " << territories.size() << " ) : \n";
	for (Territorio *item : territories) {
		out << "\t" << *item << "\n";
	}
	out << "Tecnologias ------------------ \n";
	for (Technology *item : technologies) {
		out << "\t" << *item << "\n";
	}
}

void Kingdom::simplePrint(ostream &out) const {
	out << "Imperio --------------------- \n\tArmazem : " << getProducts() << " \t Capacidade : "
		<< getProductsCapacity()
		<< "\n\tCofre : " << getGold() << " \t Capacidade : " << getGoldCapacity()
		<< "\n\tForca Militar : " << getMilitaryForce() << "\t Capacidade : " << getMaxMilitaryForce() << "\n";
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
	for (Technology *tec : technologies) {
		if (tec->getName() == name) {
			return true;
		}
	}
	return false;
}

void Kingdom::setWarehouseCapacity(int _warehouseCapacity) {
	this->warehouseCapacity = _warehouseCapacity;
}

void Kingdom::setSafeCapacity(int _safeCapacity) {
	this->safeCapacity = _safeCapacity;
}

void Kingdom::setMilitaryForceCapacity(int _militaryForceCapacity) {
	this->militaryForceCapacity = _militaryForceCapacity;
}

Kingdom &Kingdom::operator=(const Kingdom &other) {

	this->territories.reserve(other.territories.size());
	for (Territorio *territory : other.territories) {
		this->territories.push_back(territory->createCopy());
	}

	this->technologies.reserve(other.technologies.size());
	for (Technology *technology : other.technologies) {
		this->technologies.push_back(technology->createCopy());
	}

	this->warehouseAmount = other.warehouseAmount;
	this->warehouseCapacity = other.warehouseCapacity;
	this->safeAmount = other.safeAmount;
	this->safeCapacity = other.safeCapacity;
	this->militaryForce = other.militaryForce;
	this->militaryForceCapacity = other.militaryForceCapacity;

	return *this;
}

int Kingdom::getFinalPoints(World &world) {
	int points = 0;
	for (auto &terr : territories) {
		points += terr->getVictoryPoints();
	}
	points += technologies.size();
	if (technologies.size() == 5) {
		//Bonus Cientifico
		points += 1;
	}
	if (world.getSize() == 0) {
		//Imperador Supremo
		points += 3;
	}
	return points;
}

void Kingdom::updateTerritories(int turn, int year) {
	for (Territorio *terr: territories) {
		terr->updateValues(turn, year);
		addProducts(terr->getProductProduction());
		addGold(terr->getGoldProduction());
	}
}

void Kingdom::setWarehouseAmount(int warehouseAmount) {
	Kingdom::warehouseAmount = warehouseAmount;
}

void Kingdom::setSafeAmount(int safeAmount) {
	Kingdom::safeAmount = safeAmount;
}

void Kingdom::addTechnology(Technology *technology) {
	technologies.push_back(technology);
}
