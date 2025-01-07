/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 16:09
 */

#include "Lista.h"

Lista::Lista() {
    peso = 0.0;
    ini = nullptr;
}

Lista::~Lista() {
    eliminar();
    
}

void Lista::SetPeso(double peso) {
    this->peso = peso;
}

double Lista::GetPeso() const {
    return peso;
}

void Lista::Insertar(Nodo *dato) {
    if (ini == nullptr) {
        ini = dato;
    } else {
        Nodo *recorrido = ini;
        while (recorrido->sig != nullptr) {
            recorrido = recorrido->sig;
        }
        recorrido->sig = dato;
    }
    SetPeso(peso + dato->GetPeso());
}

void Lista::imprimir(ofstream &arch) {
    class Nodo *recorrido = ini;
    while (recorrido != nullptr) {
        recorrido->ImprimeDato(arch);
        recorrido = recorrido->sig;
    }
}

void Lista::eliminar() {

}
void Lista::Actualizar() {
    class Nodo *recorrido = ini;
    while (recorrido != nullptr) {
        recorrido->plibro->actualiza();
        recorrido = recorrido->sig;
    }
}

bool Lista::VerificarPeso(double capa, Nodo *dato) {
    if (peso + dato->GetPeso() <= capa) return true;
    else return false;
}