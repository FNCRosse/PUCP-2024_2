/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PrioridadBaja.cpp
 * Author: Rosse
 * 
 * Created on 6 de noviembre de 2024, 16:22
 */

#include "PrioridadBaja.h"

PrioridadBaja::PrioridadBaja(){
    nueva_fecha_entrega = 0;
}
PrioridadBaja::~PrioridadBaja(){
    
}
PrioridadBaja::PrioridadBaja(const PrioridadBaja &prBaja){
    *this = prBaja;
}
void PrioridadBaja::Lee(ifstream &arch) {
    Pedido::Lee(arch);
    arch>>dias_espera;
    arch.get();
}

void PrioridadBaja::imprime(ofstream &arch) {
    Pedido::imprime(arch);
}
void PrioridadBaja::ActualizarOrden() {
    nueva_fecha_entrega = GetFecha() + dias_espera;
    SetFecha(nueva_fecha_entrega);
    SetTotal(GetTotal()+)
    
}
void PrioridadBaja::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadBaja::GetNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadBaja::SetDias_espera(int dias_espera) {
    this->dias_espera = dias_espera;
}

int PrioridadBaja::GetDias_espera() const {
    return dias_espera;
}