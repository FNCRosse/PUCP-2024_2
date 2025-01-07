/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 20:30
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
class Lista{
private:
    class Nodo *lini;
    class Nodo *lfin;
public:
    Lista();
    ~Lista();
    void Insertar(Nodo *dato);
    void Imprimir(ofstream &arch);
    void LeerDato(ifstream &arch,int );
    void Actualizar(int dniC, int fechaC);
};
#endif /* LISTA_H */
