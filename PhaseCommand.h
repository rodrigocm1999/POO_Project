//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_PHASECOMMAND_H
#define TRABALHOPRATICO_PHASECOMMAND_H


#include <string>

class PhaseCommand {
	std::string command;
	int phase;

public:
	PhaseCommand(const std::string &command, int phase);

	const std::string &getCommand() const;

	int getPhase() const;
};


#endif //TRABALHOPRATICO_PHASECOMMAND_H
