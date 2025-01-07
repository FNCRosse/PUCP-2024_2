/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Registro.cpp
 * Author: Rosse
 * 
 * Created on 24 de octubre de 2024, 15:15
 */

#include <iomanip>
#include "Registro.h"

enum ventas {COD, NOMB, AT, ARREGLO, LIBVEN, SUMA, PROM, RANK};
enum registro {CODI,TITULO,AUTOR,RANKING,ARR};

void * crearRegistro(void *Libro) {
    void **DatosLib = (void**) Libro;
    void **Registro = new void *[5];
    int * rk = (int*) DatosLib[RANK];
    Registro[CODI] = (char*) DatosLib[COD];
    Registro[TITULO] = (char*) DatosLib[NOMB];
    Registro[AUTOR] = (char*) DatosLib[AT];
    Registro[RANKING] = rk;
    Registro[ARR] = (int *)DatosLib[ARREGLO];
    return Registro;
}

void imprimeRegistro(ofstream &arch, void *Libro) {
    void **DatosLib = (void**) Libro;
    arch << left << setw(12) << (char*) DatosLib[CODI] << (char*) DatosLib[TITULO] <<endl;
    arch << left << setw(12) << *(int*) DatosLib[RANKING] << (char*) DatosLib[AUTOR] <<endl;
    arch<<"DNI CLIENTES:"<<endl;
    int *Arrclientes =(int *)DatosLib[ARR];
    if(Arrclientes != nullptr){
        for(int i=0;Arrclientes[i];i++){
            arch<<setw(12)<<Arrclientes[i];
        }
    }
    arch<<endl<<endl;
}