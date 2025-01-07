/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PunterosFuncion2Examen01Pregunta02.cpp
 * Author: Rosse
 * 
 * Created on 24 de octubre de 2024, 15:07
 */
#include <iostream>
#include "PunterosFuncion2Examen01Pregunta02.h"
#include "ColaDoblementeEnlazada.h"
using namespace std;
enum Ranking {
    CAB, COLA, TOTAL
};

enum Nodo {
    DATO, DIREC
};

enum Direccion {
    SIG, ANT
};

void cargarRanking(void *&Ranking, void *(*crear)(void*), void *ventas) {
    void **ArrVentas = (void**) ventas;
    void *Registro;
    GenerarCola(Ranking);
    for (int i = 0; ArrVentas[i]; i++) {
        Registro = crear(ArrVentas[i]);
        Encolar(Ranking, Registro);
    }
}

void MuestraRanking(void *Ranking, void(*imprime)(ofstream &, void*), const char* namefile) {
    ofstream arch(namefile);
    void **Cola = (void **) Ranking;
    void **Recorrer = (void **) Cola[CAB];
    while (not EsColaVacia(Recorrer)) {
        imprime(arch,Recorrer[DATO]);
        void **DirecNodo = (void **) Recorrer[DIREC];
        Recorrer = (void **) DirecNodo[SIG];
    }
}