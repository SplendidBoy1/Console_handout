#include "Menu.h"

void Menu :: PrintOut(){
    bool menu = true;
    Console console;
    unsigned int choice = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while (menu){
        system("cls");
        SetConsoleTextAttribute(hConsole, static_cast<int>(Colors::white));
        console.GotoXY(0, 0);
        cout << "MyShop App. Please select a function" << endl;
        string option[3] = {
            "1. Display all product (paging support - table)",
            "2. Add a new product",
            "3. Delete a product by id"
        };
        for (int i = 0; i < 3; i++){
            if (choice == i)SetConsoleTextAttribute(hConsole, static_cast<int>(Colors::lightBlue));
            else SetConsoleTextAttribute(hConsole, static_cast<int>(Colors::white));
            console.GotoXY(3, i + 1);
            cout << option[i];
        }
        console.GotoXY(0, 5);
        SetConsoleTextAttribute(hConsole, static_cast<int>(Colors::white));
        cout << "Press escape to quit" << endl;
        console.GotoXY(3, choice + 1);
        bool flag = true;
        while(flag){
            unsigned char key = _getch();
        
            if(int(key) == static_cast<int>(Keys::up) && choice > 0){
                choice --;
                flag = false;
                continue;
            }
            if(int(key) == static_cast<int>(Keys::down) && choice < 2){
                choice ++;
                flag = false;
                continue;
            }
            if (int(key) == static_cast<int>(Keys::enter)){
                this ->Switch_case(choice);
                flag = false;
                continue;
            }
            if (int(key) == static_cast<int>(Keys :: escape)){
                flag = false;
                menu = false;
                system("cls");
                continue;
            }
        // if (int(key) >= 72 && int(key) <= 80) {

        //     switch (int(key)) {
        //     case static_cast<int>(Keys::up):
        //         cout << "Up";
        //         break;
        //     case static_cast<int>(Keys::down):
        //         cout << "Down";
        //         break;
        //     case static_cast<int>(Keys::left):
        //         cout << "Left";
        //         break;
        //     case static_cast<int>(Keys::right):
        //         cout << "Right";
        //         break;
        //     case static_cast<int>(Keys::del):
        //         cout << "Delete";
        //         break;
        //     }
        // }
        // else {
        //     switch (key) {
        //     case static_cast<int>(Keys::enter):
        //         cout << "Enter";
        //         break;
        //     case static_cast<int>(Keys::escape):
        //         cout << "Escape";
        //         break;
        //     }
        // }
        }
    }
}

void Menu :: Switch_case(int choice){
    system("cls");
    Object* screen;
    switch(choice){
        case static_cast<int>(Cases :: display):
            screen = new Display;
            dynamic_cast<Display*>(screen) ->PrintOut();
            break;
        case static_cast<int>(Cases :: add):
            screen = new Add;
            dynamic_cast<Add*>(screen) -> PrintOut();
            break;
        case static_cast<int>(Cases :: dele):
            screen = new Delete;
            dynamic_cast<Delete*>(screen) -> PrintOut();
            break;
    }
}

/////////////////////
// void Add :: PrintOut(){

// }

// void Delete :: PrintOut(){

// }
//////////////////////////////////////////////////////////
void Display :: PrintOut(){
    system("cls");
    
    int page = 1;
    
    bool display = true;
    Console console;
    unsigned int choice = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int xConsole = 1, yConsole = 3;
    while (display){
        FactoryProduct data;
        data.set_products(File :: InFile("data.txt"));
        int max_page = (data.get_product().size() / 10) + 1;
        system("cls");
        SetConsoleTextAttribute(hConsole, static_cast<int>(Colors::white));
        console.GotoXY(0, 0);
        cout << "All products. Page " << page << "/" << max_page << ". Displaying " << ((page < max_page)?10:((data.get_product().size() % 10 == 0)?10:data.get_product().size()%10)) << "/" << data.get_product().size() << " items";
        console.GotoXY(0, 1);
        cout << setw(4) << "ID|" << setw(31) << "Name|" << setw(20) << "Price";
        console.GotoXY(0, 2);
        for (int i = 0; i < 55; i++){
            cout << "_";
        }
        int max_to_print = (page < max_page) ? (page* 10) : data.get_product().size();
        int position = (page - 1)*10;
        int count = max_to_print - position;
        for (position ; position < max_to_print; position++){
            if (choice % 10 == position - (page - 1)* 10){
                SetConsoleTextAttribute(hConsole, static_cast<int>(Colors::lightBlue));
            }
            else  SetConsoleTextAttribute(hConsole, static_cast<int>(Colors::white));
            console.GotoXY(0, 3 + position % 10);
            cout << setw(3) << data.get_product()[position] ->get_id() << setw(30) << data.get_product()[position] ->get_name() << setw(20) << data.get_product()[position] -> get_price();
        }
        
        cout << endl;
        console.GotoXY(0, 4 + count);
        SetConsoleTextAttribute(hConsole, static_cast<int>(Colors::white));
        cout << "Use left and right arrow to go to next/previous page";
        console.GotoXY(0, 5 + count);
        cout << "Press delete to delete a row";
        console.GotoXY(0, 6 + count);
        cout << "To view the detail of a product for editing, press enter";
        console.GotoXY(0, 7 + count);
        cout << "Press escape to go back to main menu";
        
        console.GotoXY(xConsole, yConsole);
        bool flag = true;
        while(flag){
            unsigned char key = _getch();
            if(int(key) == static_cast<int>(Keys::up) && yConsole > 3){
                choice--;
                console.GotoXY(xConsole, --yConsole);
                flag = false;
                system("cls");
                continue;
            }
            if(int(key) == static_cast<int>(Keys::down) && yConsole < 2 + count){
                choice++;
                console.GotoXY(xConsole, ++yConsole);
                flag = false;
                system("cls");
                continue;
            }
            if(int(key) == static_cast<int>(Keys::right) && page < max_page){
                choice = page*10;
                page++;
                system("cls");
                xConsole = 0;
                yConsole = 3;
                flag = false;
                continue;
            }
            if(int(key) == static_cast<int>(Keys::left) && page > 1){
                choice = (page - 2)*10;
                page--;
                system("cls");
                xConsole = 0;
                yConsole = 3;
                flag = false;
                continue;
            }
            if(int(key) == static_cast<int>(Keys::enter)){
               Display ::Edit(&console, data.get_product().at(choice));
               system("cls");
               data.Sort_id();
               File :: File :: OutFile("data.txt", data.get_product());
               flag = false;
               continue;
            }
            if(int(key) == static_cast<int>(Keys::escape)){
                flag = false;
                display = false;
                system("cls");
                data.Sort_id();
                File :: OutFile("data.txt", data.get_product());
                continue;
            }
            if (int(key) == static_cast<int>(Keys::del)){
                system("cls");
                console.GotoXY(0, 0);
                cout << "Selected product:" << endl;
                cout << "ID=" << data.get_product().at(choice)->get_id() << ", Name=" << data.get_product().at(choice)->get_name() << ", Price=" << data.get_product().at(choice)->get_price() << endl << endl;
                cout << "Do you want to edit? (Y/N) " << endl;
                char input;
                cin >> input;
                if (toupper(input) == 'Y'){
                    data.get_product().erase(data.get_product().begin() + choice);
                    choice = 0;
                    page = 1;
                    xConsole = 0;
                    yConsole = 3;
                    flag = false;
                    data.Sort_id();
                    File :: OutFile("data.txt", data.get_product());
                }else{ 
                    flag = false;
                }
                continue;
            }
        }
    }
}

void Display :: Edit(Console* console, Product* in){
    system("cls");
    console ->GotoXY(0, 0);
    cout << "Selected product:" << endl;
    cout << "ID=" << in->get_id() << ", Name=" << in ->get_name() << ", Price=" << in ->get_price() << endl << endl;
    cout << "Do you want to edit? (Y/N) " << endl;
    char input;
    cin >> input;
    if (toupper(input) == 'Y'){
        bool flag = true;
        while(flag){
            cout << "Enter a new name" << endl;
            string name;
            cin.ignore();
            getline(cin, name, '\n');
            vector<string> Tokens = Utils :: String::split(name, " ");
            if (Tokens.size() != 3)continue;
            else {
                cout << "Enter a new price" << endl;
                ll price;
                cin >> price;
                in ->set_name(name);
                in -> set_price(price);
                flag = false;
            }
        }
        return;
    }
    else{
        return;
    }
}

//////////////////////////////////////////////////////////////
void Add :: PrintOut(){
    system("cls");
    stringstream id;
    string name;
    ll price;
    FactoryProduct data;
    data.set_products(File :: InFile("data.txt"));
    cout << "Add a new product" << endl;
    int count = 1;
    for (int i = 0; i < data.get_product().size(); i++){
        if (count < stoi(data.get_product().at(i)->get_id())){
            break;
        }
        else count++;
    }
    id << setw(3) << setfill('0') << count;
    bool flag = true;
        while(flag){
            cout << "Input a name of product" << endl;
            cin.ignore();
            getline(cin, name, '\n');
            vector<string> Tokens = Utils :: String::split(name, " ");
            if (Tokens.size() != 3)continue;
            else {
                cout << "Input a price" << endl;
                cin >> price;
                flag = false;
            }
        }
    Product* temp = new Product(id.str(), name, price);
    data.get_product().push_back(temp);
    cout << "Press enter to continue" << endl;
    data.Sort_id();
    File :: OutFile("data.txt", data.get_product());
}

///////////////////////////////////////////////////////////


void Delete::PrintOut(){
    system("cls");
    stringstream id;
    string name;
    ll price;
    FactoryProduct data;
    data.set_products(File :: InFile("data.txt"));
    cout << "Delete a product by id" << endl;
    string input;
    cout << "Input ID" << endl;
    cin >> input;
    bool same = false;

    for (int i = 0; i < data.get_product().size();i++){
        if (input == data.get_product().at(i)->get_id()){
            same = true;
            data.get_product().erase(data.get_product().begin() + i);
            break;
        }
        else continue;
    }
    if (same)cout << "Delete success" << endl;
    else cout << "Not found ID" << endl;
    cout << "Press enter to continue" << endl;
    data.Sort_id();
    File :: OutFile("data.txt", data.get_product());
}