// Ivan Escalante



#include<iostream>
#include<cstring>
#include<queue>
#include<string>
#include<stack>
#include<fstream>
#include<regex>
#include<vector>

#include "LeerArchivo.h"
#include "Lineas.h"
#include "Build.h"


using namespace std;
vector<Build> build;

int iTotalLDC=0;


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

void cuentaLineas(string Archivo){
    ifstream file;
    file.open(Archivo);
    //expreciones regulares
    //https://www.computerhope.com/unix/regex-quickref.htm
    // \s* any number of whitespace characters
    //^(start of string) $(end of line)
    // "^(\\s) (<- whitespace) *(followed by) // (characters) (.r)    "
    regex expBlanco ("^(\\s)*$");//("^(\\s)")
    regex expComent ("^(\\s)*//(.)*$");
    regex expComentAbrir("^(\\s)*/\\*(.)*$");
    regex expComentCerrar("^(.)*\\*/(\\s)*$");
    //nuevas
    regex expLlaveAbrir ("^(\\s)*\\{(\\s)*$");
    regex expLlaveCerrar ("^(\\s)*};?(\\s)*$");
    regex expItem ("^(\\s)*//\\.i(\\s)*$");
    regex expModificados ("^(.)*//\\.m(\\s)*$");
    regex expBase ("^(\\s)*//\\.b=(.)*$");
    regex expBorrados ("^(\\s)*//\\.d=(.)*$");



    string line;
    //contadores viejos
   //int blanco = 0;
   // int coment = 0;
   // int code = 0;
    //do we really need the ones on the top ?

    int base = 0;           // \.b
    int borradas = 0;       // \.d
    int modificadas = 0;    // \.m
    int totales = 0;
    int items = 0;          // \.i
    do{
        getline(file,line); //por linea del archivo

        if(!regex_match(line,expBlanco) && !regex_match(line, expLlaveAbrir) && !regex_match(line,expLlaveCerrar) ){
            //cout<<"imin"<<endl;
            //blanco++;
            //cout<<"blanco"<<endl;
        if(regex_match(line, expComent)){
                //cout<<" -.-----------.--.-.-.-"<<endl;
              if(regex_match(line,expBase)){
                 int pos = line.find_first_of("1234567890");
                 base += stoi(line.substr(pos));
                 //cout<<"Base"<<endl;
              }else if (regex_match(line,expBorrados)){
                  int pos = line.find_first_of("1234567890");
                  borradas += stoi(line.substr(pos));
                  //cout<<"Borradas"<<endl;
              }else if(regex_match(line,expItem)){
                  items++;
                  //cout<<"Items"<<endl;
                  //int pos = line.find_first_of("1234567890");
              }else{
              }
        }//last line de regex_match(line, expComent)
        else if(regex_match(line,expComentAbrir)){
            while (!regex_match(line, expComentCerrar)){
                getline(file,line);
            }
        }else{
            totales++;
            iTotalLDC++;
            if (regex_match(line,expModificados)){
                modificadas++;
            }
            }
    }//aqui se termina el de triple comparison
    }while(!file.eof());

    file.close();
    //Lineas lineas(blanco, coment, code);
    //return lineas;

    //cout<<"Done with the file"<<endl;
    //cout<<"Hasta ahorita van ;;;"<<endl;
    //cout<<"-----------------------"<<endl;
    //cout<<"Lineas base;        "<<base<<endl;
    //cout<<"Lineas borraads;    "<<borradas<<endl;
    //cout<<"Lineas modificadas; "<<modificadas<<endl;
    //cout<<"Lineas items;       "<<items<<endl;
    //cout<<"-------------------------"<<endl;

    int agregadas = totales - base + borradas;
    //cout<<"Lineas agregadas ; "<<agregadas<<endl;
    //cout<<"-------------------------"<<endl;
    int iContador =0;
    bool found = false;
    //aqui necesito crear una clase vectorrr
    // el archivo aqui sera divirido por bloques en el aire divididos por los .'s
    //

    int iPunto = Archivo.find(".");
    string sBuild = Archivo.substr(0,iPunto);

    while(iContador< (int)build.size()&& !found){
        if(build[iContador].getName() == sBuild){
            found = true;
        }else{
        iContador++;
        }
    }

    //ocupo un auxiliar contador para hacer un ejercicio temporal

    Lineas lineasAux(base,borradas,modificadas,agregadas);
    if(found){
        build[iContador].sumaLineas(lineasAux);
        build[iContador].sumaItems(items);
    }else{
        Build buildAux(sBuild,items,lineasAux);
        build.push_back(buildAux);
    }
}

//intento de hacerlo con formato string
void imprimir(){

    bool error = false;
    //cout<<"Ya esta corriendo el imprimir--------"<<endl;
    string text = "PARTES BASE: \n";
    char type;
    for (int cont =0; cont < (int)build.size(); cont++){
        type = build[cont].getType();
        if (type == 'B'){
            text += build[cont].display(type);
            //cout<<"Entro tipo B"<<endl;
        }
    }
    //cout<<"---------------------checkpoint1--"<<endl;
    text += "-------------------------------------------- \n";
    text += "PARTES NUEVAS: \n";

    for( int i=0; i< (int)build.size() ; i++){
        type = build[i].getType();
        if(type=='N'){
                //cout<<"Entro tipo N"<<endl;
            text += build[i].display(type);
        }
    }
    text += "--------------------------------- \n";
    text += "PARTES REUSADAS: \n";
    for( int j =0 ; j <(int)build.size(); j++){
        type = build[j].getType();
        if(type == 'R'){

                cout<<"Entro tipo R            "<<endl;
            text += build[j].display(type);
        }else{
            if (type== 'E'){

            cout<<"Entro tipo E"<<endl;
                error = true;
            }
        }
    }
    //cout<<"---------------------checkpoin2--"<<endl;

    if(error){
        text += "--------------------------------- \n";
        text += " PARTES ERROR: \n";

        for( int x =0; x < (int)build.size() ; x++){
            type = build[x].getType();
            if(type == 'E'){
                text += build[x].display('B');
            }
        }
    }
    //cout<<"---------------------checkpoint4--"<<endl;

    text += "--------------------------------- \n";
    //text += " whahappen";
    text += "Total LDC = " + to_string(iTotalLDC);
    //cout<<"---------------------checkpoint5--"<<endl;
    cout<< text;
    //cout<<"---------------------checkpoint6--"<<endl;
    ofstream createFile;
    createFile.open("ConteoLDC.txt");
    createFile<<text;
    createFile.close();
    //cout<<"Ya se acabo el imprimir"<<endl;
}

int main(){
    string Archivo;
    getline(cin,Archivo);
    while(Archivo != "out"){
        if(validarArchivo(Archivo)){
            cuentaLineas(Archivo);
        }
        getline(cin,Archivo);
    }

    if(build.size() > 0){
        //cout<<"ahi va la impresion"<<endl;
        imprimir();
    //cout<<"aand its done"<<endl;
    }
    else{
        cout<<"Hay un error con el archivo o no fue introducido"<<endl;

    }
    //if(validarArchivo(Archivo)){
    //    Lineas lineas = cuentaLineas(Archivo);
    //    LeerArchivo leerArchivo(Archivo, lineas);
    //    leerArchivo.imprimirLA(); //creoq ue es imprimirLA



    //cout<<""<<endl;
    //int vacio=0;
    //cin>>vacio;
    return 0;


}
