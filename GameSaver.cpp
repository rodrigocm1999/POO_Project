//
// Created by Rodrigo on 22/11/2020.
//

#include "GameSaver.h"

using namespace std;

void GameSaver::saveGame(const string &name, Jogo *currentGame) {
	Jogo *gameCopy = new Jogo(currentGame);
	gameCopy->setName(name);
	savedGames.push_back(gameCopy);
}

bool GameSaver::usedSaveGameName(const string &gameName) {
	for (Jogo *game : savedGames)
		if (game->getName() == gameName)
			return true;
	return false;
}