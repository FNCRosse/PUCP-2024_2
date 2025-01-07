/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Pila.h
 * Author: Rosse
 *
 * Created on 21 de noviembre de 2024, 10:46
 */

#ifndef PILA_H
#define PILA_H
#include "Orden.h"
class Pila{
private:
    int nelementos;
    class Orden *pcima;
public:
    Pila();
    ~Pila();
    void apilar(class Orden *dato);
    class Orden * Desapilar();
    bool PilaVacia();
    class Orden * Cima();
    void Imprimir(ofstream &arch);
};
#endif /* PILA_H */
