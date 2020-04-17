#ifndef REGRMULTIPLE_H_INCLUDED
#define REGRMULTIPLE_H_INCLUDED


#include<cmath>
#include<iomanip>
#include<vector>

#include"Datos.h"
#include"Gauss.h"

using namespace std;

class RegrMultiple{

private:
    int n;
    double b0;
    double b1;
    double b2;
    double b3;
    bool bError;
public:
    RegrMultiple(vector<Datos> datos);
    void display(double wk, double xk, double yk);


};

//.i
RegrMultiple::RegrMultiple(vector<Datos> datos){
    n = (int) datos.size();
    double sumaW = 0;
    double sumaX = 0;
    double sumaY = 0;
    double sumaZ = 0;
    double sumaW2 = 0;
    double sumaWX = 0;
    double sumaWY = 0;
    double sumaWZ = 0;
    double sumaX2 = 0;
    double sumaXY = 0;
    double sumaXZ = 0;
    double sumaY2 = 0;
    double sumaYZ = 0;

    for (int i = 0; i < n; i++){
        double tempW = datos[i].getW();
        double tempX = datos[i].getX();
        double tempY = datos[i].getY();
        double tempZ = datos[i].getZ();

        sumaW += tempW;
        sumaX += tempX;
        sumaY += tempY;
        sumaZ += tempZ;
        sumaW2 += tempW * tempW;
        sumaWX += tempW * tempX;
        sumaWY += tempW * tempY;
        sumaWZ += tempW * tempZ;
        sumaX2 += tempX * tempX;
        sumaXY += tempX * tempY;
        sumaXZ += tempX * tempZ;
        sumaY2 += tempY * tempY;
        sumaYZ += tempY * tempZ;
    }

    double matEcuacion[4][5] = {
        {(double)n, sumaW,sumaX,sumaY,sumaZ},
        {sumaW, sumaW2, sumaWX, sumaWY, sumaWZ},
        {sumaX, sumaWX, sumaX2, sumaXY, sumaXZ},
        {sumaY, sumaWY, sumaXY, sumaY2, sumaYZ}
        };//de la eq

    Gauss gauss = Gauss(matEcuacion);

    //traite los errores
    bError = gauss.getError();
    if(!bError){
        b0 = gauss.solveB0();
        b1 = gauss.solveB1();
        b2 = gauss.solveB2();
        b3 = gauss.solveB3();
    }



}


//.i
void RegrMultiple::display(double wk, double xk, double yk){
    //solucion es o unica o no
    if(bError){
        cout<<"Hubo un error, no hay solucion unica"<<endl;
    }else{

    cout<< setprecision(5)<<fixed;
    cout<<"N    = "<<n<<endl;
    cout<<"wk   = "<<round(wk*100000)/100000 <<endl;
    cout<<"xk   = "<<round(xk*100000)/100000 <<endl;
    cout<<"yk   = "<<round(yk*100000)/100000 <<endl;
    cout<<"--------------"<<endl;
    cout<<"bo   = "<<round(b0*100000)/100000 <<endl;
    cout<<"b1   = "<<round(b1*100000)/100000 <<endl;
    cout<<"b2   = "<<round(b2*100000)/100000 <<endl;
    cout<<"b3   = "<<round(b3*100000)/100000 <<endl;
    cout<<"--------------"<<endl;

    double zk = b0 + b1*wk + b2*xk + b3*yk;
    cout<<"zk   = "<<round(zk*100000)/100000 <<endl;

    }



}



#endif // REGRMULTIPLE_H_INCLUDED
