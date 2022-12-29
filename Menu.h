#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include "key.h"
#include "color.h"
#include "Console.h"
#include "Object.h"
#include "File.h"
#include "FactoryProduct.h"

using namespace std;

enum class Cases : int{
    display = 0,
    add = 1,
    dele = 2
};

class Menu : public Object{
private:
    void Switch_case(int choice);
public:
    virtual void PrintOut();
    string toString(){return NULL;}
};

class Display : public Menu{
public:
    void PrintOut();
    static void Edit(Console* console, Product* in);
};

class Add : public Menu{
public:
   void PrintOut();
};

class Delete : public Menu{
public:
    void PrintOut();
};