/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Revista.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 12:11
 */

#ifndef REVISTA_H
#define REVISTA_H
#include "Libro.h"

class Revista : public Libro {
private:
    int ISSN;
    int anho;
    int numero;
public:
    Revista();
    ~Revista();
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;

    void Leer(ifstream &arch);
    void Imprime(ofstream &arch);
};
#endif /* REVISTA_H */
