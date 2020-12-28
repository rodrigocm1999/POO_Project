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
	int finalScore;
	World world;
	Kingdom kingdom;


	int calculateFinalPoints();

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

	Territorio *getTerritoryByName(const std::string &name);
	void addTerritoryToWorld(Territorio *newTerritory);
	std::vector<Territorio *> getAllTerritories() const;
	int conquer(std::string &territoryName);

	void nextPhase(std::ostream &out);

	void print(std::ostream &out) const;
	void simplePrint(std::ostream &out) const;

	void eventMaybeHappens(std::ostream &out);

	bool isGameFinished() const;
	bool isInProgress() const;
	int getFinalScore() const;
	void finishGame(std::ostream &out);
	bool start();

	bool moreProducts();
	bool moreGold();
	bool moreMilitary();
	bool acquire(const std::string &name);

	void forceConquer(Territorio * terr);

    void setKingdomGold(int amount);

    void setKingdomWarehouse(int amount);

    void abandonedResource();

    bool invaded();

    void diplomaticAlliance();

	const World &getWorld() const;

	const Kingdom &getKingdom() const;
};


#endif //TRABALHOPRATICO_GAME_H
