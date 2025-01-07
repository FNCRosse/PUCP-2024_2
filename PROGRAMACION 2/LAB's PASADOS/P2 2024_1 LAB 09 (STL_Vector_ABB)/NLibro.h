/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NLibro.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 12:16
 */

#ifndef NLIBRO_H
#define NLIBRO_H
#include "Libro.h"
class NLibro{
private:
    class Libro *pLibro;
public:
    NLibro();
    ~NLibro();
    
    void AsignarTipo(char tipo);
    void Leer(ifstream &arch);
    void Imprime(ofstream &arch);
    double  getPeso();
};
#endif /* NLIBRO_H */
