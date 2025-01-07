/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Rosse
 * 
 * Created on 6 de noviembre de 2024, 15:52
 */

#include <cstring>

#include "Pedido.h"

Pedido::Pedido() {
    codigo = nullptr;
    estado = nullptr;
    total = 0;
}

Pedido::~Pedido() {
    if (codigo != nullptr) delete codigo;
    if (estado != nullptr) delete estado;
}

Pedido::Pedido(const Pedido &ped) {
    codigo = nullptr;
    estado = nullptr;
    *this = ped;
}

void Pedido::Lee(ifstream &arch) {
    char buff[100],aa,mm,dd,c;
    arch.getline(buff,100,',');
    if(arch.eof()) return;
    SetCodigo(buff);
    arch>>dni_cliente;
    arch.get();
    arch>>subtotal;
    arch.get();
    arch>>aa>>c>>mm>>c>>dd>>c;
    fecha = aa*10000+mm*100*dd;
}

void Pedido::imprime(ofstream &arch) {
    
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetEstado(const char* est) {
    if (estado != nullptr) delete estado;
    estado = new char [strlen(est) + 1];
    strcpy(estado, est);
}

void Pedido::GetEstado(char *& cad) const {
    if (estado == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(estado) + 1];
        strcpy(cad, estado);
    }
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetSubtotal(double subtotal) {
    this->subtotal = subtotal;
}

double Pedido::GetSubtotal() const {
    return subtotal;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(const char* cod) {
    if (codigo != nullptr) delete codigo;
    codigo = new char [strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Pedido::GetCodigo(char *& cad) const {
    if (codigo == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(codigo) + 1];
        strcpy(cad, codigo);
    }
}