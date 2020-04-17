
#include<iostream>
#include<cstring>
#include<queue>
#include<string>
#include<stack>
#include<fstream>
#include<regex>
#include<vector>
#include<cmath>
#include <iomanip>

#include "Archivo.h"
#include "Punto.h"
using namespace std;

//veamos que el archivo si existe !vacio

bool validarArchivo(string Archivo){
    ifstream file;
    file.open(Archivo);

    //aqui verificamos que efectivamente se abrio el archivo
    if(file.is_open()){
        //cout<<"si se abrio \n"<<endl;
        //vamos a ver si abre el primer caracter
        char test;
        file.get(test);
        //es el primer caracter el eof ?
        if(file.eof()){
            file.close();
            cout<<"El archivo : "<< Archivo<<" es un archivo vacio."<<endl;
            return false;
        }
        //cout<<"el archivo si tenia cosas jeje"<<e
        //cout<<"el nombre del archivo es : "<<Archivo<<" --- "<<endl;

        //cerramos despues de usarlo
        file.close();
        return true;
        //true porque si se abrio, la funcion es booleana
    }
    file.close();
    cout<<"ERROR 001: el archivo con nombre :''"<<Archivo<<"'' no pudo ser encontrado, favor de revisarlo."<<endl;
    return false;
}

//creamos el objeto archivo para imprimir
void newArchivo(int n, int xk,vector<Punto> punto){
double sumX = 0;
double sumY = 0;
double sumX2 =0;
double sumY2 =0;
double sumXY =0;


for (int i =0;i<n;i++){
    double x = punto[i].getX();
    double y = punto[i].getY();

    sumX +=x;
    sumY += y;
    sumX2+=x*x;
    sumY2+=y*y;
    sumXY+=x*y;
}
double xProm = sumX/n;
double yProm = sumY/n;

//b1 y b0
double b1 =((sumXY)-(n*xProm*yProm))/(n*xProm*yProm);
double b0 =yProm-(b1-xProm);

double r = ((n*sumXY)-(sumX*sumY))/(sqrt( ((n*sumX2)-(sumX*sumX))*((n*sumY2)-(sumY*sumY)) ));

double yk = b0 +(b1*xk);
Archivo arch= Archivo(n,xk,r,b0,b1,yk);
arch.imprimir();
}

//aqui abrimos el archivo y vemos cuandas lineas son
void leerArchivo(string nombreArch){
    ifstream file;
    file.open(nombreArch);

    string line;
    getline(file, line);
    //la linea a entero
    int xk = stoi(line);
    vector<Punto> puntos;
    int n =0 ;
    //error cuando xk sea negativo
    if(xk<0){
        cout<<"Error, el xk es < a 0 "<<endl;
    }else{
        while(!file.eof()){
            //lees renglon y a decimales
            getline(file,line);
            double x = stod(line);
            //lookin for that comma
            int pos = line.find_first_of(",");
            //que agarre el sig caracter
            double y = stod(line.substr(pos+1));

            Punto puntoTemporal = Punto(x,y);
            puntos.push_back(puntoTemporal);

            n++;
            //le vas sumando para ver cuantas ns hay denro delprograma

        }
        //hay datos?
        if(n>0){
            newArchivo(n,xk,puntos);

        }else{
        cout<<"Error, no hay n"<<endl;
        }
    }
    file.close();
}

int main(){
string nombreArch;
getline(cin, nombreArch);

if(validarArchivo(nombreArch)){
    leerArchivo(nombreArch);
}
return 0;
}

