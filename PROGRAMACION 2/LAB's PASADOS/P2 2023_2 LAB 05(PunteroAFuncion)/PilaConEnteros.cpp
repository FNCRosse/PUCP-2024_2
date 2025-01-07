/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PilaConEnteros.cpp
 * Author: Rosse
 * 
 * Created on 24 de octubre de 2024, 09:57
 */

#include "PilaConEnteros.h"
void *leeNumero(ifstream &arch){
    double *num = new double ;
    arch>>*num;
    return num;
}
double calculaNumero(void *dato){
    return *(double*)dato;
}
int cmpNumero(const void *a,const void *b){
     void **AuxA = (void**)a, **AuxB = (void**)b;
    void **ListaA = (void**)(*AuxA), **ListaB = (void**)(*AuxB);
    double* PesoA = (double*)(ListaA[1]), *PesoB = (double*)(ListaB[1]);
    return *PesoB - *PesoA;
}
void imprimenumero(ofstream &arch, void *Camion){
    if(Camion == nullptr) return;
    arch<<*(double*)Camion<<endl;
}