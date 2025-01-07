/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PedidoUsual.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 20:19
 */

#include <iomanip>

#include "PedidoUsual.h"

PedidoUsual::PedidoUsual() {

}

PedidoUsual::~PedidoUsual() {

}
void PedidoUsual::Actualiza() {
    int to = GetTotal();
    SetTotal(to + (to*(flete/100)));
}
void PedidoUsual::lee(ifstream &arch) {
    arch>>descuento;
    arch.get();
    arch>>flete;
    arch.get();
    Pedido::lee(arch);
}

void PedidoUsual::imprime(ofstream &arch) {
    Pedido::imprime(arch);
    arch<<"Descuento: "<<right<<setw(15)<<descuento<<"%"<<endl;
    arch<<"Flete: "<<right<<setw(15)<<flete<<"%"<<endl<<endl;
}

void PedidoUsual::setFlete(double flete) {
    this->flete = flete;
}

double PedidoUsual::getFlete() const {
    return flete;
}

void PedidoUsual::setDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoUsual::getDescuento() const {
    return descuento;
}