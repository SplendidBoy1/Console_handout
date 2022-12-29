#pragma once

#include <iostream>
#include <vector>
#include "Product.h"

using namespace std;

class FactoryProduct{
private:
    vector<Product*> _products;

public:
    void set_products(vector<Product*> products){this -> _products = products;}
    vector<Product*>& get_product(){return this -> _products;}
    void Sort_id();
};