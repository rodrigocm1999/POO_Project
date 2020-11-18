//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_UTILS_H
#define TRABALHOPRATICO_UTILS_H


#include <string>
#include <vector>


class Utils {
public:
    static std::vector<std::string> stringSplit(const std::string &oriStr, const std::string &delimiter);

    static int getRandom(int lower, int higher);
};


#endif //TRABALHOPRATICO_UTILS_H
