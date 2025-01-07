/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PilaConRegistros.cpp
 * Author: Rosse
 * 
 * Created on 24 de octubre de 2024, 09:57
 */

#include <cstring>
#include <iomanip>

#include "PilaConRegistros.h"

enum Regis {
    COD, DNI, CANT, PESO
};

char *ConvertirCharPtr(char* cad) {
    char *ptr;
    ptr = new char[strlen(cad)];
    strcpy(ptr, cad);
    return ptr;
}

void *leeRegistro(ifstream &arch) {
    void **Registro = new void*[4];
    char codigo[8];
    int* dni = new int, *cantidad = new int;
    double *peso = new double;
    arch.getline(codigo, 8, ',');
    arch>>*dni;
    arch.get();
    arch>>*cantidad;
    arch.get();
    arch>>*peso;
    arch.get();
    Registro[COD] = ConvertirCharPtr(codigo);
    Registro[DNI] = dni;
    Registro[CANT] = cantidad;
    Registro[PESO] = peso;
    return Registro;
}

double calculaRegistro(void *Camion) {
    void **Datos = (void**)Camion;
    return *(double*)Datos[PESO];
}

int cmpRegistro(const void *a, const void *b) {
    void **AuxA = (void**) a, **AuxB = (void**) b;
    void **ListaA = (void**) (*AuxA), **ListaB = (void**) (*AuxB);
    double* PesoA = (double*) (ListaA[1]), *PesoB = (double*) (ListaB[1]);
    return *PesoB - *PesoA;
}

void imprimeRegistro(ofstream &arch, void *Camion) {
    void **Datos = (void**)Camion;
    arch<<right<<setw(14)<<(char*)Datos[COD]<<setw(6)<<*(int*)Datos[CANT]<<setw(8)
            <<*(double*)Datos[PESO]<<endl;
}