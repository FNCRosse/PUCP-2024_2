/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 12:33
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "NEstante.h"

class Arbol {
    class NEstante *raiz;
    void InsertarRec(class NEstante *&ra, class NEstante *dato);
    void ImprimeRec(class NEstante *ra, ofstream &arch);
    void ImprimePruebaRec(class NEstante *ra, ofstream &arch,double peso);
    bool PruebaRec(class NEstante *ra, double peso);
public:
    Arbol();
    ~Arbol();
    void insertar(class NEstante &est);
    void Imprime(ofstream &arch);
    void PruebaPeso(double peso,ofstream &arch);
};
#endif /* ARBOL_H */
