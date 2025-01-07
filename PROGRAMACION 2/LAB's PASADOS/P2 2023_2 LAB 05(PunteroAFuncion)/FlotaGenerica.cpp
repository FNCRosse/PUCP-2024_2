/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FlotaGenerica.cpp
 * Author: Rosse
 * 
 * Created on 24 de octubre de 2024, 09:57
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include "FlotaGenerica.h"
using namespace std;

void inicializarFlota(void *&Camion) {
    double *num = new double;
    *num = 0;
    void **Pila = new void*[2];
    Pila[0] = nullptr;
    Pila[1] = num;
    Camion = Pila;
}

void cargaCamiones(void *&flota, int numCamiones, int pesoMaximo, void *(*lee)(ifstream &),
        double (*calcula)(void *), const char *namefile) {
    ifstream arch(namefile);
    void **ArrFlota = new void *[numCamiones];
    for (int i = 0; i < numCamiones; i++) inicializarFlota(ArrFlota[i]);
    void *Dato;
    int NCam = 0;
    double PesoDato, PesoAcomulado;
    while (true) {
        Dato = lee(arch);
        if (arch.eof()) break;
        PesoDato = calcula(Dato);
        PesoAcomulado = ObtenerPesoAcomulado(ArrFlota[NCam]);
        if (PesoDato + PesoAcomulado > pesoMaximo) {
            NCam++;
            if (NCam == numCamiones) break;
        }
        Push(ArrFlota[NCam], Dato);
        ActualizarPeso(ArrFlota[NCam], PesoDato);
    }
    flota = ArrFlota;
}

bool EsPilaVacia(void *Pila) {
    if (Pila == nullptr) return true;
    return false;
}

void ActualizarPeso(void *Camion, double PesoDato) {
    void ** DatoPila = (void **) Camion;
    double * pesoCamion = (double*) DatoPila[1];
    *pesoCamion += PesoDato;
}

void Push(void *&Camion, void *Dato) {
    void **Pila = (void **) Camion;
    void **Nodo = new void *[2];
    Nodo[1] = Dato;
    Nodo[0] = nullptr;
    if (EsPilaVacia(Pila[0])) {
        Pila[0] = Nodo;
    } else {
        void ** ultimo = (void**)Pila[0];
        while (ultimo[0] !=nullptr) {
            ultimo = (void**) ultimo[0];
        }
        ultimo[0] = Nodo;
    }
}

double ObtenerPesoAcomulado(void *Camion) {
    void **Pila = (void **) Camion;
    return *(double*) Pila[1];
}

void muestraCamiones(void *flota, int numCamiones, void (*imprime)(ofstream &, void*), const char *namefile) {
    void **ArrFlota = (void **) flota;
    ofstream arch(namefile);
    for (int i = 0; i < numCamiones; i++) {
        void **Pila = (void **) ArrFlota[i];
        arch << right << "Camion  " << i + 1 << ": Peso: " << setw(10) << *(double*) Pila[1] << endl;
        void **nodo = (void **) Pila[0];
        while (nodo != nullptr) {
            imprime(arch, nodo[1]);
            nodo = (void**) nodo[0];
        }
    }
}