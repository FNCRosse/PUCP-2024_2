/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Rosse
 * 
 * Created on 21 de noviembre de 2024, 10:33
 */

#include "Pedido.h"
#include "Comunes.h"

Pedido::Pedido() {
    monto = 0;
}

Pedido::~Pedido() {

}

void Pedido::Leer(ifstream &arch) {
    char c;
    arch>>fecha>>c>>dni>>c>>monto>>c;
}

void Pedido::Imprimir(ofstream &arch) {
    arch<<"Fecha Pedido:  ";
    ImprimeFecha(fecha,arch);
    arch<<"  DNI: "<<dni<<endl;
    arch<<"Monto del Pedido: "<<monto<<endl<<endl;
}

void Pedido::SetMonto(double monto) {
    this->monto = monto;
}

double Pedido::GetMonto() const {
    return monto;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}