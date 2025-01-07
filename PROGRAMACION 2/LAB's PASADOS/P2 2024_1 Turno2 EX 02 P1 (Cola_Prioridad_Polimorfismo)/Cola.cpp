/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Cola.cpp
 * Author: Rosse
 * 
 * Created on 21 de noviembre de 2024, 12:30
 */

#include "Cola.h"
#include "Orden.h"

Cola::Cola() {
    pcima = nullptr;
    pcima = nullptr;
    nelementos = 0;
}

Cola::~Cola() {

}

void Cola::Encolar(class Orden *dato) {
    if (ColaVacia()) {
        pcima = dato;
        pcola = dato;
    } else {
        pcola->sig = dato;
        pcola = dato;
    }
    nelementos++;
}

void Cola::EncolarPorDNI(class Orden *dato) {
    int dniDato =dato->pped->GetDni();
    if (ColaVacia()) {
        pcima = dato;
        pcola = dato;
    } else if (dniDato >= 70000000) {
        pcola->sig = dato;
        pcola = dato;
    } else {
        Orden *rec = pcima,*ant =nullptr;
        while(rec){
            int dniRec = rec->pped->GetDni();
            if(((dniDato > 40000000 and dniDato < 70000000) and dniRec > 70000000 )
                    or(dniDato < 40000000 and dniRec > 40000000)) break;
            ant = rec;
            rec = rec->sig;
        }
        if(ant == nullptr){
            dato->sig =pcima;
            pcima = dato;
        } else{
            dato->sig = ant->sig;
            ant->sig = dato;
            if(dato->sig == nullptr) pcola = dato;
        }
    }
}

class Orden *Cola::Desencolar() {
    Orden *eliminar = pcima;
    pcima = pcima->sig;
    eliminar->sig = nullptr;
    nelementos--;
    return eliminar;
}

bool Cola::ColaVacia() {
    return pcima == nullptr;
}

void Cola::Imprimir(ofstream &arch) {
    Orden *recorrer = pcima;
    while (recorrer) {
        recorrer->Imprimir(arch);
        recorrer = recorrer->sig;
    }

}