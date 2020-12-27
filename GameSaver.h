//
// Created by Rodrigo on 22/11/2020.
//

#ifndef TRABALHOPRATICO_GAMESAVER_H
#define TRABALHOPRATICO_GAMESAVER_H

#include <vector>
#include <string>
#include "Game.h"

class GameSaver {

	std::vector<Game *> savedGames;

public:

	virtual ~GameSaver();

	void saveGame(const std::string &name, Game *currentGame);

	bool usedSaveGameName(const std::string &gameName) const;

    Game * getSavedGameByName(const std::string &gameName) const;

    void deleteGame(const std::string &gameName);

    void printAll(std::ostream &out) const;
};


#endif //TRABALHOPRATICO_GAMESAVER_H
