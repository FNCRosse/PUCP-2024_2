/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Pila.cpp
 * Author: Rosse
 * 
 * Created on 21 de noviembre de 2024, 15:36
 */

#include "Pila.h"

Pila::Pila() {
    pcima = nullptr;
    nelementos =0;
}

void Pila::Apilar(class Ejemplar *dato) {
    dato->sig = pcima;
    pcima = dato;
    nelementos++;
}

class Ejemplar *Pila:: Desapilar() {
    Ejemplar *eliminar = pcima;
    pcima = pcima->sig;
    eliminar->sig = nullptr;
    nelementos--;
    return eliminar;
}

bool Pila::PilaVacia() {
    return pcima == nullptr;
}
void Pila::Imprimir(ofstream &arch) {
    Ejemplar *rec = pcima;
    while(rec){
        rec->plibro->Imprimir(arch);
        rec = rec->sig;
    }
}