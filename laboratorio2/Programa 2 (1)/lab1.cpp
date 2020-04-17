// Ivan Escalante



#include<iostream>
#include<cstring>
#include<queue>
#include<string>
#include<stack>
#include<fstream>
#include<regex>
#include "LeerArchivo.h"
#include "Lineas.h"


using namespace std;


bool validarArchivo(string Archivo){
    ifstream file;
    file.open(Archivo);

    //aqui verificamos que efectivamente se abrio el archivo
    if(file.is_open()){
        //cout<<"si se abrio \n"<<endl;
        //vamos a ver si abre el primer caracter
        char test;
        file.get(test);
        //es el primer caracter el eof ?
        if(file.eof()){
            file.close();
            cout<<"El archivo : "<< Archivo<<" es un archivo vacio."<<endl;
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
    cout<<"ERROR 001: el archivo con nombre :''"<<Archivo<<"'' no pudo ser encontrado, favor de revisarlo."<<endl;
    return false;
    //en caso de que este vacio

}

Lineas cuentaLineas(string Archivo){
    ifstream file;
    file.open(Archivo);
    //expreciones regulares
    //https://www.computerhope.com/unix/regex-quickref.htm
    // \s* any number of whitespace characters
    //^(start of string) $(end of line)
    // "^(\\s) (<- whitespace) *(followed by) // (characters) (.r)    "
    regex expBlanco ("^(\\s)*$");//("^(\\s)")
    regex expComent ("^(\\s)*//(.r)*$");
    regex expComentAbrir("^(\\s)*/\\*(.)*$");
    regex expComentCerrar("^(.)*\\*/(\\s)*$");


    string line;
    //contadores
    int blanco = 0;
    int coment = 0;
    int code = 0;
    //cout<<"aqui va a empezar la chingadera"<<endl;
    do{
        getline(file,line); //por linea del archivo
        if(regex_match(line,expBlanco)){
            blanco++;
            //cout<<"blanco"<<endl;
        }else if(regex_match(line, expComent)){
        coment++;
        cout<<"comment"<<endl;
        }else if(regex_match(line, expComentAbrir)){
                 coment++;
                 //se abre el ciclo
                 do{
                    coment++;
                    getline(file,line);
                 }while(!regex_match(line,expComentCerrar));
        }else{
            code++;
        }
        //linea es blanco ? blanco : next ;
        //linea es comment (//) ? coment : next;
        //linea es commentabrir (/*) ? ciclo hasta cierre : next;
            //linea es commentcerrar (*/)? cerrar ciclo +coment : next;
        //linea es code

    }while(!file.eof());

    file.close();
    Lineas lineas(blanco, coment, code);
    return lineas;
}

int main(){
    string Archivo;
    getline(cin,Archivo);
    if(validarArchivo(Archivo)){
        Lineas lineas = cuentaLineas(Archivo);
        LeerArchivo leerArchivo(Archivo, lineas);
        leerArchivo.imprimirLA(); //creoq ue es imprimirLA


    }
    return 0;

}
