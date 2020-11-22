//
// Created by Rodrigo on 22/11/2020.
//

#ifndef TRABALHOPRATICO_GAMESAVER_H
#define TRABALHOPRATICO_GAMESAVER_H

#include <vector>
#include <string>
#include "Jogo.h"

class GameSaver {

	std::vector<Jogo *> savedGames;

public:

	void saveGame(const std::string &name, Jogo *currentGame);

	bool usedSaveGameName(const std::string &gameName);
};


#endif //TRABALHOPRATICO_GAMESAVER_H
