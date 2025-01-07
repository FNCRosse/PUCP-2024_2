/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Promociones.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 20:33
 */

#include <iomanip>

#include "Promociones.h"

Promociones::Promociones() {

}

void Promociones::LeePedidos() {
    ifstream arch("pedidos5.csv");
    int codigo;
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch.get();
        Lpedidos.LeerDato(arch,codigo);
    }
}

void Promociones::ActualizaPedidos() {
    ifstream arch("promocion.csv");
    int dniCliente,dd,aa,mm,FechaCliente;
    char c;
    while(true){
        arch>>dniCliente;
        if(arch.eof()) break;
        arch>>c>>dd>>c>>mm>>c>>aa;
        FechaCliente = aa*10000+mm*100+dd;
        Lpedidos.Actualizar(dniCliente,FechaCliente);
    }
}

void Promociones::ImprimePedido() {
    ofstream arch ("ReportePedidos.txt");
    arch<<setprecision(2)<<fixed;
    Lpedidos.Imprimir(arch);
}