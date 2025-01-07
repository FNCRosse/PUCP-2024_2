/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Envio.cpp
 * Author: Rosse
 * 
 * Created on 21 de noviembre de 2024, 10:35
 */

#include <cstring>

#include "Envio.h"
#include "Comunes.h"

Envio::Envio() {
    direccion = nullptr;
}

Envio::~Envio() {
    if (direccion != nullptr) delete direccion;
}

void Envio::Leer(ifstream &arch) {
    Pedido::Leer(arch);
    arch>>fecha;
    arch.get();
    char buff[100];
    arch.getline(buff,100,',');
    SetDireccion(buff);
    arch>>costo;
    arch.get();
}

void Envio::Imprimir(ofstream &arch) {
    arch<<"Direccion: "<<direccion<<endl;
    arch<<"Fecha Entrega: ";
    ImprimeFecha(fecha,arch);
    arch<<"  Costo: "<<costo<<endl;
    Pedido::Imprimir(arch);
}

void Envio::SetCosto(double costo) {
    this->costo = costo;
}

double Envio::GetCosto() const {
    return costo;
}

void Envio::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Envio::GetFecha() const {
    return fecha;
}

void Envio::SetDireccion(const char* dir) {
    if (direccion != nullptr) delete direccion;
    direccion = new char [strlen(dir) + 1];
    strcpy(direccion, dir);
}

void Envio::GetDireccion(char *& cad) const {
    if (direccion != nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(direccion) + 1];
        strcpy(cad, direccion);
    }
}