//
// Created by Rodrigo on 30/11/2020.
//

#include "GameInterface.h"
#include "Factory.h"

#include <ostream>
#include <fstream>

using namespace std;

GameInterface::GameInterface() {
	currentGame = new Game();

	phaseCommand =
			{PhaseCommand("conquista", 1), PhaseCommand("passa", 1),
			 PhaseCommand("maisouro", 2), PhaseCommand("maisprod", 2),
			 PhaseCommand("maismilitar", 3), PhaseCommand("adquire", 3),
			 PhaseCommand("lista", 0), PhaseCommand("avanca", 0),
			 PhaseCommand("grava", 0), PhaseCommand("ativa", 0),
			 PhaseCommand("apaga", 0), PhaseCommand("toma", 0),
			 PhaseCommand("modifica", 0), PhaseCommand("fevento", 0)};

}

GameInterface::~GameInterface() {
	//delete [] phaseCommand; // já não é necessário porque passou a ser um vector com objetos que não sao criados dinamicamente
	delete currentGame;
}

void GameInterface::printPhaseCommands(ostream &out, int phase) {
	bool isFirst = true;
	for (auto &item : phaseCommand) {
		if (item.getPhase() == phase) {
			if (isFirst) {
				out << item.getCommand();
				isFirst = false;
				continue;
			}
			out << ", " << item.getCommand();
		}
	}
}

void GameInterface::printMenu(ostream &out) {
	out << "\n\n";
	int phase = currentGame->getPhase();
	if (currentGame->isInCreation()) {
		out << "Jogo a ser criado\n\tComandos disponiveis: "
			<< "\n\t\tcria <tipo_territorio> <quantidade> \n\t\tcarrega <caminho_do_ficheiro>\n\t\tavanca";
		out << "\nIntroduza o commando que deseja correr\n ->";
		return;
	}
	if (currentGame->isInProgress()) {
		out << "Fase " << phase << "\n\tComandos disponiveis: \n\t";
		printPhaseCommands(out, phase);
	} else if (currentGame->isGameFinished()) {
		out << "Jogo terminado. Mas podes voltar aos teus jogos guardados.\n"
			<< "Pontuacao final: " << currentGame->getFinalScore() << "\n";
	}
	out << "\nMais comandos: \n\t";
	printPhaseCommands(out, 0);

	out << "\nIntroduza o commando que deseja correr\n ->";
}

void GameInterface::handleCommand(ostream &out, vector<std::string> &inputParts) {

	if (inputParts.empty()) {
		out << "Comando vazio. Introduza novamente\n";
		return;
	}
	const string &action = inputParts[0];

	if (action == "lista") {
		listGame(inputParts, out);
		return;
	}

	if (currentGame->isInProgress()) {
		handleGameCommand(out, inputParts);
	} else if (currentGame->isGameFinished()) {
		out << "Game is finished\n";
	} else {
		handleCreationCommand(out, inputParts);
	}
}

void GameInterface::handleCreationCommand(ostream &out, vector<std::string> &inputParts) {
	// Pre Game ----------------------------------------------------------------------------------------------------
	//Criação do jogo
	const string &action = inputParts[0];
	if (action == "avanca") {
		if (currentGame->isInProgress()) {
			currentGame->nextPhase(out);
		} else if (currentGame->start()) {
			out << "Jogo iniciado\n";
		} else {
			out << "Mundo vazio, adicione territorios primeiro\n";
		}
	} else if (action == "cria") {
		//cria <tipo> <n> - Acrescenta ao mundo n territórios de um determinado tipo (exemplo:
		//mina, refugio, para respetivamente um território do tipo Mina ou do tipo Refugio).
		if (inputParts.size() == 3) {
			int amount = stoi(inputParts[2]);
			string &type = inputParts[1];

			for (int i = 0; i < amount; ++i) {
				Territorio *newTerritory = Factory::createTerritoryFromType(type);
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
				currentGame->print(cout);
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
	//In Game ----------------------------------------------------------------------------------------------------------
	const string &action = inputParts[0];

	int commandPhase = getCommandPhase(action);

	if (commandPhase != currentGame->getPhase() && commandPhase != 0) { // = 0 ,quer dizer que é para todas as fazes
		out << "Commando invalido para a fase atual\n";
		return;
	}

	if (commandPhase == 0) {
		handleCommandAnyPhase(out, inputParts);
	} else if (commandPhase == 1) {
		handleCommandPhase1(out, inputParts);
	} else if (commandPhase == 2) {
		handleCommandPhase2(out, inputParts);
	} else if (commandPhase == 3) {
		handleCommandPhase3(out, inputParts);
	} // na fase 4 não existem comandos, apenas podem acontecer coisas que o jogador não pode afetar
}

void GameInterface::handleCommandPhase1(ostream &out, vector<std::string> &inputParts) {
	const string &action = inputParts[0];
	if (action == "conquista") {
		//conquista <nome> - Dá a ordem ao império para adquirir um determinado território
		//neste turno desde que este esteja disponível no World. O parâmetro nome indica
		//qual o nome do território a conquistar (planicie1, duna3, etc.).

		if (inputParts.size() == 2) {
			int whatHappened = currentGame->conquer(inputParts[1]);
			if (whatHappened == -1) {
				out << "Nome de territorio invalido\n";
			} else if (whatHappened == false) {
				out << "Nao consegui conquistar\n";
				currentGame->nextPhase(out);
			} else {
				out << "Conquistado com sucesso\n";
				currentGame->nextPhase(out);
			}
		} else {
			out << "Sintaxe valida -> conquista <nome_do_territorio>\n";
		}

	} else if (action == "passa") {
		currentGame->nextPhase(out);
		out << "Passou o turno a frente\n";
	}
}

void GameInterface::handleCommandPhase2(ostream &out, vector<std::string> &inputParts) {
	const string &action = inputParts[0];

	if (action == "maisouro") {
		if (currentGame->moreGold()) {
			out << "Obteve mais 1 de ouro e perdeu 2 de produtos\n";
		} else {
			out << "Nao tens produtos suficientes para trocar, necessario 2\n";
		}
	} else if (action == "maisprod") {
		if (currentGame->moreProducts()) {
			out << "Obteve mais 1 de produtos e perdeu 2 de ouro\n";
		} else {
			out << "Nao tens ouro suficiente para trocar, necessario 2\n";
		}
	}
}

void GameInterface::handleCommandPhase3(ostream &out, vector<std::string> &inputParts) {
	const string &action = inputParts[0];

	if (action == "maismilitar") {
		if (currentGame->moreMilitary()) {
			out << "Obteve mais 1 de forca militar á custa de 1 de ouro e 1 de produutos\n";
		} else {
			out << "Nao tens produtos e ouro suficientes para trocar, necessario 1 de cada\n";
		}
	} else if (action == "adquire") {
		if (inputParts.size() == 2) {
		    //TODO test this
		    int whatHappen = currentGame->acquire(inputParts[1]);
			if (whatHappen == -1) {
                cout << "o Reino ja possui esta tecnologia\n";
			} else if (whatHappen == -2 ){
                cout << "o Reino nao consegue comprar a tecnologia\n";
			} else if (whatHappen == false){
                out << "sintaxe valida -> adquire <tipo>\n";
			} else {
                out << "Tecnlogia adquirida\n";
                //ele que ande com as maos
			}
		} else {
			out << "sintaxe valida -> adquire <tipo>\n";
		}
	}
}

void GameInterface::handleCommandAnyPhase(ostream &out, vector<std::string> &inputParts) {
	const string &action = inputParts[0];

	if (action == "lista") {
		listGame(inputParts, out);
	} else if (action == "grava") {
		// Grava o jogo em memória -------------------------------------------------------------------------------------
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
	} else if (action == "ativa") {
		// Recupera um jogo que estava em memória ----------------------------------------------------------------------
		if (inputParts.size() == 2) {
			const string &name = inputParts[1];
			if (gameSaver.usedSaveGameName(name)) {
				Game *newGame = gameSaver.getSavedGameByName(name);
				delete currentGame;
				currentGame = new Game(*newGame);
				cout << "Jogo " << currentGame->getName() << " retomado\n";
			} else {
				out << "Nao existe jogo com esse nome\n";
				gameSaver.printAll(out);
			}
		} else {
			out << "sintaxe valida -> ativa <nome_do_jogo>\n Jogos guardados atualmente: -----------------------------";
			gameSaver.printAll(out);
			out << "---------------------------------------------\n";
		}
	} else if (action == "apaga") {
		// Apaga um jogo que estava em memória -------------------------------------------------------------------------
		if (inputParts.size() == 2) {
			const string &name = inputParts[1];
			if (gameSaver.usedSaveGameName(name)) {
				gameSaver.deleteGame(name);
				cout << "Jogo " << name << " apagado com sucesso\n";
			} else {
				out << "Nao existe jogo com esse nome\n";
			}
		}
	} else if (currentGame->isInProgress()) {
		if (action == "avanca") {
			// Avança para a próxima fase ----------------------------------------------------------------------------------
			currentGame->nextPhase(out);
		} else if (action == "toma") { // TODO TEST THIS
			// Obtem tecnologia ou territorio sem seguir as regras do jogo -------------------------------------------------
			if (inputParts.size() == 3 && inputParts[1] == "terr" || inputParts[1] == "tec") {
				const string &qual = inputParts[1];
				const string &name = inputParts[2];
				if (qual == "terr") {
					Territorio *terr = currentGame->getTerritoryByName(name);
					if (terr != nullptr) {
						currentGame->forceConquer(terr);
					} else {
						cout << "O territorio nao existe\n";
					}
				} else if (qual == "tec") {
                    Technology *technology = Factory::createTechnologyFromType(name);
					if (technology != nullptr) {
						currentGame->forceAcquire(technology);
					} else {
						out << "sintaxe valida -> toma <terr || tec> <nome>\n";
					}
				}
			} else {
				out << "sintaxe valida -> toma <terr || tec> <nome>\n";
			}
		} else if (action == "modifica") {
			// Modifica a quantidade de recursos sem seguir as regras do jogo ----------------------------------------------
			if (inputParts.size() == 3) {

				const string &qual = inputParts[1];
				if (qual == "ouro" || qual == "prod") {

					int amount = stoi(inputParts[2]);
					if (amount) {
						if (qual == "ouro") {
							currentGame->setKingdomGold(amount);
							out << "alterada a quantidade de ouro para : " << amount;
							return;
						} else if (qual == "prod") {
							currentGame->setKingdomWarehouse(amount);
							out << "alterada a quantidade de produtos para : " << amount;
							return;
						}
					}
				}
			}
			out << "sintaxe valida -> modifica <ouro|prod> <quantidade>\n";

		} else if (action == "fevento") {
			// Força o acontecimento de um evento --------------------------------------------------------------------------
			if (inputParts.size() == 2) {
				const string &eventType = inputParts[1];
				if (eventType == "abandona") {
					currentGame->abandonedResource();
					out << "Obtiveste recursos";
				} else if (eventType == "invasao") {
					Territorio *invaded = currentGame->getKingdom().getLastConquered();
					if (currentGame->invaded()) {
						out << "Perdeste o teu ultimo territorio conquistado:\n\t" << *invaded << "\n";
					} else {
						out << "Tiveste sorte! não perdeste o teu terrritorio conquistado mais recentemente\n";
					}
				} else if (eventType == "alianca") {
					currentGame->diplomaticAlliance();
					out << "Força militar aumentada em 1 para : " << currentGame->getKingdom().getMilitaryForce()
						<< "\n";
				} else {
					out << "sintaxe valida -> fevento <abandona || invasao || alianca>\n";
				}
			} else {
				out << "sintaxe valida -> fevento <abandona || invasao || alianca>\n";
			}
		}
	} else {
		out << "Jogo ja terminado, certos comandos nao podem ser utilizados";
	}
}

int GameInterface::getCommandPhase(const string &command) {
	for (const auto &item : phaseCommand) {
		if (item.getCommand() == command)
			return item.getPhase();
	}
	return -1;
}

void GameInterface::listGame(vector<std::string> &inputParts, ostream &out) {
// Lista o jogo ou territorio ----------------------------------------------------------------------------------
	if (inputParts.size() == 1) {
		currentGame->print(cout);
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
}
