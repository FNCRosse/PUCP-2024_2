/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Ejemplar.cpp
 * Author: Rosse
 * 
 * Created on 21 de noviembre de 2024, 15:33
 */

#include "Ejemplar.h"
#include "Novela.h"
#include "Revista.h"

Ejemplar::Ejemplar(){
    sig = nullptr;
}
Ejemplar::Ejemplar(char tipo){
    sig = nullptr;
    switch(tipo){
        case 'N':
            plibro = new Novela;
            break;
        case 'R':
            plibro = new Revista;
            break;
    }
}
Ejemplar::~Ejemplar(){
    
}
void Ejemplar::Leer(ifstream &arch){
    plibro->Leer(arch);
}