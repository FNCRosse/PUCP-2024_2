/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Autor.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 17:36
 */

#ifndef AUTOR_H
#define AUTOR_H
#include "Libro.h"
#include <list>
#include <vector>

class Autor{
private:
    string codigo;
    string nombre;
    list<class Libro> libros;
public:
    Autor();
    Autor(const Autor &);
    ~Autor();
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
    
    void Leer (ifstream &arch);
    void AgregarSusLibros(vector<class Libro> &libros);
};
#endif /* AUTOR_H */
