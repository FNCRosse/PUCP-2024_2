/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Pila.cpp
 * Author: Rosse
 * 
 * Created on 21 de noviembre de 2024, 10:46
 */

#include "Pila.h"

Pila::Pila() {
    pcima = nullptr;
    nelementos = 0;
}

Pila::~Pila() {

}

void Pila::apilar(class Orden *dato) {
    dato->sig = pcima;
    pcima = dato;
    nelementos++;
}

class Orden * Pila::Desapilar() {
    Orden *Eliminar = pcima;
    pcima = pcima->sig;
    Eliminar->sig = nullptr;
    nelementos--;
    return Eliminar;
}

bool Pila::PilaVacia() {
    if(pcima == nullptr) return true;
    else return false;
}

class Orden * Pila::Cima(){
    return pcima;
}

void Pila::Imprimir(ofstream &arch) {
    Orden *recorrido = pcima;
    while(recorrido){
        recorrido->Imprimir(arch);
        recorrido = recorrido->sig;
    }
}