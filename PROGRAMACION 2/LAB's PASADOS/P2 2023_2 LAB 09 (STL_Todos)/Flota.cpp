/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Flota.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 15:15
 */


#include <iomanip>

#include "Flota.h"
#include "NPedido.h"

Flota::Flota() {

}

bool Flota::compara(class NVehiculo &a, class NVehiculo &b) {
    return a.getCodigoCliente() < b.getCodigoCliente();
}

void Flota::CargaFlota() {
    ifstream arch("Vehiculos.csv");
    char tipo;
    class NVehiculo dato;
    while (true) {
        arch>>tipo;
        if (arch.eof()) break;
        arch.get();
        dato.AsignarTipo(tipo);
        dato.Leer(arch);
        vflota.push_back(dato);
    }
    sort(vflota.begin(),vflota.end(),compara);
}

void Flota::CargaPedido() {
    ifstream arch("Pedidos3.csv");
    int dniCliente;
    while (true) {
        class NPedido ped;
        arch>>dniCliente;
        if (arch.eof()) break;
        arch.get();
        int posCliente = BuscarCliente(dniCliente);
        if (posCliente != -1) {
            ped.Leer(arch);
            vflota[posCliente].AgregarPedido(ped);
        } else while (arch.get() != '\n');
    }
}

int Flota::BuscarCliente(int dniCliente) {
    for (int i = 0; i < vflota.size(); i++) {
        if (vflota[i].getCodigoCliente() == dniCliente) return i;
    }
    return -1;
}

void Flota::MuestraCarga() {
    ofstream arch("Reporte.txt");
    arch<<setprecision(2)<<fixed;
    for (class NVehiculo dato : vflota) {
        dato.Imprimir(arch);
    }
}