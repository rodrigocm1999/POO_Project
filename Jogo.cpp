//
// Created by Rodrigo on 17/11/2020.
//

#include "Jogo.h"

const std::string &Jogo::getName() const {
    return name;
}

int Jogo::getTurn() const {
    return turn;
}

int Jogo::getPhase() const {
    return phase;
}

const Mundo &Jogo::getWorld() const {
    return world;
}

const Imperio &Jogo::getKingdom() const {
    return kingdom;
}

void Jogo::setName(const std::string &name) {
    Jogo::name = name;
}

Jogo::Jogo() {


}

Jogo::Jogo(const Jogo *otherGame) {

    //TODO create a full game copy

}
