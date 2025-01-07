/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 20:30
 */

#include "Lista.h"

Lista::Lista() {
    lfin = nullptr;
    lini = nullptr;
}

Lista::~Lista() {
    if(lfin != nullptr) delete lfin;
    if(lini != nullptr) delete lini;
}

void Lista::Insertar(Nodo *dato) {
    if (lini == nullptr) { // Lista vacía
        lini = dato;
        lfin = dato;
    } else {
        Nodo *rec = lini, *ant = nullptr;
        while (rec != nullptr) {
            if (rec->ped->GetDni() < dato->ped->GetDni() or
               (rec->ped->GetDni() == dato->ped->GetDni() and rec->ped->GetFecha() < dato->ped->GetFecha())) {
                break;
            }
            ant = rec;
            rec = rec->sig;
        }
        dato->sig = rec;
        if (rec != nullptr) rec->ant = dato;
        if (ant != nullptr) {
            ant->sig = dato;
            dato->ant = ant;
        } else 
            lini = dato; 
        if (dato->sig == nullptr) lfin = dato;
    }
}

void Lista::Imprimir(ofstream &arch) {
    Nodo *recorrido = lini;
    while(recorrido){
        recorrido->ped->imprime(arch);
        recorrido = recorrido->sig;
    }
}
void Lista::LeerDato(ifstream &arch,int codigo){
    Nodo *dato = new Nodo (codigo);
    dato->ped->SetCodigo(codigo);
    dato->Leer(arch);
    Insertar(dato);
}
void Lista::Actualizar(int dniC, int fechaC){
    Nodo *recorrido = lfin;
    while(recorrido){
        if(recorrido->ped->GetDni() == dniC and recorrido->ped->GetFecha() < fechaC)
            recorrido->ped->Actualiza();
        recorrido = recorrido->ant;
    }
}