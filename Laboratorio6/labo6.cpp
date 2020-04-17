//Ivan Escalante
//06/12 /19
/*
 Calcalcula Regresion Lineal,
Correlacion, Significancia, Rangos de 70%

*/

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

#include "Simpson.h"

#include "Punto.h"

using namespace std;

//mete todas las variables de salidas del programa

int n = 0; //parejas de datos leidas
        //todas las demas son double
//coeficientes de realcion
double xk;
double r;
double r2;
//parametros de regresion lineal
double b0;
double b1;
//prediccion mejorada
double yk; //= Bo + B1*XK
double sig; //significancia      //unico con 10 decimales
double ran; //rango
double LS;  //Limite superior UPI in english
double LI;  //Limite inferior LPI  "   //min value is 0

double xProm;
//double yProm;

//vamos a utilizar las clases que hicimos para el 3
//los vectores

string nombreArch;
vector<Punto> puntos;
bool error = false;

//significance

/*


x = (abs(Rxy)*(n-2)^(1/2))/(1-rxy^2)^(1/2)
//rxy correlation
n was datapoints


*/

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

void leerArchivo(string nombreArch){
    ifstream file;
    file.open(nombreArch);

    string line;
    getline(file, line);
    //la linea a entero
    xk = stod(line);
    //int xk = stoi(line);

    //vector<Punto> puntos;
    //int n =0 ;
    //error cuando xk sea negativo
    if(xk<0){
        cout<<"Error, el xk es < a 0 "<<endl;
        error = true;
    }else{
        while(!file.eof()){
            //lees renglon y a decimales
            getline(file,line);
            double x = stod(line);
            //lookin for that comma
            int pos = line.find_first_of(",");
            //que agarre el sig caracter
            double y = stod(line.substr(pos+1));

            //puntos de verificacion de x Y y
            if(x<0){
                error = true;
                cout<<"Error X en numero "<<n<<" es menor a 0"<<endl;

            }
            if(y<0){
                error = true;
                cout<<"Error Y en numero "<<n<<" es menor a 0"<<endl;

            }

            Punto puntoTemporal = Punto(x,y);
            puntos.push_back(puntoTemporal);

            n++;
            //le vas sumando para ver cuantas ns hay denro delprograma

        }
        //hay datos?
        //ahora es menro igual a 3
        if(n<3){
            error = true;
            cout<<"Error, la N es menor a 3 "<<endl;

            //newArchivo(n,xk,puntos);

        }
        /*else{
        cout<<"Error, no hay n"<<endl;
        }*/
    }
    file.close();
}


void calculadora(){
double sumX = 0;
double sumY = 0;
double sumX2 =0;
double sumY2 =0;
double sumXY =0;


for (int i =0;i<n;i++){
    double x = puntos[i].getX();
    double y = puntos[i].getY();

    sumX +=x;
    sumY += y;
    sumX2+=x*x;
    sumY2+=y*y;
    sumXY+=x*y;
}

 xProm = sumX/n;
 double yProm = sumY/n;

//bq b0 r yk
 b1 =(sumXY-(n*xProm*yProm))/(sumX2 - (n*xProm*xProm));
 b0 =yProm-(b1*xProm);

 r = ((n*sumXY)-(sumX*sumY))/(sqrt( ((n*sumX2)-(sumX*sumX))*((n*sumY2)-(sumY*sumY)) ));

 yk = b0 +(b1*xk);


}

void calSig(){
    double xSig = abs(r)*sqrt(n-2)/sqrt(1-(r*r));
    double pNext= evalSimpson(xSig, n-2);
    sig = 1 - pNext*2;
}


double findX(int dof){ //evalX  int dof
    double p = .35;
    double trialX = 2;
    double dX = trialX/2;  //transform the D to a 1 to tart

    double pNext = evalSimpson(trialX, (int)dof);
    double pBefore = pNext;

    double dErr = .00000001;

    do{
        if((pNext > p && pBefore < p )|| (pNext<p && pBefore >p) ){
            dX /= 2; // transform the d from a 1 to a .5
        }
        pBefore = pNext;
        if(pBefore < p ){
            trialX += dX; //step number 3  if too low add add d = .5 to trial D
        } else{
        trialX -= dX; //if too high substract d=.5 from trialX
        }
        pNext = evalSimpson(trialX, (int)dof);

    }while( abs(pNext-pBefore)> dErr && pNext != p);

                //x = trialX;
    return trialX;

//things to keep in acccount ;
//if nextP >p and the one before is smaller

//el erorr aqui va a ser de .0000001

}


void range(){
    double sumXi_Xav2=0;
    double stdDev = 0;

    for (int i=0;i<n;i++){
        double x = puntos[i].getX();
        double y = puntos[i].getY();

        sumXi_Xav2 += pow((x-xProm),2);///////////////////////////////////
        stdDev += pow((y-b0- b1*x),2);
    }
    stdDev = sqrt(stdDev/(n-2));
    ran = findX(n-2)*stdDev*sqrt(1+1.0/n+(pow((xk-xProm),2)/sumXi_Xav2));


}

void imprimir(){
    //se va a cambiar la presision a 5 , no a 10
cout<<setprecision(5)<<fixed; //andresHal me enseño esto
//10 ceros      10000000000
cout<<"n    = "<<n<<endl;
cout<<"xk   = "<<round(xk*100000)/100000<<endl;
cout<<"r    = "<<round(r*100000)/100000<<endl;
cout<<"r2   = "<<round(r*r*100000)/100000<<endl;
cout<<"b0   = "<<round(b0*100000)/100000<<endl;
cout<<"b1   = "<<round(b1*100000)/100000<<endl;
cout<<"yk   = "<<round(yk*100000)/100000<<endl;
cout<<"sig  = "<<setprecision(10)<< round(sig*10000000000)/10000000000 << endl;
cout<<"ran  = "<<setprecision(5) << round(ran*100000)/100000 << endl;
cout<<"LS   = "<<round((yk+ran)*100000)/100000<<endl;
double li = yk - ran;
if(li <0){
    li = 0;}
cout<<"LI   = "<<round(li*100000)/100000<<endl;



//cout<<"p    = "<<round(p*100000)/100000<<endl;
//cout<<"dof  = "<<(int)dof<<endl;
//cout<<"x    = "<<round(x*100000)/100000 <<endl;
}

int main(){
    string nombreArch;
getline(cin, nombreArch);

if(validarArchivo(nombreArch)){
    leerArchivo(nombreArch);
}
    if(error != true)
    {
    calculadora();
    range();
    calSig();
    imprimir();
    return 0;
    }
}
