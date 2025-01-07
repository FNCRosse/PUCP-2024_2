/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Revista.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 15:58
 */

#include <iomanip>

#include "Revista.h"

Revista::Revista() {
    vigencia  =1;
}

Revista::~Revista() {

}

Revista::Revista(const Revista & rev) {

}

void Revista::lee(ifstream &arch) {
    Libro::lee(arch);
    arch>>ISSN;
    arch.get();
    arch>>anho;
    arch.get();
    arch>>numero;
    arch.get();
}

void Revista::imprime(ofstream &arch) {
    Libro::imprime(arch);
    arch << left << "ISSN: " << setw(6) << ISSN << "Año: " << setw(6) << anho << "Numero: " << setw(6)
            << numero <<"Vigencia: "<<vigencia<< endl << endl;
}
void Revista::actualiza(){
    if(anho <= 2020) vigencia = 0;
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

void Revista::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Revista::GetVigencia() const {
    return vigencia;
}