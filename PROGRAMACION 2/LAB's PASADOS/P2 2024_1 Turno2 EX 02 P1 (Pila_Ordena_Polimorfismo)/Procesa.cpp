/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Procesa.cpp
 * Author: Rosse
 * 
 * Created on 21 de noviembre de 2024, 10:52
 */

#include <iomanip>

#include "Procesa.h"
#include "Orden.h"

Procesa::Procesa() {

}

void Procesa::carga() {
    ifstream arch("Pedidos.csv");
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        class Orden *dato = new Orden (tipo);
        dato->Leer(arch);
        ppedidos.apilar(dato);
    }
}

void Procesa::Ordena() {
    Pila aux;
    while(!ppedidos.PilaVacia()){
        Orden *temp = ppedidos.Desapilar();
        while(!aux.PilaVacia() and *(aux.Cima()) > temp){
            Orden *cima = aux.Desapilar();
            ppedidos.apilar(cima);
        }
        aux.apilar(temp);
    }
    while(!aux.PilaVacia()){
        Orden *dato = aux.Desapilar();
        ppedidos.apilar(dato);
    }
}

void Procesa::Muestra() {
    ofstream arch ("ReporteOrdenado.txt");
    arch<<setprecision(2)<<fixed;
    ppedidos.Imprimir(arch);
}