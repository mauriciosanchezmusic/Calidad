#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include<iostream>
#include<iomanip>
#include<cmath>

#include"Punto.h"

using namespace std;

class Archivo{
private:
    int n;
    int xk;
    double r;
    double b0;
    double b1;
    double yk;
public:
    Archivo();
    Archivo(int n, int xk, double r,double b0,double b1,double yk);
    void imprimir();
    };

Archivo::Archivo(){
n=0;
xk=0;
r=0;
b0=0;
b1=0;
yk=0;
}
Archivo::Archivo(int n, int xk, double r,double b0,double b1,double yk){
this ->n=n;
this ->xk=xk;
this ->r=r;
this ->b0=b0;
this ->b1=b1;
this ->yk=yk;
}

void Archivo::imprimir(){
cout<<setprecision(5)<<fixed;
cout<<"N    ="<<n<<endl;
cout<<"Xk   ="<<xk<<endl;
cout<<"r    ="<<round(r*100000)/100000<<endl;
cout<<"r2   ="<<round(r*r*100000)/100000<<endl;
cout<<"B0   ="<<round(b0*100000)/100000<<endl;
cout<<"B1   ="<<round(b1*100000)/100000<<endl;
cout<<"Yk   ="<<round(yk*100000)/100000<<endl;
}


#endif // ARCHIVO_H_INCLUDED
