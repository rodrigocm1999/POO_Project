#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <fstream>

#include "ComanFase.h"
#include "Imperio.h"
#include "Jogo.h"

#include "Utils.h"
#include "GameSaver.h"

using namespace std;

void printMenu();

int main() {
	srand((unsigned) time(nullptr));

	ComanFase phaseCommand[] = {ComanFase("conquista", 1), ComanFase("passa", 1),
								ComanFase("maisouro", 1), ComanFase("maisprod", 1),
								ComanFase("maismilitar", 1), ComanFase("adquire", 1),
								ComanFase("lista", 1), ComanFase("avanca", 1),
								ComanFase("maismilitar", 1), ComanFase("adquire", 1),
								ComanFase("lista", 1), ComanFase("avanca", 1),
								ComanFase("grava", 1), ComanFase("ativa", 1),
								ComanFase("apaga", 1), ComanFase("toma", 1),
								ComanFase("modifica", 1), ComanFase("fevento", 1)};


	GameSaver gameSaver;
	Jogo *currentGame = new Jogo();

	bool exit = false;

	while (!exit) {

		printMenu();

		string inputString;
		getline(cin, inputString);
		vector<string> inputParts = Utils::stringSplit(inputString, " ");
		if (inputParts.empty()) {
			cout << "Comando vazio. Introduza novamente\n";
		}
		string &action = inputParts[0];

		//TODO separar o codigo melhor pelas phases tipo: pregame , ingame

		// Pre Game ----------------------------------------------------------------------------------------------------
		//Criação do jogo
		if (action == "cria") {
			//cria <tipo> <n> - Acrescenta ao mundo n territórios de um determinado tipo (exemplo:
			//mina, refugio, para respetivamente um território do tipo Mina ou do tipo Refugio).
			if (inputParts.size() == 3) {
				int amount = stoi(inputParts[2]);
				string &type = inputParts[1];

				for (int i = 0; i < amount; ++i) {
					Territorio *newTerritory = Jogo::createTerritoryFromType(type);
					currentGame->addTerritoryToWorld(newTerritory);
				}
			} else {
				cout << "sintaxe valida -> cria <tipo> <quantidade>\n";
			}
		} else if (action == "carrega") {
			if (inputParts.size() == 2) {
				string filePath = inputParts[1];
				ifstream file(filePath);
				if (!file.is_open()) {
					cout << "Couldnt open file : " << filePath << " \n";
				} else {

					Jogo *newGame = new Jogo(file,cout);
					delete currentGame;
					currentGame = newGame;
					currentGame->printGame(cout);
				}
			} else {
				cout << "sintaxe valida -> carrega <nome_ficheiro>\n";
			}
		}

			//In Game ------------------------------------------------------------------------------------------------------
			//Durante o jogo
		else if (action == "grava") {
			if (inputParts.size() == 2) {
				string &name = inputParts[1];
				if (!gameSaver.usedSaveGameName(name)) {
					gameSaver.saveGame(name, currentGame);
				} else {
					cout << "Ja existe um jogo guardado com esse nome\n";
				}
			} else {
				cout << "sintaxe valida -> grava <nome_do_jogo>\n";
			}
		} else if (action == "conquista") {
			//conquista <nome> - Dá a ordem ao império para adquirir um determinado território
			//neste turno desde que este esteja disponível no Mundo. O parâmetro nome indica
			//qual o nome do território a conquistar (planicie1, duna3, etc.).

			if (inputParts.size() == 2) {
				int whatHappened = currentGame->conquer(inputParts[1]);
				if (whatHappened == -1) {
					cout << "Nome de territorio invalido\n";
				} else if (whatHappened == false) {
					cout << "Nao consegui conquistar\n";
				} else {
					cout << "Conquistado com sucesso\n";
				}
			} else {
				cout << "sintaxe valida -> conquista <nome_do_territorio>\n";
			}

		} else if (action == "lista") {
			//lista <nome>- Obtém a informação do jogo, tanto globalmente como apenas de um
			//território específico caso o seu nome seja indicado como parâmetro.

			if (inputParts.size() == 1) {
				currentGame->printGame(cout); // Print the whole game
			} else if (inputParts.size() == 2) {
				string &name = inputParts[1];
				const Territorio *territory = currentGame->getTerritoryByName(name);
				if (territory != nullptr) {
					cout << *territory << endl;
				} else {
					cout << "Territorio com esse nome nao encontrado\n";
				}
			} else {
				cout << "sintaxe valida -> lista OU lista <nome_do_territorio>\n";
			}
		} else if (action == "sair") {
			exit = true;
			break;
		} else {
			cout << "Comando nao existe \n";
		}
	}

	return 0;
}

void printMenu() {
	//TODO make this proper
	cout << "Introduza o commando que deseja correr\n -> ";
}

