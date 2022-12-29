#pragma once

#include <string>
#include <iostream>

#define ll long long

using namespace std;

class Product{
private:
    string _id;
    string _name;
    ll _price;
public:
    Product(string id, string name, ll price){this -> _id = id; this ->_name = name; this ->_price = price;};
    string get_id(){return this ->_id;}
    string get_name(){return this ->_name;}
    ll get_price(){return this -> _price;}
    void set_name(string name){this ->_name = name;}
    void set_price(ll price){this -> _price = price;}

};