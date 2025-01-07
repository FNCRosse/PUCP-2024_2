/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PrioridadAlta.cpp
 * Author: Rosse
 * 
 * Created on 6 de noviembre de 2024, 16:05
 */

#include "PrioridadAlta.h"
#include "Pedido.h"

PrioridadAlta::PrioridadAlta() {
    total = 0;
}

PrioridadAlta::~PrioridadAlta() {

}

PrioridadAlta::PrioridadAlta(const PrioridadAlta & prAlta) {
    *this = prAlta;
}
//A,YYK-309,22777006,69.37,2023-11-11,7
void PrioridadAlta::Lee(ifstream &arch) {
    Pedido::Lee(arch);
    arch>>recargo;
    arch.get();
}

void PrioridadAlta::imprime(ofstream &arch) {
    Pedido::imprime(arch);
}

void PrioridadAlta::SetTotal(double total) {
    this->total = total;
}

double PrioridadAlta::GetTotal() const {
    return total;
}

void PrioridadAlta::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double PrioridadAlta::GetRecargo() const {
    return recargo;
}