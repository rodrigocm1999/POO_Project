//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_TERRITORIO_H
#define TRABALHOPRATICO_TERRITORIO_H


#include <string>
#include <ostream>

class Territorio {

protected:

    std::string name;
    int resistance;
    int productProduction;
    int goldProduction;
    int victoryPoints;

public:

    virtual bool isContinent() const { return false; }

    virtual bool isIsland() const { return false; }

    virtual std::string getType() const {return "";}

    const std::string &getName() const {
        return name;
    }

    int getResistance() const {
        return resistance;
    }

    int getProductProduction() const {
        return productProduction;
    }

    int getGoldProduction() const {
        return goldProduction;
    }

    int getVictoryPoints() const {
        return victoryPoints;
    }

    friend std::ostream &operator<<(std::ostream &os, const Territorio &territorio) {
        os << "tipo : " << territorio.getType()
           << ", nome: " << territorio.name
           << ", resistencia: " << territorio.resistance
           << ", produtos: " << territorio.productProduction
           << ", ouro: " << territorio.goldProduction
           << ", pontos: " << territorio.victoryPoints;
        return os;
    }

};

//std::ostream &operator<<(std::ostream &os, const Territorio &territory);


#endif //TRABALHOPRATICO_TERRITORIO_H
