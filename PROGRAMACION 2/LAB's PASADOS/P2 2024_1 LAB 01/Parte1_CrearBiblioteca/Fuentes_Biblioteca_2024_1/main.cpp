/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 21 de agosto de 2024, 07:26
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "SobreCargaOperadores.h"

int main(int argc, char** argv) {
    ifstream archL,archC,archP;
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaLeer(archC,"Cientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archL,"Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archP,"Pedidos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,"Pruebaaa.txt");
    
    struct Libro arrLibro[5];
    struct Cliente arrCliente[5];
    
    //SobreCarga Lectura
    for(int i=0;i<3;i++) archL>>arrLibro[i];
    for(int i=0;i<3;i++) archC>>arrCliente[i];
    strcpy(arrLibro[3].codigo,"FIN");
    arrCliente[3].dni =0;
    
    //SobreCarga Operaciones
    struct LibroSolicitado libsol;
    int dni;
    char CodigoLibro[8];
    archP>>libsol.numeroDePedido;
    archP.get();
    archP>>dni;
    archP.get();
    for(int i=0;arrCliente[i].dni != 0;i++){
        int a = arrCliente[i].dni ;
        if(arrCliente[i].dni == dni){
            while(true){
                archP>>CodigoLibro;
                strcpy(libsol.codigoDelLibro,CodigoLibro);
                libsol >> arrLibro;
                arrCliente[i] << libsol;
                if(archP.get()  == '\n') break;
            }
            ++arrCliente[i];
        }else while(archP.get()!='\n');
    }
    
    //SobreCarga Impresion
    for(int i=0;strcmp(arrLibro[i].codigo,"FIN")!=0;i++) archRep<<arrLibro[i];
    archRep<<endl<<endl;
    for(int i=0;arrCliente[i].dni != 0;i++) archRep<<arrCliente[i];
    
    return 0;
}

