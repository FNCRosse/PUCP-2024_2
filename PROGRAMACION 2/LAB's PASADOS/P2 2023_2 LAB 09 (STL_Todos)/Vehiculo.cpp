/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 14:55
 */

#include <cstring>

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    actcarga =0;
    placa = nullptr;
}

Vehiculo::~Vehiculo() {
    if (placa != nullptr) delete placa;
}

void Vehiculo::Leer(ifstream &arch) {
    char buff[20];
    arch>>cliente;
    arch.get();
    arch.getline(buff, 20, ',');
    SetPlaca(buff);
    arch>>maxcarga;
    arch.get();
}

void Vehiculo::Imprimir(ofstream &arch) {
    arch <<"Codigo Cliente: "<<cliente<< endl;
    arch <<"Placa: "<<placa<< endl;
    arch <<"Carga Maxima: "<<maxcarga<< endl;
    arch <<"Carga Actual: "<<actcarga<< endl;
}
void Vehiculo::AgregarPedido(class NPedido &datoPed) {
    
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(const char* pla) {
    if (placa != nullptr) delete placa;
    placa = new char [strlen(pla) + 1];
    strcpy(placa, pla);
}

char* Vehiculo::GetPlaca() const {
    return placa;
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}