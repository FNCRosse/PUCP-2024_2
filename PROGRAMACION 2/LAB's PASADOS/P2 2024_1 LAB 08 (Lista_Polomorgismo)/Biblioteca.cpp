/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 16:33
 */

#include "Biblioteca.h"

Biblioteca::Biblioteca() {

}

void Biblioteca::Carga() {
    ifstream arch("Estantes2.csv");
    int nd = 0;
    while (true) {
        AEstante[nd].Leer(arch);
        if (arch.eof()) break;
        nd++;
    }
    AEstante[nd].SetId(0);
}

void Biblioteca::Llena() {
    ifstream arch("Libros3.csv");
    char tipo;
    while (true) {
        arch>>tipo;
        if (arch.eof()) break;
        arch.get();
        Nodo *dato = new Nodo;
        dato->AsignarTipo(tipo);
        dato->leerDato(arch);
        int posEstante = EstanteDisponible(dato);
        if (posEstante != -1) AEstante[posEstante].Insertar(dato);
        else delete dato;
    }
}

int Biblioteca::EstanteDisponible(Nodo *dato) {
    for (int i = 0; AEstante[i].GetId() != 0; i++) {
        if (AEstante[i].EspacioDisponible(dato)) return i;
    }
    return -1;
}

void Biblioteca::baja() {
    for (int i = 0; AEstante[i].GetId() != 0; i++) {
        AEstante[i].Actualizar();
    }
}

void Biblioteca::Muestra() {
    ofstream arch ("Reporte.txt");
    arch<<"Estante:"<<endl;
    for (int i = 0; AEstante[i].GetId() != 0; i++) {
        AEstante[i].Imprimir(arch);
    }
}