#ifndef LEERARCHIVO_H_INCLUDED
#define LEERARCHIVO_H_INCLUDED

#include<iostream>
#include<string>

#include "Lineas.h"

using namespace std;

class LeerArchivo{
private:
    string nombre;
    Lineas lineas;

public:
    //constructores
    LeerArchivo();
    LeerArchivo(string nombre, Lineas lineas);
    //getters

    string getNombre();
    Lineas getLineas();

    //setters
    void setNombre(string nombre);
    void setLineas(Lineas linea);

    //el impresor de leer archivo
    void imprimirLA();
    //le puse LA porque el otro se llama igual
};
//constructoresss

LeerArchivo :: LeerArchivo(){
    nombre= "sinnombre.nada";
    lineas  = Lineas();
}

LeerArchivo::LeerArchivo(string nombre, Lineas lineas){
    this->nombre = nombre;
    this->lineas= lineas;
}
//mr getters
string LeerArchivo::getNombre(){
    return nombre;
}
Lineas LeerArchivo::getLineas(){
    return lineas;
}
//mr setter
void LeerArchivo::setNombre(string nombre){
    this->nombre=nombre;
}
void LeerArchivo::setLineas(Lineas lineas){
    this->lineas = lineas;
}

//el impresor que pusiste que seria impresionLA

void LeerArchivo:: imprimirLA(){
    cout<<"Nombre del archivo: "<<nombre<<endl;
    lineas.imprimir();
    cout<<"Cantidad total de lineas: "<<lineas.total()<<endl;
}



#endif // LEERARCHIVO_H_INCLUDED
