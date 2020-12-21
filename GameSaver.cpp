//
// Created by Rodrigo on 22/11/2020.
//

#include "GameSaver.h"

using namespace std;

void GameSaver::saveGame(const string &name, Game *currentGame) {
	Game *gameCopy = new Game(*currentGame);
	gameCopy->setName(name);
	savedGames.push_back(gameCopy);
}

bool GameSaver::usedSaveGameName(const string &gameName) const {
	for (Game *game : savedGames)
		if (game->getName() == gameName)
			return true;
	return false;
}

GameSaver::~GameSaver() {
	for (Game *game : savedGames)
		delete game;
}
