/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Camion.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 15:01
 */

#include <iomanip>

#include "Camion.h"

Camion::Camion(){
    
}
Camion::~Camion(){
    
}
void Camion::Leer(ifstream &arch) {
    Vehiculo::Leer(arch);
    arch>>ejes;
    arch.get();
    arch>>llanta;
    arch.get();
}

void Camion::Imprimir(ofstream &arch) {
    Vehiculo::Imprimir(arch);
    arch<<"#Ejes: "<<ejes<<endl;
    arch<<"#Llantas: "<<llanta<<endl;
    arch<<"Lista de Pedidos: "<<endl;
    if(!mdeposito.empty()){
        for(auto dato :mdeposito) {
            arch<<left<<setw(3)<<dato.first;
            dato.second.Imprimir(arch);
        }
        arch<<endl;
    } else arch<<"No hay pedidos"<<endl<<endl;
    
}
void Camion::AgregarPedido(class NPedido &datoPed) {
    double actualCarga = Vehiculo::GetActcarga();
    double MaxCarga = Vehiculo::GetMaxcarga();
    double peso = datoPed.GetPeso();
    if(actualCarga + peso <= MaxCarga and mdeposito.size()<= 5){
        mdeposito[mdeposito.size()] = datoPed;
        Vehiculo::SetActcarga(actualCarga + peso);
    }
}
void Camion::SetLlanta(int llanta) {
    this->llanta = llanta;
}

int Camion::GetLlanta() const {
    return llanta;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}