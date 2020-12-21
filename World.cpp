//
// Created by Rodrigo on 17/11/2020.
//

#include "World.h"

using namespace std;

const std::vector<Territorio *> &World::getTerritories() const {
	return territories;
}

void World::setTerritories(const std::vector<Territorio *> &territories) {
	World::territories = territories;
}

World::~World() {
	for (Territorio *item : territories) {
		delete item;
	}
}

void World::addTerritory(Territorio *territory) {
	territories.push_back(territory);
}

void World::lostTerritory(const Territorio *territory) {
	for (auto item = territories.begin(); item != territories.end(); ++item) {
		if (*item == territory) {
			territories.erase(item);
			return;
		}
	}
}

void World::print(ostream &out) const {
	out << "Territorios no mundo (quantidade : "
		<< territories.size() << " ) : \n";
	for (Territorio *territory : territories) {
		out << "\t" << *territory << endl;
	}
	out << "------------------------------ \n";
}

Territorio *World::getTerritoryByName(const string &name) {
	for (auto &territory : territories) {
		if (territory->getName() == name) return territory;
	}
	return nullptr;
}

World &World::operator=(const World &other) {
	std::cout << "copy world";
	territories.reserve(other.territories.size());

	for (auto &territory : other.territories) {
		territories.push_back(territory->createCopy());
	}
	return *this;
}
