//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_GAME_H
#define TRABALHOPRATICO_GAME_H

#include "World.h"
#include "Kingdom.h"
#include "Utils.h"

class Game {

private:

	std::string gameName;
	int turn;
	int phase;
	int gameState;
	World world;
	Kingdom kingdom;

	void abandonedResource();
	void invaded();
	void diplomaticAlliance();

public:

	Game();

	explicit Game(const Game &otherGame);

	Game(std::ifstream &file, std::ostream &out);

	virtual ~Game();

	void addTerritoryToWorld(Territorio *newTerritory);

	int conquer(std::string &territoryName);

	bool isInProgress() const;

	const std::string &getName() const { return gameName; }

	int getTurn() const { return turn; }

	int getPhase() const { return phase; }

	void setName(const std::string &name) { gameName = name; }

	const Territorio *getTerritoryByName(const std::string &name);

	std::vector<Territorio *> getAllTerritories() const;

	void nextPhase();

	bool gameIsFinished() const { return turn > 12; }

	int getYear() const { return Utils::turnToYear(turn); }

	void printGame(std::ostream &out) const;

	int eventMaybeHappens();

	static Territorio *createTerritoryFromType(const std::string &type);

	void finishGame();

	bool isGameFinished();

	bool start();
};


#endif //TRABALHOPRATICO_GAME_H
