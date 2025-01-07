/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PedidoEventual.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 20:22
 */

#include <iomanip>

#include "PedidoEventual.h"

PedidoEventual::PedidoEventual(){
    
}
PedidoEventual::~PedidoEventual(){
    
}
void PedidoEventual::Actualiza() {
    int to = GetTotal();
    SetTotal(to + (to*(flete/100)));
}
void PedidoEventual::lee(ifstream &arch) {
    arch>>flete;
    arch.get();
    Pedido::lee(arch);
}

void PedidoEventual::imprime(ofstream &arch) {
    Pedido::imprime(arch);
    arch<<"Flete: "<<right<<setw(15)<<flete<<"%"<<endl<<endl;
}
void PedidoEventual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoEventual::GetFlete() const {
    return flete;
}