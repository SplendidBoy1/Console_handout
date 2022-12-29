#pragma once

#include <fstream>
#include <vector>
#include <sstream>
#include "Product.h"
#include "Utils.h"

using namespace std;

class File{
public:
    static vector<Product*> InFile(const char* namefile);
    static void OutFile(const char* namefile, vector<Product*> data);
};