#include "File.h"

vector<Product*> File :: InFile(const char* namefile){
    vector<Product*> result;
    fstream file;
    file.open(namefile, ios ::in);
    while(!file.eof()){
        string s;
        stringstream ss;
        getline(file, s);
        vector<string> Tokens = Utils::String::split(s, " "); //// tach sai chuoi
        // for (int i = 0; i < Tokens.size(); i++){
        //     cout << Tokens[i] << endl;
        // }
        string id = Tokens[0];
        // cout << id << endl;
        ss << Tokens[1] << " " << Tokens[2] << " " <<  Tokens[3];
        string name = ss.str();
        // cout << name << endl;
        ll price = stoll(Tokens[4]);
        // cout << price << endl;
        Product* temp = new Product(id, name,price);
        result.push_back(temp);
    }
    file.close();
    return result;
}

void File :: OutFile(const char* namefile, vector<Product*> data){
    fstream file;
    file.open(namefile, ios :: out);
    for (int i = 0; i < data.size(); i++){
        file << data[i] -> get_id() << " " << data[i] -> get_name() << " " << data[i] -> get_price();
        if (i != data.size() - 1)file << endl;
        else continue;
    }
    file.close();
    return;
}