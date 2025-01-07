/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 16:05
 */

#ifndef NODO_H
#define NODO_H
#include "Libro.h"
#include "Lista.h"
class Nodo{
private:
    class Libro *plibro;
    class Nodo *sig;
public:
    Nodo();
    ~Nodo();
    
    void leerDato(ifstream &arch);
    void ImprimeDato(ofstream &arch);
    double GetPeso();
    void AsignarTipo(char tipo);
    
    friend class Lista;
};
#endif /* NODO_H */
