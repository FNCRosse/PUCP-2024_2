/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 15:37
 */

#include <cstring>

#include "Libro.h"

Libro::Libro() {
    nombre = nullptr;
}

Libro::~Libro() {
    if (nombre != nullptr) delete nombre;
}

Libro::Libro(const Libro &lib) {
    nombre = nullptr;
    *this = lib;
}

void Libro::lee(ifstream &arch) {
    char buff[100];
    arch.getline(buff,100,',');
    SetNombre(buff);
    arch>>paginas;
    arch.get();
    arch>>peso;
    arch.get();
}

void Libro::imprime(ofstream &arch) {
    arch<<"Titulo: "<<nombre<<endl;
    arch<<"Peso: "<<peso<<endl;
}

void Libro::actualiza() {

}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

void Libro::SetNombre(const char* nomb) {
    if (nombre != nullptr) delete nombre;
    nombre = new char [strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Libro::GetNombre(char *& cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(nombre) + 1];
        strcpy(cad, nombre);
    }
}