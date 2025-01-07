/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   OrdenVenta.cpp
 * Author: Rosse
 * 
 * Created on 6 de noviembre de 2024, 16:35
 */

#include "OrdenVenta.h"
#include "PrioridadAlta.h"
#include "PrioridadMedia.h"
#include "PrioridadBaja.h"

OrdenVenta::OrdenVenta() {
    ptr_Orden = nullptr;
}

OrdenVenta::~OrdenVenta() {
    if (ptr_Orden != nullptr) delete ptr_Orden;
}

OrdenVenta::OrdenVenta(const OrdenVenta &orVenta) {
    ptr_Orden = nullptr;
    *this = orVenta;
}

void OrdenVenta::AsignarPrioridad(char tipo) {
    switch (tipo) {
        case 'A':
            ptr_Orden = new PrioridadAlta;
            break;
        case 'M':
            ptr_Orden = new PrioridadMedia;
            break;
        case 'B':
            ptr_Orden = new PrioridadBaja;
            break;
    }
}

void OrdenVenta::Leer(ifstream &arch) {
    ptr_Orden->Lee(arch);
}

void OrdenVenta::Imprime(ofstream &arch) {
    ptr_Orden->imprime(arch);
}
void OrdenVenta::ActualizarOrden() {
    ptr_Orden->ActualizarOrden();
}