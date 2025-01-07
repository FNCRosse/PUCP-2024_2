/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NVehiculo.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 15:13
 */

#include "NVehiculo.h"
#include "Furgon.h"
#include "Camion.h"

NVehiculo::NVehiculo() {

}

NVehiculo::~NVehiculo() {

}

void NVehiculo::AsignarTipo(char tipo) {
    switch(tipo){
        case 'F':
            unidad = new Furgon;
            break;
        case 'C':
            unidad = new Camion;
            break;
    }
}

void NVehiculo::Leer(ifstream &arch) {
    unidad->Leer(arch);
}

void NVehiculo::Imprimir(ofstream &arch) {
    unidad->Imprimir(arch);
}
void NVehiculo::AgregarPedido(class NPedido &datoPed) {
    unidad->AgregarPedido(datoPed);
}
int NVehiculo::getCodigoCliente(){
    unidad->GetCliente();
}