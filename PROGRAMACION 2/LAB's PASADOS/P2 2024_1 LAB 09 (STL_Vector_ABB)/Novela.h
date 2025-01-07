/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Novela.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 12:08
 */

#ifndef NOVELA_H
#define NOVELA_H
#include "Libro.h"

class Novela : public Libro {
private:
    char *autor;
public:
    Novela();
    ~Novela();
    void SetAutor(const char* autor);
    char* GetAutor() const;
    
    void Leer(ifstream &arch);
    void Imprime(ofstream &arch);
};
#endif /* NOVELA_H */
