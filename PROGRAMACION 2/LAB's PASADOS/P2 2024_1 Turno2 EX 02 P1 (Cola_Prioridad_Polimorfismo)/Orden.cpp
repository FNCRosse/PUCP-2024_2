/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Orden.cpp
 * Author: Rosse
 * 
 * Created on 21 de noviembre de 2024, 10:42
 */

#include "Orden.h"
#include "Envio.h"
#include "Recojo.h"

Orden::Orden() {
    sig = nullptr;
    pped = nullptr;
}

Orden::Orden(char tipo) {
    sig = nullptr;
    switch (tipo) {
        case 'E':
            pped = new Envio;
            break;
        case 'R':
            pped = new Recojo;
            break;
    }
}

Orden::~Orden() {

}

void Orden::Leer(ifstream &arch) {
    pped->Leer(arch);
}

void Orden::Imprimir(ofstream &arch) {
    pped->Imprimir(arch);
}