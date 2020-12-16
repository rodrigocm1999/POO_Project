//
// Created by Rodrigo on 17/11/2020.
//

#include "PhaseCommand.h"

PhaseCommand::PhaseCommand(const std::string &command, int phase) {
	this->command = command;
	this->phase = phase;
}

const std::string &PhaseCommand::getCommand() const {
	return command;
}

int PhaseCommand::getPhase() const {
	return phase;
}

PhaseCommand::PhaseCommand() {

}
