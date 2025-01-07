/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 17:33
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
using namespace std;

class Libro {
    string codigo;
    string titulo;
    string autor;
    string genero;
    string tema;
public:
    Libro();
    Libro(const Libro &);
    ~Libro();
    void SetTema(string tema);
    string GetTema() const;
    void SetGenero(string genero);
    string GetGenero() const;
    void SetAutor(string autor);
    string GetAutor() const;
    void SetTitulo(string titulo);
    string GetTitulo() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;

    void Leer(ifstream &arch);
    bool operator<(const Libro & lib)const ;
};
#endif /* LIBRO_H */
