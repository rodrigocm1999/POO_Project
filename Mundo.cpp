//
// Created by Rodrigo on 17/11/2020.
//

#include "Mundo.h"

using namespace std;

const std::vector<Territorio *> &Mundo::getTerritories() const {
	return territories;
}

void Mundo::setTerritories(const std::vector<Territorio *> &territories) {
	Mundo::territories = territories;
}

Mundo::~Mundo() {
	for (Territorio *item : territories) {
		delete item;
	}
}

void Mundo::addTerritory(Territorio *territory) {
	territories.push_back(territory);
}

void Mundo::gotConquered(const Territorio *territory) {
	for (vector<Territorio *>::iterator item = territories.begin(); item != territories.end(); ++item) {
		if (*item == territory) {
			territories.erase(item);
			return;
		}
	}
}

void Mundo::print(ostream &out) const {
	out << "------------------------------ \nTerritorios no mundo (quantidade : "
		<< territories.size() << " ) : \n";
	for (Territorio *territory : territories) {
		out << "\t" << *territory << endl;
	}
	out << "------------------------------ \n";
}

