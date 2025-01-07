/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Novela.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 15:53
 */

#ifndef NOVELA_H
#define NOVELA_H
#include "Libro.h"

class Novela : public Libro {
private:
    char* Autor;
public:
    Novela();
    ~Novela();
    Novela(const Novela &);
    void SetAutor(const char* Autor);
    void GetAutor(char*&) const;

    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza();
};
#endif /* NOVELA_H */
