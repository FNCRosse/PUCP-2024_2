/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Nodo.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 16:05
 */

#include "Nodo.h"
#include "Enciclopedia.h"
#include "Revista.h"
#include "Novela.h"

Nodo::Nodo(){
    plibro = nullptr;
    sig = nullptr;
}

void Nodo::leerDato(ifstream &arch){
    plibro->lee(arch);
}
void Nodo::ImprimeDato(ofstream &arch){
    plibro->imprime(arch);
}
double Nodo::GetPeso(){
    return plibro->GetPeso();
}
Nodo::~Nodo(){
    if(plibro != nullptr) delete plibro;
    if(sig != nullptr) delete plibro;
}
void Nodo::AsignarTipo(char tipo){
    sig = nullptr;
    switch(tipo){
        case 'E':
            plibro = new Enciclopedia;
            break;
        case 'R':
            plibro = new Revista;
            break;
        case 'N':
            plibro = new Novela;
            break;
    }
}