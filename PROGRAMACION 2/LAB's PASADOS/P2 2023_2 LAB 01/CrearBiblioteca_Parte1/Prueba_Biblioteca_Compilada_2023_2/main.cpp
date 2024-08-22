/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 22 de agosto de 2024, 08:17
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "OpSobreCargados.h"

int main(int argc, char** argv) {
    ifstream archC,archPro,archPed;
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaLeer(archC,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPro,"Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,"Prueba FINAAAL 2023_2 LAB1.txt");
   
    //LECTURA
    struct Cliente arrCli[10];
    struct Producto arrPro[10];
    for(int i=0; i<5;i++) archC>>arrCli[i];
    for(int i=0; i<5;i++) archPro>>arrPro[i];
    arrCli[5].dni =0;
    strcpy(arrPro[5].codigo,"XXXXXXX");
    
    //AGREGACION
    struct Pedido ped;
    for(int i=0;i<5;i++){
        archPed>>ped;
        if(arrPro+=ped) arrCli += ped;
    }
    
    //iMPRESION
    archRep.precision(2);
    archRep<<fixed;
    archRep<<right<<setw(30)<<"LISTADO DE CLIENTES"<<left<<endl;
    for(int i=0;arrCli[i].dni !=0;i++) archRep<<arrCli[i];
    archRep<<endl<<endl;
    archRep<<right<<setw(30)<<"LISTADO DE PRODUCTOS"<<left<<endl;
    for(int i=0; strcmp(arrPro[i].codigo,"XXXXXXX")!=0;i++) archRep<<arrPro[i];
    return 0;
}

