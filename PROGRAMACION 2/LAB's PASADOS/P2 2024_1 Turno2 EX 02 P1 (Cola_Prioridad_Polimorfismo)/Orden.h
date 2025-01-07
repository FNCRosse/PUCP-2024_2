/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Orden.h
 * Author: Rosse
 *
 * Created on 21 de noviembre de 2024, 10:42
 */

#ifndef ORDEN_H
#define ORDEN_H
#include "Pedido.h"
class Orden{
private:
    class Pedido *pped;
    class Orden *sig;
public:
    Orden();
    Orden(char tipo);
    ~Orden();
    
    void Leer(ifstream &arch);
    void Imprimir(ofstream &arch);
    
    friend class Cola;
};
#endif /* ORDEN_H */
