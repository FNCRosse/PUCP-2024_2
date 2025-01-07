/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Furgon.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 15:08
 */

#include "Furgon.h"

Furgon::Furgon() {

}

Furgon::~Furgon() {

}

void Furgon::Leer(ifstream &arch) {
    Vehiculo::Leer(arch);
    arch>>filas;
    arch.get();
    arch>>puertas;
    arch.get();
}

void Furgon::Imprimir(ofstream &arch) {
    Vehiculo::Imprimir(arch);
    arch << "#Filas: " << filas << endl;
    arch << "#Puertas: " << puertas << endl;
    arch << "Lista de Pedidos: " << endl;
    if (!pdeposito.empty()) {
        for (class NPedido ped:pdeposito){
            ped.Imprimir(arch);
        }
        arch<<endl;
    } else arch << "No hay pedidos" << endl << endl;
}
void Furgon::AgregarPedido(class NPedido &datoPed) {
    double actualCarga = Vehiculo::GetActcarga();
    double MaxCarga = Vehiculo::GetMaxcarga();
    double peso = datoPed.GetPeso();
    if(actualCarga + peso <= MaxCarga){
        pdeposito.push_front(datoPed);
        Vehiculo::SetActcarga(actualCarga + peso);
    }
}
void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}