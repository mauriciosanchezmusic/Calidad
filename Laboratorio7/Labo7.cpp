//Ivan Escalante
//20/11/19
/*
Lee el teclado de l nomrbe de un archivo
Lee renglón 1 ->  Wk, xk, yk  - reutiliza el  6 ¿   ( pero falta la parte de WK  )
Segundo renglón  ( w,x, y, z)  N >= 0  -> separado Dos comas
Fin de archivo marca el final de los cuadriplos <- checa el doc para uqe veas de que e trata

Hace los calculos necesario de regresaion
despliega los resultados en pantalla

*/

#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<regex>
#include<vector>
#include<cmath>
#include <iomanip>

//#include clase nueva para datos historicos

//#include clase nueva para regresion multiple

#include "Datos.h"
#include "RegrMultiple.h"

using namespace std;

string nombreArch;
bool bError = false;

double wk;
double xk;
double yk;

vector<Datos> datos;

//.i

bool validarArchivo(string nombreArch){
    ifstream file;
    file.open(nombreArch);

    //aqui verificamos que efectivamente se abrio el archivo
    if(file.is_open()){
        char test;
        file.get(test);
        //es el primer caracter el eof ?
        if(file.eof()){
            file.close();
            cout<<"El archivo : "<< nombreArch<<" es un archivo vacio."<<endl;
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
    cout<<"ERROR 001: el archivo con nombre :''"<<nombreArch<<"'' no pudo ser encontrado, favor de revisarlo."<<endl;
    return false;
}
//.i
void leerArchivo(string nombreArch){
    //si sale error saca el string
    ifstream file;
    file.open(nombreArch);
    string line;
    getline(file, line);

    try{
    //la linea a entero
    wk = stod(line);
    //int xk = stoi(line);
    //first,
    int pos = line.find_first_of(",");
    line = line.substr(pos+1);
    xk =stod(line);
    //second,
    pos = line.find_first_of(",");
    line = line.substr(pos+1);
    yk = stod(line);




    if(xk<0){
    cout<<"Error, el xk es < a 0 "<<endl;
    bError = true;
    }
    if(yk<0){
    cout<<"Error, el yk es < a 0 "<<endl;
    bError = true;
    }
    if(wk<0){
    cout<<"Error, el wk es < a 0 "<<endl;
    bError = true;
    }


    //quiza tengas que borrar e else
    else{
        while(!file.eof()){
            //lees renglon y a decimales
            getline(file,line);

            double w = stod(line);
            //lookin for that comma
            pos = line.find_first_of(",");
            line = line.substr(pos+1);

            //que agarre el sig caracter
            double x = stod(line);
            pos = line.find_first_of(",");
            line = line.substr(pos+1);

            double y = stod(line);
            pos = line.find_first_of(",");
            line = line.substr(pos+1);

            double z = stod(line);
            //pos = line.find_first_of(",");
            //line = line.substr(pos+1);


            //.substr(pos+1));

            //puntos de verificacion de x Y y
            if(x<0){//.m
                bError = true;
                cout<<"Error X en renglon "<<datos.size()+2<<" es menor a 0"<<endl;

            }
            if(y<0){//.m
                bError = true;
                cout<<"Error Y en renglon "<<datos.size()+2<<" es menor a 0"<<endl;

            }
            if(z<0){
                bError = true;
                cout<<"Error Z en renglon "<<datos.size()+2<<" es menor a 0"<<endl;

            }
            Datos datoTemporal = Datos(w,x,y,z);
            datos.push_back(datoTemporal);
//.d=5

        } //while

    } //else
    }catch (const invalid_argument ie){
        cout<<"Error al leer los datos."<<endl;
        bError = true;
    }

    file.close();
}


int main(){
    string nombreArch;
    getline(cin,nombreArch);

    if(validarArchivo(nombreArch)){
            leerArchivo(nombreArch); //falta meterla
            if(bError!= true){
                RegrMultiple rm = RegrMultiple(datos);
                rm.display(wk,xk,yk);
            }


    }
    return 0;
}




