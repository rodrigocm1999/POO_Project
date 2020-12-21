//
// Created by Rodrigo on 30/11/2020.
//

#ifndef TRABALHOPRATICO_GAMEINTERFACE_H
#define TRABALHOPRATICO_GAMEINTERFACE_H

#include "Game.h"
#include "GameSaver.h"
#include "PhaseCommand.h"

class GameInterface {

	GameSaver gameSaver;
	Game *currentGame;
	std::vector<PhaseCommand> phaseCommand;

	void handleCreationCommand(std::ostream &out, std::vector<std::string> &inputParts);

	void handleGameCommand(std::ostream &out, std::vector<std::string> &inputParts);

public:

	GameInterface();

	virtual ~GameInterface();

	void printMenu(std::ostream &out);

	void handleCommand(std::ostream &out, std::vector<std::string> &inputParts);

	int getCommandPhase(const std::string &command);

	void handleCommandPhase1(std::ostream &out, std::vector<std::string> &inputParts);

	void handleCommandPhase2(std::ostream &out, std::vector<std::string> &inputParts);

	void handleCommandPhase3(std::ostream &out, std::vector<std::string> &inputParts);

	void handleCommandPhase4(std::ostream &out, std::vector<std::string> &inputParts);
};


#endif //TRABALHOPRATICO_GAMEINTERFACE_H
