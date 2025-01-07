/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Rosse
 * 
 * Created on 30 de octubre de 2024, 17:10
 */

#include <cstring>
#include <iomanip>

#include "Libro.h"

Libro::Libro() {
    codigo = nullptr;
    nombre = nullptr;
    Colocado = false;
}

Libro::~Libro() {
    if (codigo != nullptr) delete codigo;
    if (nombre != nullptr) delete nombre;
}

Libro::Libro(char* cod, char* nomb, int an, int al, bool col) {
    SetAlto(al);
    SetAncho(an);
    SetCodigo(cod);
    SetColocado(col);
    SetNombre(nomb);
}

Libro::Libro(const Libro &lib) {
    SetAlto(lib.alto);
    SetAncho(lib.ancho);
    SetCodigo(lib.codigo);
    SetColocado(lib.Colocado);
    SetNombre(lib.nombre);
    
}

void Libro::Leer(ifstream &arch) {
    char Buff[100];
    arch.getline(Buff, 100, ',');
    if (arch.eof()) return;
    SetCodigo(Buff);
    arch.getline(Buff, 100, ',');
    SetNombre(Buff);
    arch>>ancho;
    arch.get();
    arch>>alto;
    arch.get();
}

void Libro::Imprimir(ofstream &arch) {
    arch << left << setw(12) << codigo << setw(55) << nombre << setw(10) << ancho << alto << endl;
}

void operator>>(ifstream &arch, Libro & lib) {
    lib.Leer(arch);
}

void operator<<(ofstream &arch, Libro & lib) {
    lib.Imprimir(arch);
}

void Libro::SetColocado(bool Colocado) {
    this->Colocado = Colocado;
}

bool Libro::IsColocado() const {
    return Colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(const char* nomb) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Libro::GetNombre(char*& cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else strcpy(cad, nombre);
}

void Libro::SetCodigo(const char* cod) {
    if (codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Libro::GetCodigo(char* &cad) const {
    if (codigo == nullptr) cad[0] = 0;
    else strcpy(codigo, cad);
}