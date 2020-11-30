//
// Created by Rodrigo on 17/11/2020.
//

#include "Game.h"
#include "Utils.h"

#include "World.h"
#include "Kingdom.h"

#include "Territorios/Castelo.h"
#include "Territorios/Continente.h"
#include "Territorios/Duna.h"
#include "Territorios/Fortaleza.h"
#include "Territorios/Ilha.h"
#include "Territorios/Mina.h"
#include "Territorios/Montanha.h"
#include "Territorios/Pescaria.h"
#include "Territorios/Planicie.h"
#include "Territorios/Refugio.h"
#include "Territorios/Territorio.h"
#include "Territorios/TerritorioInicial.h"

#include <sstream>
#include <fstream>

using namespace std;

Game::Game() {
	kingdom.gotConquered(new TerritorioInicial);
}

Game::Game(const Game *otherGame) {

	//TODO create a full game copy

}

Game::~Game() {
	//Doesnt need to do anything because the objects are not dynamically allocated
}

vector<Territorio *> Game::getAllTerritories() const {
	vector<Territorio *> territoriesKingdom = kingdom.getTerritories();
	vector<Territorio *> territoriesWorld = world.getTerritories();

	vector<Territorio *> all;
	all.reserve(territoriesKingdom.size() + territoriesWorld.size());

	for (auto i : territoriesKingdom)
		all.push_back(i);
	for (auto i : territoriesWorld)
		all.push_back(i);
	return all;
}

const Territorio *Game::getTerritoryByName(const string &name) {
	Territorio *land = world.getTerritoryByName(name);
	return land != nullptr ? land : kingdom.getTerritoryByName(name);
}

void Game::printGame(ostream &out) const {
	out << "Turno : " << getTurn() << " \tFase : " << getPhase() << "\n";
	kingdom.print(out);
	out << "------------------------------ \n";
	world.print(out);
	//TODO adicionar tecnologias e restantes cenas
}

void Game::addTerritoryToWorld(Territorio *territory) {
	world.addTerritory(territory);
}

int Game::conquer(std::string &territoryName) {
	Territorio *toConquer = world.getTerritoryByName(territoryName);
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

Game::Game(ifstream &file, ostream &out) : Game() {

	int fileLine = 0;
	string line;
	string type;
	int amount;

	while (getline(file, line)) {
		fileLine++;
		istringstream stringStream(line);

		stringStream >> type;
		stringStream >> amount;

		for (int i = 0; i < amount; i++) {
			Territorio *terr = Game::createTerritoryFromType(type);
			if (terr != nullptr) this->addTerritoryToWorld(terr);
			else {
				out << "Ficheiro contem tipos inválidos na linha : " << fileLine << " -> " << type
					<< "\nMundo ficara imcompleto \n";
				break;
			}
		}
	}
}

Territorio *Game::createTerritoryFromType(const string &type) {
	if (type == "planicie") return new Planicie;
	if (type == "montanha") return new Montanha;
	if (type == "fortaleza") return new Fortaleza;
	if (type == "mina") return new Mina;
	if (type == "duna") return new Duna;
	if (type == "castelo") return new Castelo;
	if (type == "refugio") return new Refugio;
	if (type == "pescaria") return new Pescaria;
	return nullptr;
}

