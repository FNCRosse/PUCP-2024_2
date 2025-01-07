/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Furgon.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 15:08
 */

#ifndef FURGON_H
#define FURGON_H
#include "Vehiculo.h"
#include "NPedido.h"
#include <list>

class Furgon : public Vehiculo {
private:
    int filas;
    int puertas;
    list<class NPedido> pdeposito;
public:
    Furgon();
    ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;

    void Leer(ifstream &arch);
    void Imprimir(ofstream &arch);
    void AgregarPedido(class NPedido &datoPed);
};
#endif /* FURGON_H */
