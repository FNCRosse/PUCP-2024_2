/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   OrdenVenta.h
 * Author: Rosse
 *
 * Created on 6 de noviembre de 2024, 16:35
 */

#ifndef ORDENVENTA_H
#define ORDENVENTA_H
#include "Pedido.h"
class OrdenVenta{
private:
    class Pedido *ptr_Orden;
public:
    OrdenVenta();
    ~OrdenVenta();
    OrdenVenta(const OrdenVenta &);
    void AsignarPrioridad(char tipo);
    void Leer(ifstream &arch);
    void Imprime(ofstream &arch);
    void ActualizarOrden();
};
#endif /* ORDENVENTA_H */
