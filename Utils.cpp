//
// Created by Rodrigo on 17/11/2020.
//

#include "Utils.h"

using namespace std;

std::vector<std::string> Utils::stringSplit(const std::string oriStr, const std::string delimiter) {
    vector<string> list;
    string str(oriStr);
    size_t pos;
    string token;
    while ((pos = str.find(delimiter)) != string::npos) {
        token = str.substr(0, pos);
        list.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    list.push_back(str);
    return list;
}
