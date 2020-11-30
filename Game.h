//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_GAME_H
#define TRABALHOPRATICO_GAME_H


#include "World.h"
#include "Kingdom.h"

class Game {

private:

	std::string gameName;
	int turn = -1;
	int phase = -1;
	World world;
	Kingdom kingdom;

	Territorio *getWorldTerritoryByName(const std::string &name) const;

	Territorio *getKingdomTerritoryByName(const std::string &name) const;

public:

	Game();

	explicit Game(const Game *otherGame);

	Game(std::ifstream &file, std::ostream &out);

	virtual ~Game();

	void addTerritoryToWorld(Territorio *newTerritory);

	int conquer(std::string &territoryName);

	bool isInProgress() const { return turn > 0; } // TODO change this to make sense

	const std::string &getName() const { return gameName; }

	int getTurn() const { return turn; }

	int getPhase() const { return phase; }

	const World &getWorld() const { return world; }

	const Kingdom &getKingdom() const { return kingdom; }

	void setName(const std::string &_name) { gameName = _name; }

	const Territorio *getTerritoryByName(const std::string &name) const;

	std::vector<Territorio *> getAllTerritories() const;

	void printGame(std::ostream &out) const;

	static Territorio *createTerritoryFromType(const std::string &type);
};


#endif //TRABALHOPRATICO_GAME_H
