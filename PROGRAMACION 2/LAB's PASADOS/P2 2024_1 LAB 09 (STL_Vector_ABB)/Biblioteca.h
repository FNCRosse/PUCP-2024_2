/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 12:44
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Arbol.h"
class Biblioteca{
private:
    class Arbol AEstante;
public:
    Biblioteca();
    void Carga();
    void Muestra();
    void Prueba(double peso);
};
#endif /* BIBLIOTECA_H */
