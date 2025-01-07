/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 12:33
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {

}

void Arbol::insertar(class NEstante &est) {
    class NEstante *dato = new NEstante(est);
    InsertarRec(raiz, dato);
}

void Arbol::Imprime(ofstream &arch) {
    ImprimeRec(raiz, arch);
}

void Arbol::InsertarRec(class NEstante *&ra, class NEstante *dato) {
    if (ra == nullptr) {
        ra = dato;
    } else if (ra->disponible > dato->disponible)
        InsertarRec(ra->izq, dato);
    else
        InsertarRec(ra->der, dato);
}

void Arbol::ImprimeRec(class NEstante *ra, ofstream &arch) {
    if (ra == nullptr) return;
    ImprimeRec(ra->izq, arch);
    ra->ImprimeEstante(arch);
    ImprimeRec(ra->der, arch);
}

void Arbol::PruebaPeso(double peso,ofstream &arch) {
    if(PruebaRec(raiz,peso)){
        arch<<"Si hay Espacio"<<endl;
        ImprimePruebaRec(raiz,arch,peso);
    }else arch<<"No hay Espacio";
}

void Arbol::ImprimePruebaRec(class NEstante *ra, ofstream &arch, double peso) {
    if (ra == nullptr) return;
    ImprimePruebaRec(ra->izq, arch,peso);
    if(ra->disponible >= peso)
        ra->ImprimeEstante(arch);
    ImprimePruebaRec(ra->der, arch,peso);
}

bool Arbol::PruebaRec(class NEstante *ra, double peso) {
    if (ra == nullptr) return false;
    PruebaRec(ra->izq, peso);
    if(ra->disponible >= peso) return true;
    PruebaRec(ra->der, peso);
}