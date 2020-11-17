#include <iostream>
#include <sstream>
#include <string>

#include "Castelo.h"
#include "Continente.h"
#include "ComandoFase.h"
#include "Duna.h"
#include "Fortaleza.h"
#include "Ilha.h"
#include "Imperio.h"
#include "Jogo.h"
#include "Mina.h"
#include "Montanha.h"
#include "Mundo.h"
#include "Pescaria.h"
#include "Planicie.h"
#include "Refugio.h"
#include "Territorio.h"
#include "TerritorioInicial.h"
#include "Utils.h"

using namespace std;

void saveGame(string name, Jogo *currentGame, vector<Jogo *> &otherGames);

bool usedSaveGameName(string gameName, vector<Jogo *> &otherGames);

int main() {

    vector<Jogo *> savedGames;
    Jogo *currentGame = new Jogo();

    vector<Territorio *> createdTerrains;

    while (true) {

        string inputString;
        getline(cin, inputString);
        vector<string> inputParts = Utils::stringSplit(inputString, " ");
        if (inputParts.empty()) {
            cout << "Comando inválido. Introduza novamente\n";
        }
        string &action = inputParts[0];

//Criação do jogo
        if (action == "cria") {
            //cria <tipo> <n> - Acrescenta ao mundo n territórios de um determinado tipo (exemplo:
            //mina, refugio, para respetivamente um território do tipo Mina ou do tipo Refugio).
            if (inputParts.size() != 3) {

            } else {
                cout << "sintaxe válida -> cria <tipo> <quantidade>\n";
            }
        } else if (action == "carrega") {
            //TODO carrega os territorios a partir de um ficheiro
        }

//Durante o jogo
        if (action == "grava") {
            if (inputParts.size() != 2) {
                string name = inputParts[1];
                if (!usedSaveGameName(name, savedGames)) {
                    saveGame(name, currentGame, savedGames);
                } else {
                    cout << "Ja existe um jogo guardado com esse nome\n";
                }
            } else {
                cout << "sintaxe válida -> grava <nome_do_jogo>\n";
            }
        } else if (action == "conquista") {

        } else if (action == "lista") {

        } else if (action == "sair") {
            break;
        }

    }

    return 0;
}

}

void saveGame(string name, Jogo *currentGame, vector<Jogo *> &otherGames) {
    Jogo *gameCopy = new Jogo(currentGame);
    otherGames.push_back(gameCopy);
}

bool usedSaveGameName(string gameName, vector<Jogo *> &otherGames) {
    for (int i = 0; i < otherGames.size(); ++i) {
        if (otherGames[i].getName() == gameName) {
            return true;
        }
    }
    return false;
}



