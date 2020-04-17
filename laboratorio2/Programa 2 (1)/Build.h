#ifndef BUILD_H_INCLUDED
#define BUILD_H_INCLUDED


#include<iostream>
#include<string>

#include "Lineas.h"

using namespace std;

class Build{
private:
    string name;
    int items;
    Lineas lineas;

public:
    Build();
    Build(string name, int items, Lineas linea);
     //getters
     void setName(string name);
     void setItems(int items);
     void setLineas(Lineas lineas);

     //setters
     string getName();
     int getItems();
     Lineas getLineas();

     //metodos
     string display(char type);
     void sumaItems(int items);
     void sumaLineas(Lineas lineas);
     char getType();

};
//constructores
Build::Build(){
    name = "Hellow.empty";
    items = 0;
    lineas = Lineas();
}
Build::Build(string name, int items, Lineas lineas){
    this -> name= name;
    this -> items=items;
    this -> lineas=lineas;

}

//gotta catchemall
string Build::getName(){
    return name;
}

int Build::getItems(){
    return items;

}

Lineas Build::getLineas(){
    return lineas;
}

//setthetone

void Build::setName(string name){
    this ->name = name;
}
void Build::setItems(int items){
    this->items = items;
}
void Build::setLineas(Lineas lineas){
    this->lineas = lineas;
}

string Build:: display(char type){
    string text = name  + ": T=" + to_string(lineas.total()) + ", I =" + to_string(items);
    if(type=='B'){
        text += lineas.display();
    }else if(type=='R'){
        text += ", B=" + to_string(lineas.getLineasBase())+ "\n";
    }else if(type== 'E'){
        text = "ERROR en: " + name + "\n";
    }else{
    text += "\n";
    }
    return text;
}

char Build::getType(){
    return lineas.getType();
}

void Build::sumaItems(int items){
    this->items += items;
}
//las cosas extra que vayas agregando aqui abajo
void Build:: sumaLineas(Lineas lineas){
    this -> lineas.sumaLineas(lineas);
}
#endif // BUILD_H_INCLUDED
