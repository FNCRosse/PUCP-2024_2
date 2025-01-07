/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Almacen.h
 * Author: Rosse
 *
 * Created on 6 de noviembre de 2024, 16:40
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include "OrdenVenta.h"
class Almacen{
private:
    class OrdenVenta ordenes[600];
    int cantidas_ordenes;
public:
    Almacen();
    void cargar_pedidos();
    void actualizar_pedidos();
    void imprimir_ordenes_venta();
};
#endif /* ALMACEN_H */
