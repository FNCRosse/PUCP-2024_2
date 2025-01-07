/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Almacen.cpp
 * Author: Rosse
 * 
 * Created on 6 de noviembre de 2024, 16:40
 */

#include "Almacen.h"

Almacen::Almacen() {
    cantidas_ordenes  =0;
}

void Almacen::cargar_pedidos() {
    ifstream arch ("Pedidos.csv");
    char tipo;
    OrdenVenta orden;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        orden.AsignarPrioridad(tipo);
        orden.Leer(arch);
        ordenes[cantidas_ordenes] = orden;
        cantidas_ordenes++;
    }
}

void Almacen::actualizar_pedidos() {
    for(int i=0;i<cantidas_ordenes;i++){
        ordenes[i].ActualizarOrden();
    }
}

void Almacen::imprimir_ordenes_venta() {

}