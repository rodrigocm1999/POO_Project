//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_PHASECOMMAND_H
#define TRABALHOPRATICO_PHASECOMMAND_H


#include <string>

class PhaseCommand {

public:
    std::string command;
    int phase;

    PhaseCommand(const std::string command, int phase);
};


#endif //TRABALHOPRATICO_PHASECOMMAND_H
