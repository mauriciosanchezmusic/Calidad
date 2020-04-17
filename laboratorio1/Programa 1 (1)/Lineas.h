#ifndef LINEAS_H_INCLUDED
#define LINEAS_H_INCLUDED

#include <iostream>

using namespace std;

class Lineas{
private:
    int lineasBlanco;
    int lineasComent;
    int lineasCode;

public:
    //constructores
    Lineas();
    Lineas(int lineasBlanco, int lineasComent , int lineasCodigo);

    //getters
    int getLineasBlanco();
    int getLineasComent();
    int getLineasCode();

    //setters
    void setLineasBlanco(int lineasBlanco);
    void setLineasComent(int lineasComent);
    void setLineasCode(int lineasCode);

    int total();
    void imprimir();
};

//Los constructores
Lineas::Lineas(){
    lineasBlanco=0;
    lineasComent=0;
    lineasCode=0;
}

Lineas::Lineas(int lineasBlanco, int lineasComentario, int lineasCodigo){
    this->lineasBlanco= lineasBlanco;
    this->lineasComent= lineasComent;
    this->lineasCode= lineasCode;
}

//mr. getters

int Lineas::getLineasBlanco(){
    return this->lineasBlanco;
}

int Lineas::getLineasComent(){
    return this->lineasComent;
}

int Lineas::getLineasCode(){
    return this->lineasCode;
}
//Mr. Setters

void Lineas:: setLineasBlanco(int lineasBlanco){
    this->lineasBlanco = lineasBlanco;
}
void Lineas:: setLineasComent(int lineasComent){
    this->lineasComent = lineasComent;
}
void Lineas:: setLineasCode(int lineasCode){
this->lineasCode = lineasCode;
}

//el sumador de lineas totales
int Lineas:: total(){
    return (lineasBlanco + lineasComentario + lineasCodigo);
}

//la impresion de las lineas de codigo
void Lineas::imprimir(){
    cout<<"---------------------------------------------"<<endl;
    cout<<"Cantidad de lineas en Blanco: "<<lineasBlanco<<endl;
    cout<<"Cantidad de lineas con comentarios: "<<lineasComent<<endl;
    cout<<"Cantidad de lineas con codigo: "<<lineasCode<<endl;
    cout<<"----------------------------------------------"<<endl;

}


#endif // LINEAS_H_INCLUDED
