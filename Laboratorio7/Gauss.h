#ifndef GAUSS_H_INCLUDED
#define GAUSS_H_INCLUDED


#include<cmath>

class Gauss{

private:
    double matrGauss[4][5];
    bool bError;

public:
    //constructor
    Gauss(double matEcuacion[4][5]);

    double solveB0();
    double solveB1();
    double solveB2();
    double solveB3();

    bool getError();
};

//.i
//Constructor

Gauss::Gauss(double matEcuasion[4][5]){
    bError = false;

    //rengoles contador
    int i = 0;
    //un control del numero de renglones
    int k = 4;

    while(i<k && !bError){
        int pivote = i;

        // mayor coeficiente absoluto para los otros renglones
        for(int j = i+1 ;j<k;j++){
            if(abs(matEcuasion[pivote][i])< abs(matEcuasion[j][i])){
                pivote = j;
            }
        }//del for


        //ahora toca el shift de los valores en renglones
        //el objetivo es dejar el el pivote en el renglon actual
        if(pivote != i){
            for(int columna = i ; columna <k+1 ;columna ++){
                double temporal = matEcuasion[i][columna];
                matEcuasion[i][columna] = matEcuasion[pivote][columna];
                matEcuasion[pivote][columna]=temporal;
            }
        }//del if

        double coeficiente = matEcuasion[i][i];

        //if coeficiente = 0 no existe solucino unica
        if(coeficiente == 0){
            bError = true;
        }else{

            //agarra todas las columnas dentro del renglon del pivote dividelas entre el coeficiente
            for(int columna = i ; columna <k+1; columna++){
                    matEcuasion[i][columna] /= coeficiente;
            }//for

            //ahora todos los demas renglones, agarra el coeficiente del renglon contador en la columna i
            for(int contador = i+1; contador<k;contador++){
                coeficiente =matEcuasion[contador][i];


                //las columnas
                //quitale al contador el coef* i contador
                for (int j = i; j<k+1; j++){
                    matEcuasion[contador][j] -= matEcuasion[i][j]*coeficiente;
                }

            }//for

        }//del else
        i++;
    } //este es el del while
    for (int i=0; i<k;i++){
        for(int j=0; j<k+1;j++){
            matrGauss[i][j] =  matEcuasion[i][j];
        }
    }

}

//.i
//Resuelve la matriz gausseana para el valor de B3
double Gauss::solveB3(){
    return matrGauss[3][4];
}



//Resuelve la matriz gausseana para el valor de B2

//.i
double Gauss::solveB2(){
    return matrGauss[2][4] - matrGauss[2][3] * solveB3();
}



//Resuelve la matriz gausseana para el valor de B1

//.i
double Gauss::solveB1(){
    return matrGauss[1][4] - matrGauss[1][3] * solveB3() -matrGauss[1][2] * solveB2();
}


//Resuelve la matriz gausseana para el valor de B0

//.i
double Gauss::solveB0(){
    return matrGauss[0][4] - matrGauss[0][3] * solveB3() -matrGauss[0][2] * solveB2() - matrGauss[0][1] * solveB1();
}



bool Gauss:: getError(){
return bError;
}


#endif // GAUSS_H_INCLUDED
