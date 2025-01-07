/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Recojo.cpp
 * Author: Rosse
 * 
 * Created on 21 de noviembre de 2024, 10:39
 */

#include <cstring>

#include "Recojo.h"

Recojo::Recojo() {

}

Recojo::~Recojo() {

}

void Recojo::Leer(ifstream &arch) {
    Pedido::Leer(arch);
    char buff[50];
    arch.getline(buff,50,',');
    SetTienda(buff);
    arch>>dias;
    arch.get();
}

void Recojo::Imprimir(ofstream &arch) {
    arch<<"Tienda de Recojo: "<<Tienda<<endl;
    Pedido::Imprimir(arch);
}

void Recojo::SetDias(int dias) {
    this->dias = dias;
}

int Recojo::GetDias() const {
    return dias;
}

void Recojo::SetTienda(const char* Ti) {
    if (Tienda != nullptr) delete Tienda;
    Tienda = new char [strlen(Ti) + 1];
    strcpy(Tienda, Ti);
}

void Recojo::GetTienda(char *& cad) const {
    if (Tienda != nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(Tienda) + 1];
        strcpy(cad, Tienda);
    }
}