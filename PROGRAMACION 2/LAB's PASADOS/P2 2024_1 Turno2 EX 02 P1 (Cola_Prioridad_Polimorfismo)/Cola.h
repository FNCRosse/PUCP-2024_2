/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Cola.h
 * Author: Rosse
 *
 * Created on 21 de noviembre de 2024, 12:29
 */

#ifndef COLA_H
#define COLA_H
#include "Pedido.h"
class Cola{
private:
    int nelementos;
    class Orden *pcima;
    class Orden *pcola;
public:
    Cola();
    ~Cola();
    void Encolar(class Orden *dato);
    void EncolarPorDNI(class Orden *dato);
    class Orden * Desencolar();
    bool ColaVacia();
    void Imprimir(ofstream &arch);
};
#endif /* COLA_H */
