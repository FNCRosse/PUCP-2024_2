/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Rosse
 * 
 * Created on 28 de octubre de 2024, 19:23
 */

#include <cstring>

#include "Pedido.h"

Pedido::Pedido() {
    codigo = nullptr;
    precio_producto = 0;
}
bool operator >> (ifstream &arch, Pedido &ped){
    char codProd[8];
    int dni;
    arch.getline(codProd,8,',');
    if(arch.eof()) return false;
    arch>> dni; arch.get();
    ped.SetCodigo(codProd);
    ped.SetDni_cliente(dni);
    return true;
}
void Pedido::SetPrecio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

double Pedido::GetPrecio_producto() const {
    return precio_producto;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(const char* cad) {
    if (codigo != nullptr) delete codigo;
    codigo = new char[strlen(cad) + 1];
    strcpy(codigo, cad);
}

void Pedido::GetCodigo(char* cad) const {
if (codigo == nullptr) cad[0] = 0;
    else strcpy(cad, codigo);
}