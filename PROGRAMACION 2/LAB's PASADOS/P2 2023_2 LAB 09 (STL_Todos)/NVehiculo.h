/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NVehiculo.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 15:13
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H
#include "Vehiculo.h"
class NVehiculo{
private:
    class Vehiculo *unidad;
public:
    NVehiculo();
    ~NVehiculo();
    void AsignarTipo(char tipo);
    void Leer(ifstream &arch);
    void Imprimir(ofstream &arch);
    void AgregarPedido(class NPedido &datoPed);
    int getCodigoCliente();
};
#endif /* NVEHICULO_H */
