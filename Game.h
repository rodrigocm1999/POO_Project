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
	int finalScore;

	void abandonedResource();

	void invaded();

	void diplomaticAlliance();

public:

	Game();

	Game(const Game &otherGame);

	Game(std::ifstream &file, std::ostream &out);

	virtual ~Game();

	const std::string &getName() const { return gameName; }
	int getTurn() const { return turn; }
	int getPhase() const { return phase; }
	int getYear() const { return Utils::turnToYear(turn); }
	void setName(const std::string &name) { gameName = name; }

	const Territorio *getTerritoryByName(const std::string &name);
	void addTerritoryToWorld(Territorio *newTerritory);
	std::vector<Territorio *> getAllTerritories() const;
	int conquer(std::string &territoryName);

	void nextPhase();

	void printGame(std::ostream &out) const;

	int eventMaybeHappens();

	bool isGameFinished() const;
	bool isInProgress() const;
	void finishGame();
	bool start();

	bool moreProducts();
	bool moreGold();
	bool moreMilitary();
	bool acquire(const std::string &name);

	int calculateFinalPoints();

	bool forceConquer(const std::string &name);
};


#endif //TRABALHOPRATICO_GAME_H
