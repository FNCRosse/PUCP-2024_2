/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Almacen.h
 * Author: Rosse
 *
 * Created on 28 de octubre de 2024, 19:24
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include "Cliente.h"
#include "Producto.h"
class Almacen{
private:
    class Cliente arreglo_cliente[200];
    int cantidad_clientes;
    class Producto arreglo_producto[200];
    int cantidad_productos;
public:
    Almacen();
    void SetCantidad_productos(int cantidad_productos);
    int GetCantidad_productos() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
    
    void Carga_Cliente();
    void Carga_productos();
    void Carga_Pedidos();
    void AtenderPedido(Pedido &ped);
    void Mostrar_Datos();
};
#endif /* ALMACEN_H */
