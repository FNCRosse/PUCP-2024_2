/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 12:04
 */

#include <iomanip>

#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {

}

Enciclopedia::~Enciclopedia() {

}

void Enciclopedia :: Leer(ifstream &arch) {
    Libro::Leer(arch);
    arch>>sku;
    arch.get();
    arch>>anho;
    arch.get();
}

void Enciclopedia ::Imprime(ofstream &arch) {
    Libro::Imprime(arch);
    arch<<"SKU: "<<left<<setw(10)<<sku<<"Ano: "<<anho<<endl<<endl;
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}
