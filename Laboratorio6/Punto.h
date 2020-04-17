#ifndef PUNTO_H_INCLUDED
#define PUNTO_H_INCLUDED

class Punto{
private:
    double x;
    double y;

public:
    Punto();
    Punto(double x, double y);
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
};
Punto::Punto(){
x=0;
y=0;
}
Punto::Punto(double x, double y){
    this-> x = x;
    this-> y = y;
    }
double Punto::getX(){
return x;}
double Punto::getY(){
return y;}
void Punto::setX(double x){
this-> x=x;}
void Punto:: setY(double y){

this->y =y;}
#endif // PUNTO_H_INCLUDED
