

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

using namespace std;


//vamos a utilziar las clases que hicimos para el programa 4
//reutilizarmeos la de simpson y la de t_dist


//la clase de t_dist no va a ser modificada
//la cllase de simpson tampoco va a ser modificada...

//la diferencia principal ser a que ;


                    //diferencia num1
//hay un detalle a la hora de introducirdatos, este no puede sr menor a 0
// y tampoco puede ser mayor a .5  - introducir dentro de el boleano de error


                    //diferencia numero 2
//vamos a tener que meter una funcino para evaluar la X


double x;
double dof;
double p;

//contorl de calidad que la informacion entro bien

bool bError(){
    //cambiar a p y dof
cout<<"Valores de P y DOF"<<endl;
cin>>p>>dof;

bool error = false;

if(p<0||p>.5){
    error = true;
    cout<<"0<=P<=.5    p no cumple con los parametros"<<endl;
}

//aqui cambiamos e introducimos el diferencial de 0<p<.5
//
//if(x<0){
//    error = true;
//    cout<<"X debe ser >0"<<endl;
//}
//int DOFtemporal = dof;
    if (dof<=0){
            //DOFtemporal!=dof){
        error = true;
        cout<<"dof debe ser >0"<<endl;

    }
    return error;
}

void imprimir(){
    //se va a cambiar la presision a 5 , no a 10
cout<<setprecision(5)<<fixed; //andresHal me enseño esto
//10 ceros      10000000000

cout<<"p    = "<<round(p*100000)/100000<<endl;
cout<<"dof  = "<<(int)dof<<endl;
cout<<"x    = "<<round(x*100000)/100000 <<endl;
}


//nuevaclase}
void findX(){
    double trialX = 2;
    double dX = trialX/2;  //transform the D to a 1 to tart

    double pNext = evalSimpson(trialX, (int)dof);
    double pBefore = pNext;

    double dErr = .0000001;

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
    x = trialX;


//things to keep in acccount ;
//if nextP >p and the one before is smaller

//el erorr aqui va a ser de .0000001

}


int main(){
if(!bError()){
    //p = evalSimpson(x,(int)dof);
    findX();
    imprimir();
}
return 0;
}
