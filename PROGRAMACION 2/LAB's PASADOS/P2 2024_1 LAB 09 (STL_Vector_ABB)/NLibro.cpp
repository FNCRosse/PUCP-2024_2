/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NLibro.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 12:16
 */

#include "NLibro.h"
#include "Novela.h"
#include "Revista.h"
#include "Enciclopedia.h"

NLibro::NLibro() {
    pLibro = nullptr;
}

void NLibro::AsignarTipo(char tipo) {
    switch (tipo) {
        case 'N':
            pLibro = new Novela;
            break;
        case 'R':
            pLibro = new Revista;
            break;
        case 'E':
            pLibro = new Enciclopedia;
            break;
    }
}

NLibro::~NLibro() {

}

void NLibro::Leer(ifstream &arch) {
    pLibro->Leer(arch);
}

void NLibro::Imprime(ofstream &arch) {
    pLibro->Imprime(arch);
}
double  NLibro::getPeso(){
    return pLibro->GetPeso();
}