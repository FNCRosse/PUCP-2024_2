/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Procesa.cpp
 * Author: Rosse
 * 
 * Created on 21 de noviembre de 2024, 15:39
 */

#include "Procesa.h"

Procesa::Procesa() {

}

void Procesa::Carga() {
    ifstream arch ("Libros5.csv");
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        class Ejemplar * dato = new Ejemplar(tipo);
        dato->Leer(arch);
        porigen.Apilar(dato);
    }
}

void Procesa::Pasa() {
    Pila aux;
    while(!porigen.PilaVacia()){
        aux.Apilar(porigen.Desapilar());
    }
    while(!aux.PilaVacia()){
        pdestino.Apilar(aux.Desapilar());
    }
}

void Procesa::Muestra() {
    ofstream archO ("ReporteOrigen.txt");
    ofstream archD ("ReporteDestino.txt");
    porigen.Imprimir(archO);
    pdestino.Imprimir(archD);
}