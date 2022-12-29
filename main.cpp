#include "Menu.h"

int main(){
    Object* main;
    main = new Menu;
    Menu* menu = dynamic_cast<Menu*> (main);
    menu -> PrintOut();
    system("pause");
    return 0;
}