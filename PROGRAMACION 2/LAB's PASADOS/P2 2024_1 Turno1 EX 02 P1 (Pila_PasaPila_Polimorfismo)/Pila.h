/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Pila.h
 * Author: Rosse
 *
 * Created on 21 de noviembre de 2024, 15:36
 */

#ifndef PILA_H
#define PILA_H
#include "Ejemplar.h"
class Pila{
private:
    int nelementos;
    class Ejemplar *pcima;
public:
    Pila();
    void Apilar(class Ejemplar *dato);
    class Ejemplar * Desapilar();
    bool PilaVacia();
    void Imprimir(ofstream &);
};
#endif /* PILA_H */
