/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Enciclopedia.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 12:04
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H
#include "Libro.h"

class Enciclopedia : public Libro {
private:
    int sku;
    int anho;
public:
    Enciclopedia();
    ~Enciclopedia();
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;

    void Leer(ifstream &arch);
    void Imprime(ofstream &arch);
};
#endif /* ENCICLOPEDIA_H */
