/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Nodo.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 20:23
 */

#include "Nodo.h"
#include "PedidoEspecial.h"
#include "PedidoUsual.h"
#include "PedidoEventual.h"

Nodo::Nodo() {
    ped = nullptr;
    sig = nullptr;
    ant = nullptr;
}

Nodo::Nodo(int codigo) {
    if(codigo < 400000) {
        ped = new PedidoEspecial;
    } else if(codigo >= 400000 and codigo< 600000){
        ped = new PedidoUsual;
    } else{
        ped = new PedidoEventual;
    }
    sig = nullptr;
    ant = nullptr;
}

Nodo::~Nodo() {
   
}

void Nodo::imprime(ofstream &arch) {
    ped->imprime(arch);
}

void Nodo::Leer(ifstream &arch) {
    ped->lee(arch);
}