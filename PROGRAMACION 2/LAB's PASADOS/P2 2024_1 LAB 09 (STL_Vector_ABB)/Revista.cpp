/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Revista.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 12:11
 */

#include <iomanip>

#include "Revista.h"

Revista::Revista(){
    
}

Revista::~Revista(){
    
}
void Revista :: Leer(ifstream &arch) {
    Libro::Leer(arch);
    arch>>ISSN;
    arch.get();
    arch>>anho;
    arch.get();
    arch>>numero;
    arch.get();
}

void Revista ::Imprime(ofstream &arch) {
    Libro::Imprime(arch);
    arch<<"SKU: "<<left<<setw(10)<<ISSN<<"Ano: "<<anho<<endl<<endl;
}
void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}

void Revista::SetISSN(int ISSN) {
    this->ISSN = ISSN;
}

int Revista::GetISSN() const {
    return ISSN;
}