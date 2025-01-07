/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Novela.h
 * Author: Rosse
 *
 * Created on 21 de noviembre de 2024, 15:23
 */

#ifndef NOVELA_H
#define NOVELA_H
#include "Libro.h"

class Novela : public Libro {
private:
    char * Autor;
    char *Editorial;
public:
    Novela();
    ~Novela();
    void SetEditorial(const char* Editorial);
    void GetEditorial(char *&) const;
    void SetAutor(const char* Autor);
    void GetAutor(char *&) const;

    void Leer(ifstream &arch);
    void Imprimir(ofstream &arch);
};
#endif /* NOVELA_H */
