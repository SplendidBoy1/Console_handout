#include "Utils.h"


vector <string> Utils :: String :: split(string line, string cut){
    vector<string> result;
    int startPos = 0;
    size_t foundPos = line.find(cut, startPos);
    while(foundPos != string::npos){
        size_t count = foundPos - startPos;
        string token = line.substr(startPos, count);
        result.push_back(token);
        startPos = count + cut.length() + startPos;
        foundPos = line.find(cut, startPos);
    }
    string token = line.substr(startPos, line.length() - startPos);
    result.push_back(token);
    return result;
}