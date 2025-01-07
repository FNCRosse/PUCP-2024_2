/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NPedido.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 14:49
 */

#include <cstring>
#include <iomanip>

#include "NPedido.h"

NPedido::NPedido() {
    codigo = nullptr;
}

NPedido::NPedido(const NPedido &ped) {
    SetCodigo(ped.codigo);
    this->cantidad = ped.cantidad;
    this->peso = ped.peso;
}

NPedido::~NPedido() {
    if (codigo != nullptr) delete codigo;
}

void NPedido::Leer(ifstream &arch) {
    char buff[10];
    arch.getline(buff, 10, ',');
    SetCodigo(buff);
    arch>>cantidad;
    arch.get();
    arch>>peso;
    arch.get();
}

void NPedido::Imprimir(ofstream &arch) {
    arch << left << setw(10) << codigo << right << setw(5) << cantidad << setw(10) << peso << endl;
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(const char* cod) {
    if (codigo != nullptr) delete codigo;
    codigo = new char [strlen(cod) + 1];
    strcpy(codigo, cod);
}

char* NPedido::GetCodigo() const {
    return codigo;
}