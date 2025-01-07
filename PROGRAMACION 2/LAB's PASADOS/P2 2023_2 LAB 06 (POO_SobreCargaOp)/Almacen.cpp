/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Almacen.cpp
 * Author: Rosse
 * 
 * Created on 28 de octubre de 2024, 19:24
 */

#include <cstring>

#include "Almacen.h"

Almacen::Almacen() {

}

void Almacen::SetCantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}

int Almacen::GetCantidad_productos() const {
    return cantidad_productos;
}

void Almacen::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::GetCantidad_clientes() const {
    return cantidad_clientes;
}

void Almacen::Carga_Cliente() {
    ifstream arch("Clientes.csv");
    cantidad_clientes = 0;
    while (arch >> arreglo_cliente[cantidad_clientes]) cantidad_clientes++;
}

void Almacen::Carga_productos() {
    ifstream arch("Productos.csv");
    cantidad_productos = 0;
    while (arch >> arreglo_producto[cantidad_productos]) cantidad_productos++;
}

void Almacen::Carga_Pedidos() {
    ifstream arch("Pedidos.csv");
    Pedido ped;
    while(arch>>ped){
        AtenderPedido(ped);
    }
}
void Almacen::AtenderPedido(Pedido &ped){
    for(int i=0;i<cantidad_clientes;i++){
        if(arreglo_cliente[i].GetDni() == ped.GetDni_cliente()){
            arreglo_cliente[i] += ped;
            break;
        }
    }
    for(int i=0;i<cantidad_productos;i++){
        char codPro[8], codPed[8];
        arreglo_producto[i].GetCodigo(codPro);
        ped.GetCodigo(codPed);
        if(strcmp(codPed,codPro) == 0){
            arreglo_producto[i] += ped;
            break;
        }
    }
}
void Almacen::Mostrar_Datos() {
    ofstream archCliente("Reporte_Cliente.txt");
    ofstream archPro("Reporte_Producto.txt");
    archCliente.precision(2);
    archCliente<<fixed;
    archPro.precision(2);
    archPro<<fixed;
    archCliente<<" REPORTE CLIENTES"<<endl;
    for(int i=0;i<cantidad_clientes;i++){
        archCliente<<arreglo_cliente[i];
    }
    archPro<<" REPORTE DE PRODUCTOS"<<endl;
    for(int i=0;i<cantidad_productos;i++){
        archPro<<arreglo_producto[i];
    }
}
