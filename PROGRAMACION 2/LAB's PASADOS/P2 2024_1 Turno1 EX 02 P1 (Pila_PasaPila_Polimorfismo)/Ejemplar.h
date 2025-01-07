/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Ejemplar.h
 * Author: Rosse
 *
 * Created on 21 de noviembre de 2024, 15:33
 */

#ifndef EJEMPLAR_H
#define EJEMPLAR_H
#include "Libro.h"
class Ejemplar{
private:
    class Libro *plibro;
    class Ejemplar *sig;
public:
    Ejemplar();
    Ejemplar(char Tipo);
    ~Ejemplar();
    
    void Leer(ifstream &arch);
    
    friend class Pila;
};
#endif /* EJEMPLAR_H */
