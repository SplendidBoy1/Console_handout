#include "FactoryProduct.h"

void FactoryProduct :: Sort_id(){
    for (int i = 0; i < this ->get_product().size(); i++){
        for (int j = i + 1; j < this -> get_product().size(); j++){
            int left = stoi(this ->get_product().at(i)->get_id());
            int right = stoi(this ->get_product().at(j)->get_id());
            if ( left > right){
                Product* temp;
                temp = this ->get_product().at(j);
                this ->get_product().at(j) = this ->get_product().at(i);
                this ->get_product().at(i) = temp;
            }
        }
    }
}