#ifndef T_DIST_H_INCLUDED
#define T_DIST_H_INCLUDED

#include<iostream>
#include<cmath>

using namespace std;

const double PI = 3.141592653589793238462643;

//gamma recursive

double gammaFunc(double alfa){
if(alfa == 1){
    return 1;
}
if( alfa == .5){
    return pow(PI,.5);
}

    return ((alfa-1)*(gammaFunc(alfa-1)));
}

//distribucionT(x)
// x es valor DOF grados de libertad

double evalDistT(double x, int dof){
double expn;
expn = gammaFunc((dof+1)/2.0);
expn = expn/((pow((dof*PI),0.5))*gammaFunc(dof/2.0));
//revisalo bien
expn = expn*pow((1+(pow(x,2)/dof)),((dof+1)/-2.0));
return expn;

}

#endif // T_DIST_H_INCLUDED
