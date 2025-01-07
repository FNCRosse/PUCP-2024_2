/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Camion.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 15:01
 */

#ifndef CAMION_H
#define CAMION_H
#include "Vehiculo.h"
#include "NPedido.h"
#include <map>

class Camion : public Vehiculo {
private:
    int ejes;
    int llanta;
    map<int, class NPedido> mdeposito;
public:
    Camion();
    ~Camion();
    void SetLlanta(int llanta);
    int GetLlanta() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    
    void Leer(ifstream &arch);
    void Imprimir(ofstream &arch);
    void AgregarPedido(class NPedido &datoPed);
};
#endif /* CAMION_H */
