#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED


class Datos{
private:
    double w;
    double x;
    double y;
    double z;

public:
    //Constr
    Datos();
    Datos(double w, double x, double y, double z);

    //getters
    double getW();
    double getX();
    double getY();
    double getZ();

    //setters
    void setX(double x);
    void setY(double y);

    //methods
};

Datos::Datos(){
    w=0;
    x=0;
    y=0;
    z=0;
}


Datos::Datos(double w, double x, double y, double z){
    this ->w=w;
    this ->x=x;
    this ->y=y;
    this ->z=z;
}

double Datos::getW(){
    return w ;
}

double Datos::getX(){
    return  x;
}

double Datos::getY(){
    return  y;
}

double Datos::getZ(){
    return  z;
}

void Datos::setX(double x){
    this -> x = x;
}

void Datos::setY(double y){
    this -> y = y;
}


#endif // DATOS_H_INCLUDED
