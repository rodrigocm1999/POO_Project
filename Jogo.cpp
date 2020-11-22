//
// Created by Rodrigo on 17/11/2020.
//

#include "Jogo.h"
#include "Utils.h"
#include "TerritorioInicial.h"

using namespace std;

Jogo::Jogo() {
	kingdom.gotConquered(new TerritorioInicial);
}

Jogo::Jogo(const Jogo *otherGame) {

	//TODO create a full game copy

}

vector<Territorio *> Jogo::getAllTerritories() const {
	vector<Territorio *> all;
	vector<Territorio *> territoriesKingdom = kingdom.getTerritories();
	vector<Territorio *> territoriesWorld = world.getTerritories();

	all.reserve(territoriesKingdom.size() + territoriesWorld.size());
	for (int i = 0; i < territoriesKingdom.size(); ++i) {
		all.push_back(territoriesKingdom[i]);
	}
	for (int i = 0; i < territoriesWorld.size(); ++i) {
		all.push_back(territoriesWorld[i]);
	}
	return all;
}

const Territorio *Jogo::getTerritoryByName(const string &name) const {
	Territorio *land = getWorldTerritoryByName(name);
	return land != nullptr ? land : getKingdomTerritoryByName(name);
}

Territorio *Jogo::getWorldTerritoryByName(const string &name) const {
	vector<Territorio *> territoriesWorld = world.getTerritories();
	for (auto &territory : territoriesWorld) {
		if (territory->getName() == name) return territory;
	}
	return nullptr;
}

Territorio *Jogo::getKingdomTerritoryByName(const string &name) const {
	vector<Territorio *> territoriesKingdom = kingdom.getTerritories();
	for (auto &territory : territoriesKingdom) {
		if (territory->getName() == name) return territory;
	}
	return nullptr;
}

void Jogo::printGame(ostream &out) const {

	out << "Turno : " << getTurn() << " \tFase : " << getPhase() << "\n";

	kingdom.print(out);
	world.print(out);
	//TODO adicionar tecnologias e restantes cenas
}

void Jogo::addTerritoryToWorld(Territorio *territory) {
	world.addTerritory(territory);
}

int Jogo::conquer(std::string &territoryName) {
	Territorio *toConquer = getWorldTerritoryByName(territoryName);
	if (toConquer == nullptr) return -1;
	if (toConquer->isIsland()) { // check if has requirements to conquer island
		//TODO if has technology required "Misseis Teleguiados"
		if (kingdom.getSize() < 5) {
			return false;
		}
	}

	int random = Utils::getRandom(1, 6);
	int conqueringPower = kingdom.getMilitaryForce() + random;

	if (conqueringPower > toConquer->getResistance()) {
		world.gotConquered(toConquer);
		kingdom.gotConquered(toConquer);
		return true;
	}

	return false;
}

