/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 16:09
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
class Lista{
private:
    double peso;
    class Nodo *ini;
public:
    Lista();
    ~Lista();
    void SetPeso(double peso);
    double GetPeso() const;
    void Insertar (Nodo *dato);
    void imprimir (ofstream &arch);
    void eliminar ();
    void Actualizar ();
    bool VerificarPeso(double capa, Nodo *dato);
};
#endif /* LISTA_H */
