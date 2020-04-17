#ifndef LINEAS_H_INCLUDED
#define LINEAS_H_INCLUDED

#include <iostream>

using namespace std;

class Lineas{
private:
    int lineasBase; //.b
    int lineasBorradas; //.d
    int lineasModificadas; //.m
    int lineasAgregadas; //.a

public:
    //constructores
    Lineas();
    Lineas(int lineasBase, int lineasBorradas , int lineasModificadas, int lineasAgregadas);


    //getters
    int getLineasBase();
    int getLineasBorradas();
    int getLineasModificadas();
    int getLineasAgregadas();

    //setters
    void setLineasBase(int lineasBase);
    void setLineasBorradas(int lineasBorradas);
    void setLineasModificadas(int lineasModificadas);
    void setLineasAgregadas(int lineasAgregadas);

    int total();
    string display(); //si no funciona lo regresamos a void
    //void imprimir();

    //new
    char getType();
    void sumaBase(int lineasBase);
    void sumaBorradas(int lineasBorradas);
    void sumaModificadas(int lineasModificadas);
    void sumaAgregadas(int lineasAgregadas);
    void sumaLineas(Lineas lineas);
};

//Los constructores
Lineas::Lineas(){
    lineasBase = 0;
    lineasBorradas = 0;
    lineasAgregadas = 0 ;
    lineasModificadas =0;
}

Lineas::Lineas(int lineasBase, int lineasBorradas, int lineasModificadas, int lineasAgregadas){
    this->lineasBase = lineasBase;
    this->lineasBorradas = lineasBorradas;
    this->lineasModificadas= lineasModificadas;
    this->lineasAgregadas = lineasAgregadas;
}

//mr. getters

int Lineas::getLineasBorradas(){
    return lineasBorradas;
}
int Lineas::getLineasBase(){
    return lineasBase;
}
int Lineas::getLineasModificadas(){
    return lineasModificadas;
}
int Lineas::getLineasAgregadas(){
    return lineasAgregadas;
}

//Mr. Setters

void Lineas:: setLineasBase(int lineasBase){
    this-> lineasBase = lineasBase;
}
void Lineas:: setLineasBorradas(int lineasBorradas){
this->lineasBorradas = lineasBorradas;
}

void Lineas:: setLineasModificadas(int lineasModificadas){
this->lineasModificadas = lineasModificadas;
}
void Lineas:: setLineasAgregadas(int lineasAgregadas){
    this->lineasAgregadas = lineasAgregadas;
}


//el sumador de lineas totales
int Lineas:: total(){
    return (lineasBase - lineasBorradas + lineasAgregadas);
}

//la impresion de las lineas de codigo
//void Lineas::imprimir(){
 //   cout<<"---------------------------------------------"<<endl;
 //   cout<<"Cantidad de lineas en Blanco: "<<lineasBlanco<<endl;
  //  cout<<"Cantidad de lineas con comentarios: "<<lineasComent<<endl;
   // cout<<"Cantidad de lineas con codigo: "<<lineasCode<<endl;
   // cout<<"----------------------------------------------"<<endl;

//}

char Lineas::getType(){
    if(lineasBase > 0 && (lineasBorradas >0 || lineasModificadas >  0 || lineasAgregadas >0)){
        return 'B'; //base
    }else if(lineasBase == 0 && lineasBorradas == 0 && lineasModificadas ==0 && lineasAgregadas>0){
        return 'N'; //nuevo
    }else if(lineasBase > 0  && lineasBorradas == 0 && lineasModificadas ==0 && lineasAgregadas ==0){
        return 'R'; //reutilizada
    }else{
        return 'E'; //de error
    }
}

//los nuevos

void Lineas::sumaBase(int lineasBase){
    this->lineasBase += lineasBase;
}
void Lineas::sumaBorradas(int lineasBorradas){
    this->lineasBorradas+= lineasBorradas;
}
void Lineas::sumaModificadas(int lineasModificadas){
    this-> lineasModificadas += lineasModificadas;
}
void Lineas::sumaAgregadas(int lineasAgregadas){
    this-> lineasAgregadas += lineasAgregadas;
}

string Lineas::display(){
    string text = ", B=" + to_string(lineasBase) + ", ";
    text += "D=" + to_string(lineasBorradas) + ", ";
    text += "M=" + to_string(lineasModificadas) + ", ";
    text += "A=" + to_string(lineasAgregadas) + "\n";
    return text;
}

void Lineas::sumaLineas(Lineas lineas){
this->lineasBase+= lineas.getLineasBase();
this->lineasBorradas+= lineas.getLineasBorradas();
this->lineasModificadas+= lineas.getLineasModificadas();
this->lineasAgregadas+= lineas.getLineasAgregadas();
}
#endif // LINEAS_H_INCLUDED
