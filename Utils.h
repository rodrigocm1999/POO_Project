//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_UTILS_H
#define TRABALHOPRATICO_UTILS_H

#define TURNSPERYEAR 6

#include <string>
#include <vector>


class Utils {
public:
	static std::vector<std::string> stringSplit(const std::string &oriStr, const std::string &delimiter);

	static int getRandom(int lower, int higher);

	static int turnToYear(int turn) { return (int) (turn / TURNSPERYEAR); };
};


#endif //TRABALHOPRATICO_UTILS_H
