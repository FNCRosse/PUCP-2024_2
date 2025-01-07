/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 20:23
 */

#ifndef NODO_H
#define NODO_H
#include "Pedido.h"
#include "Lista.h"
class Nodo{
private:
    class Pedido *ped;
    class Nodo *sig;
    class Nodo *ant;
public:
    Nodo();
    Nodo(int codigo);
    ~Nodo();
    
    void imprime (ofstream &arch);
    void Leer (ifstream &arch);
    friend class Lista;
};
#endif /* NODO_H */
