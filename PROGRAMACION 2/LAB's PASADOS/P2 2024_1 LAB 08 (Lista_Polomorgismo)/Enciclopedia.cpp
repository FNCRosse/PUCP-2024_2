/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 15:45
 */

#include <iomanip>

#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    vegencia =1;
}

Enciclopedia::~Enciclopedia() {

}

Enciclopedia::Enciclopedia(const Enciclopedia & en) {

}

void Enciclopedia::lee(ifstream &arch) {
    Libro::lee(arch);
    arch>>sku;
    arch.get();
    arch>>anho;
    arch.get();
}

void Enciclopedia::imprime(ofstream &arch) {
    Libro::imprime(arch);
    arch<<left<<"SKU: "<<setw(6)<<sku<<"Año: "<<setw(6)<<anho<<"Vigencia: "<<vegencia<<endl<<endl;
}

void Enciclopedia::actualiza() {
    if(anho <= 2020) vegencia = 0;
}

void Enciclopedia::SetVegencia(int vegencia) {
    this->vegencia = vegencia;
}

int Enciclopedia::GetVegencia() const {
    return vegencia;
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