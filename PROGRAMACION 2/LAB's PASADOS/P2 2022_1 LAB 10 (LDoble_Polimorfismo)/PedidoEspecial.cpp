/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PedidoEspecial.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 20:14
 */

#include <iomanip>

#include "PedidoEspecial.h"

PedidoEspecial::PedidoEspecial() {
    descuento = 0;
}

PedidoEspecial::~PedidoEspecial() {

}
void PedidoEspecial::Actualiza() {
    
}
void PedidoEspecial::lee(ifstream &arch) {
    arch>>descuento;
    arch.get();
    Pedido::lee(arch);
}

void PedidoEspecial::imprime(ofstream &arch) {
    Pedido::imprime(arch);
    arch<<"Descuento: "<<right<<setw(15)<<descuento<<"%"<<endl<<endl;
}

void PedidoEspecial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoEspecial::GetDescuento() const {
    return descuento;
}