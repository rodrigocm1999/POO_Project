//
// Created by Rodrigo on 17/11/2020.
//

#include "Game.h"
#include "Utils.h"

#include "World.h"
#include "Kingdom.h"
#include "Factory.h"

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
#include "Factory.h"
#include "Constants.h"

#define GAME_NOT_STARTED 1
#define GAME_IN_PROGRESS 2
#define GAME_FINISHED 3

using namespace std;

Game::Game() {
	gameState = GAME_NOT_STARTED;
	turn = 1;
	phase = 1;
	finalScore = 0;
	kingdom.addTerritory(new TerritorioInicial);
}

Game::Game(const Game &otherGame) {

	this->turn = otherGame.turn;
	this->phase = otherGame.phase;
	this->gameState = otherGame.gameState;
	this->finalScore = otherGame.finalScore;

	this->world = otherGame.world;
	this->kingdom = otherGame.kingdom;
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

Territorio *Game::getTerritoryByName(const string &name) {
	Territorio *land = world.getTerritoryByName(name);
	return land != nullptr ? land : kingdom.getTerritoryByName(name);
}

void Game::print(ostream &out) const {
	out << "Turno : " << getTurn() << " \tFase : " << getPhase() << "\n";
	kingdom.print(out);
	out << "Mundo ------------------------ \n";
	world.print(out);
	out << "------------------------------ \n";
}

void Game::simplePrint(ostream &out) const {
	out << "Turno : " << getTurn() << " \tFase : " << getPhase() << "\n";
	kingdom.simplePrint(out);
	out << "\tQuantidade de territorios : " << kingdom.getSize()
		<< "\n\tQuantidade de tecnologias : " << kingdom.getTechnologies().size()
		<< "\nQuantidade de territorios no Mundo: " << world.getSize() << " \n";
}

void Game::addTerritoryToWorld(Territorio *territory) {
	world.addTerritory(territory);
}

int Game::conquer(std::string &territoryName) {
	Territorio *toConquer = world.getTerritoryByName(territoryName);
	if (toConquer == nullptr) return -1;
	if (toConquer->isIsland()) { // check if has requirements to conquer island
		if (kingdom.getSize() < 5 || !kingdom.hasTechnology(TEC_MISSEIS)) {
			return false;
		}
	}

	int random = Utils::getRandom(1, 6);
	int conqueringPower = kingdom.getMilitaryForce() + random;

	if (conqueringPower > toConquer->getResistance()) {
		world.lostTerritory(toConquer);
		kingdom.addTerritory(toConquer);
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
			Territorio *terr = Factory::createTerritoryFromType(type);
			if (terr != nullptr) this->addTerritoryToWorld(terr);
			else {
				out << "Ficheiro contem tipos inválidos na linha : " << fileLine << " -> " << type
					<< "\nMundo ficara imcompleto \n";
				break;
			}
		}
	}
}

bool Game::start() {
	if (world.getSize() == 0) {
		return false;
	}
	gameState = GAME_IN_PROGRESS;
	turn = 1;
	phase = 1;
	return true;
}

void Game::nextPhase(ostream &out) {
	phase++;
	if (phase == 1) {
		// Conquista e passa
	} else if (phase == 2) {
		kingdom.updateTerritories(getTurn(), getYear());
		// fazer troca de produtos ou ouro
	} else if (phase == 3) {
		// comprar militar e tecnologias
	} else if (phase == 4) {
		eventMaybeHappens(out);
		turn++;
		phase = 1;

		if (turn > 12) {
			finishGame(out);
		}
	}
}

void Game::eventMaybeHappens(ostream &out) {
	int eventType = Utils::getRandom(1, 4);
	if (eventType == 1) {
		abandonedResource();
		out << "Encontraste um recurso abandonado, ganhaste alguns recursos\n";
	} else if (eventType == 2) {
		Territorio *invadedTerr = kingdom.getLastConquered();
		if (invaded()) {
			out << "Perdeste o teu ultimo territorio conquistado:\n\t" << *invadedTerr << "\n";
			if (kingdom.getSize() == 0) {
				finishGame(out);
			}
		} else {
			out << "Tiveste sorte! nao perdeste o teu terrritorio conquistado mais recentemente\n";
		}
	} else if (eventType == 3) {
		if (diplomaticAlliance()) {
			out << "houve uma alianaa diplomatica, ganhaste mais 1 forca militar\n";
		}
	} else {
		out << "houve uma alianaa diplomatica, mas ja atingiste o maximo de forca militar\n";
	}
}

void Game::abandonedResource() {
	kingdom.foundAbandonedResource(getYear());
}

bool Game::invaded() {
	int luckStrength = Utils::getRandom(1, 6);
	int baseInvasionStrength = getYear() == 1 ? 2 : 3;
	int invasionStrength = baseInvasionStrength + luckStrength;

	bool hasBonus = kingdom.hasTechnology(TEC_DEFESAS);
	int bonusResistance = hasBonus ? 1 : 0;

	Territorio *terr = kingdom.getLastConquered();
	int territoryResistance = terr->getResistance() + bonusResistance;

	if (invasionStrength > territoryResistance) {
		kingdom.lostTerritory(terr);
		world.addTerritory(terr);
		return true;
	}
	return false;
}

bool Game::diplomaticAlliance() {
	return kingdom.addMilitaryForce(1);
}

bool Game::isInProgress() const {
	return gameState == GAME_IN_PROGRESS;
}

bool Game::isGameFinished() const {
	return gameState == GAME_FINISHED;
}

void Game::finishGame(ostream &out) {
	gameState = GAME_FINISHED;
	phase = -1;

	calculateFinalPoints();
	if (kingdom.getSize()) {
		out << "Perdeste o jogo. Ficaste com " << getFinalScore() << " pontos\n";
	} else {
		out << "Acabaste o jogo e ficaste com " << getFinalScore() << " pontos\n";
	}
}

bool Game::moreProducts() {
	if (kingdom.getGold() >= 2) {
		kingdom.addGold(-2);
		kingdom.addProducts(1);
		return true;
	}
	return false;
}

bool Game::moreGold() {
	if (kingdom.getProducts() >= 2) {
		kingdom.addProducts(-2);
		kingdom.addGold(1);
		return true;
	}
	return false;
}

bool Game::moreMilitary() {
	if (kingdom.getProducts() >= 1 && kingdom.getGold() >= 1) {
		kingdom.addProducts(-1);
		kingdom.addGold(-1);
		kingdom.addMilitaryForce(1);
		return true;
	}
	return false;
}

int Game::acquire(const string &name) {
    if (kingdom.hasTechnology(name)){
        return -1;
    }
    Technology *technology = Factory::createTechnologyFromType(name);
    if (technology == nullptr){
        return false;
    }
    if (technology->getCost() <= kingdom.getGold()){
        kingdom.addTechnology(technology);
        kingdom.addGold(-(technology->getCost()));
        technology->makeChanges(&kingdom);
        return true;
    } else{
        delete technology;
        return -2;
    }
}

int Game::calculateFinalPoints() {
	finalScore = kingdom.getFinalPoints(world);
	return finalScore;
}

void Game::forceConquer(Territorio *terr) {
	world.lostTerritory(terr);
	kingdom.addTerritory(terr);
}

void Game::setKingdomGold(int amount) {
	//only for command midifica - if n more than capacity should set capacity too ?!
	kingdom.setSafeAmount(amount);
}

void Game::setKingdomWarehouse(int amount) {
	//only for command midifica - if n more than capacity should set capacity too ?!
	kingdom.setWarehouseAmount(amount);
}

int Game::getFinalScore() const {
	return finalScore;
}

const World &Game::getWorld() const {
	return world;
}

const Kingdom &Game::getKingdom() const {
	return kingdom;
}

void Game::forceAcquire(Technology *technology) {
    kingdom.addTechnology(technology);
}


