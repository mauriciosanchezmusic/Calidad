#ifndef SIMPSON_H_INCLUDED
#define SIMPSON_H_INCLUDED

#include<iostream>
#include"T_dist.h"

using namespace std;

//p calculado con simpson
//x rango de eval, def grad de libertad
// numseg  es canitdad de segmentos

double evalP(double x, int dof, int numSeg){
    //x para cada intervalo
    double w = x/(double)numSeg;
    double suma = 0;
    //sumas evaluados en W


    for(int cont=0 ; cont <= numSeg ; cont++){
        double funx = evalDistT((w*cont),dof);

        if(cont==0||cont==numSeg){
            suma += funx;
        }else if( cont%2 == 0){
            suma += funx*2;
        }else{
            suma +=funx*4;
            }
    }return((w/3)*suma);

}

// !dif > .0000001  (6 ceros )
double evalSimpson(double x, int dof){
int numSeg =10;
double error = .0000001;

//valor de p con simpson despues con
//doble de numero de segmentos
//mientras la dif enre las  p sea mayor al error
//sige doblando los segmentos
//hasta que tengas un error mas pequeño

double pOne = evalP(x,dof,numSeg);
numSeg *= 2;
double pNext = evalP(x,dof,numSeg);

while (abs(pNext-pOne)>error){
    pOne = pNext;
    numSeg *=2;
    pNext = evalP(x,dof,numSeg);
}
//hatsa que el error sea mas pequeño sale
return pNext;
}

#endif // SIMPSON_H_INCLUDED
