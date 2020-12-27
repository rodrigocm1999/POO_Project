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

Game *GameSaver::getSavedGameByName(const std::string &gameName) const {
	for (Game *game :savedGames) {
		if (game->getName() == gameName) {
			return game;
		}
	}
	return nullptr;
}

void GameSaver::deleteGame(const string &gameName) {
	for (int i = 0; i < savedGames.size(); i++) {
		Game *game = savedGames[i];
		if (game->getName() == gameName) {
			savedGames.erase(savedGames.begin() + i);
			delete game;
			return;
		}
	}
}

void GameSaver::printAll(ostream &out) const {
	for (auto game : savedGames) {
		out << "\n\nGame name : " << game->getName() << "\n";
		game->simplePrint(out);
	}
}
