/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PrioridadMedia.cpp
 * Author: Rosse
 * 
 * Created on 6 de noviembre de 2024, 16:17
 */

#include <cstring>

#include "PrioridadMedia.h"


PrioridadMedia::PrioridadMedia(){
    Descripcion = nullptr;
}
PrioridadMedia::~PrioridadMedia(){
    if(Descripcion != nullptr) delete Descripcion;
}
PrioridadMedia::PrioridadMedia(const PrioridadMedia &prMedia){
    Descripcion = nullptr;
    *this = prMedia;
}
//M,CRU-009,50375303,49.38,2023-11-26,1
void PrioridadMedia::Lee(ifstream &arch) {
    Pedido::Lee(arch);
    int estado;
    arch>>estado;
    arch.get();
    if(estado == 1) SetDescripcion("ACTIVO");
    else SetDescripcion("INACTIVO");
}

void PrioridadMedia::imprime(ofstream &arch) {
    Pedido::imprime(arch);
}
void PrioridadMedia::SetNueva_fecha_Entrega(int nueva_fecha_Entrega) {
    this->nueva_fecha_Entrega = nueva_fecha_Entrega;
}

int PrioridadMedia::GetNueva_fecha_Entrega() const {
    return nueva_fecha_Entrega;
}

void PrioridadMedia::SetDescripcion(const char* Desc) {
    if (Descripcion != nullptr) delete Descripcion;
    Descripcion = new char [strlen(Desc) + 1];
    strcpy(Descripcion, Desc);
}

void PrioridadMedia::GetDescripcion(char *& cad) const {
    if (Descripcion == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(Descripcion) + 1];
        strcpy(cad, Descripcion);
    }
}
