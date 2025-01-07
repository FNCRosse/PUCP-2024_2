/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   biblioteca.h
 * Author: Rosse
 *
 * Created on 30 de octubre de 2024, 17:11
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Estante.h"
#include "Libro.h"
class Biblioteca{
private:
    class Estante estantes[10];
    int cantidad_estantes;
    class Libro libros[10];
    int cantidad_libros;
public:
    Biblioteca();
    void Carga_Libros();
    void Carga_Estantes();
    void Posicionar_Libros();
    void Mostrar_Datos();
};
#endif /* BIBLIOTECA_H */
