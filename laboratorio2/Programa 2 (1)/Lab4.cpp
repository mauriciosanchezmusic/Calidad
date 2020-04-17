

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

double x;
double dof;
double p;

//contorl de calidad que la informacion entro bien

bool bError(){
cout<<"Valores de X y DOF"<<endl;
cin>>x>>dof;

bool error = false;

if(x<0){
    error = true;
    cout<<"X debe ser >0"<<endl;
}
//int DOFtemporal = dof;
if (dof<=0){
        //DOFtemporal!=dof){
    error = true;
    cout<<"dof debe ser >0"<<endl;

}
return error;
}

void imprimir(){
cout<<setprecision(10)<<fixed; //andresHal me enseño esto
//10 ceros      10000000000
cout<<"r    = "<<round(x*10000000000)/10000000000 <<endl;
cout<<"dof  = "<<(int)dof<<endl;
cout<<"p    = "<<round(p*10000000000)/10000000000<<endl;
}

int main(){
if(!bError()){
    p = evalSimpson(x,(int)dof);
    imprimir();
}
return 0;
}
