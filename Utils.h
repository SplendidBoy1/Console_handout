#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace Utils
{
    class String{
    public:
    static vector<string> split(string line, string cut);
    };
}