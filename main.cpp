#include <iostream>
#include <sstream>
#include <string>

#include "Castelo.h"
#include "Continente.h"
#include "Duna.h"
#include "Fortaleza.h"
#include "Ilha.h"
#include "Imperio.h"
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

int main() {


    while (true) {

        string inputString;
        getline(cin, inputString);
        vector<string> inputParts = Utils::stringSplit(inputString, " ");
        if (inputParts.empty()) {
            cout << "Comando inválido. Introduza novamente\n";
        }
        string &action = inputParts[0];

        if (action == "cria") {

        } else if (action == "carrega") {

        } else if (action == "conquista") {

        } else if (action == "lista") {

        } else if (action == "sair") {
            break;
        }

    }
    return 0;
}
