//
// Created by Rodrigo on 30/11/2020.
//

#include "GameInterface.h"

#include <ostream>
#include <fstream>

using namespace std;

GameInterface::GameInterface() {
	currentGame = new Game();

	phaseCommand = new PhaseCommand[]
			{PhaseCommand("conquista", 1), PhaseCommand("passa", 1),
			 PhaseCommand("maisouro", 1), PhaseCommand("maisprod", 2),
			 PhaseCommand("maismilitar", 1), PhaseCommand("adquire", 3),
			 PhaseCommand("lista", 1), PhaseCommand("avanca", 1),
			 PhaseCommand("maismilitar", 1), PhaseCommand("adquire", 1),
			 PhaseCommand("lista", 1), PhaseCommand("avanca", 1),
			 PhaseCommand("grava", 1), PhaseCommand("ativa", 1),
			 PhaseCommand("apaga", 1), PhaseCommand("toma", 1),
			 PhaseCommand("modifica", 1), PhaseCommand("fevento", -1)};

}

void GameInterface::printMenu(ostream &out) {
	//TODO make this proper
	out << "\nIntroduza o commando que deseja correr\n ->";
}

void GameInterface::handleCommand(ostream &out, vector<std::string> &inputParts) {

	if (inputParts.empty()) {
		out << "Comando vazio. Introduza novamente\n";
		return;
	}
	const string &action = inputParts[0];

	if (action == "lista") {
		//lista <nome>- Obtém a informação do jogo, tanto globalmente como apenas de um
		//território específico caso o seu nome seja indicado como parâmetro.

		if (inputParts.size() == 1) {
			currentGame->printGame(cout); // Print the whole game
		} else if (inputParts.size() == 2) {
			string &name = inputParts[1];
			const Territorio *territory = currentGame->getTerritoryByName(name);
			if (territory != nullptr) {
				out << *territory << endl;
			} else {
				out << "Territory com esse nome nao encontrado\n";
			}
		} else {
			out << "sintaxe valida -> lista OU lista <nome_do_territorio>\n";
		}
		return;
	}

	//if (!currentGame->isInProgress()) {
	handleCreationCommand(out, inputParts);
	//} else {
	handleGameCommand(out, inputParts);
	//}
}

void GameInterface::handleCreationCommand(ostream &out, vector<std::string> &inputParts) {
	// Pre Game ----------------------------------------------------------------------------------------------------
	//Criação do jogo
	const string &action = inputParts[0];

	if (action == "cria") {
		//cria <tipo> <n> - Acrescenta ao mundo n territórios de um determinado tipo (exemplo:
		//mina, refugio, para respetivamente um território do tipo Mina ou do tipo Refugio).
		if (inputParts.size() == 3) {
			int amount = stoi(inputParts[2]);
			string &type = inputParts[1];

			for (int i = 0; i < amount; ++i) {
				Territorio *newTerritory = Game::createTerritoryFromType(type);
				if (newTerritory != nullptr) currentGame->addTerritoryToWorld(newTerritory);
				else {
					out << "tipo de territorio invalido : " << type << endl;
					break;
				}
			}
			out << type << " criado(a) na fase de criacao\n";
		} else {
			out << "sintaxe valida -> cria <tipo> <quantidade>\n";
		}
	} else if (action == "carrega") {
		if (inputParts.size() == 2) {
			string filePath = inputParts[1];
			ifstream file(filePath);
			if (!file.is_open()) {
				out << "Nao foi possivel abrir o ficheiro : " << filePath << " \n";
			} else {
				Game *newGame = new Game(file, cout);
				delete currentGame;
				currentGame = newGame;
				currentGame->printGame(cout);
				out << "Carregado o ficheiro com sucesso\n";
			}
		} else {
			out << "Sintaxe valida -> carrega <nome_ficheiro>\n";
		}
	} else {
		out << "Comando invalido para a criacao do jogo\n";
	}
}

void GameInterface::handleGameCommand(ostream &out, vector<std::string> &inputParts) {
	// if game is running
	//In Game ------------------------------------------------------------------------------------------------------
	//Durante o jogo
	const string &action = inputParts[0];

	if (action == "grava") {
		if (inputParts.size() == 2) {
			const string &name = inputParts[1];
			if (!gameSaver.usedSaveGameName(name)) {
				gameSaver.saveGame(name, currentGame);
			} else {
				out << "Ja existe um jogo guardado com esse nome\n";
			}
		} else {
			out << "sintaxe valida -> grava <nome_do_jogo>\n";
		}
	} else if (action == "conquista") {
		//conquista <nome> - Dá a ordem ao império para adquirir um determinado território
		//neste turno desde que este esteja disponível no World. O parâmetro nome indica
		//qual o nome do território a conquistar (planicie1, duna3, etc.).

		if (inputParts.size() == 2) {
			int whatHappened = currentGame->conquer(inputParts[1]);
			if (whatHappened == -1) {
				out << "Nome de territorio invalido\n";
			} else if (whatHappened == false) {
				out << "Nao consegui conquistar\n";
			} else {
				out << "Conquistado com sucesso\n";
			}
		} else {
			out << "Sintaxe valida -> conquista <nome_do_territorio>\n";
		}
	} else {
		out << "Comando invalido para durante o jogo\n";
	}
}

GameInterface::~GameInterface(){
	delete [] phaseCommand;
	delete currentGame;
}
