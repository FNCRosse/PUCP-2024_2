/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: Rosse
 * 
 * Created on 28 de octubre de 2024, 19:18
 */

#include <cstring>
#include <iomanip>

#include "Producto.h"

Producto::Producto() {
    cantidad_clientes_no_servidos=0;
    cantidad_clientes_servidos=0;
}
bool operator >> (ifstream &arch, Producto &pro){
    char Cod[8],descripcion[110];
    int stock;
    double precio;
    arch.getline(Cod,8,',');
    if(arch.eof()) return false;
    arch.getline(descripcion,110,',');
    arch>> precio; arch.get();
    arch>> stock; arch.get();
    pro.SetCodigo(Cod);
    pro.SetDescripcion(descripcion);
    pro.SetPrecio(precio);
    pro.SetStock(stock);
    return true;
}
bool Producto::operator += (Pedido &ped){
    ped.SetPrecio_producto(precio);
    if(stock >= 0){ // hay stock
        int indice = cantidad_clientes_servidos;
        clientes_servidos[indice] = ped.GetDni_cliente();
        cantidad_clientes_servidos++;
        stock--;
        return true;
    } else { // no hay stock
        int indice = cantidad_clientes_no_servidos;
        clientes_no_servidos[indice] = ped.GetDni_cliente();
        cantidad_clientes_no_servidos++;
        return false;
    }
}
void Producto::imprimirClientes(ofstream &arch){
    arch<<left<<setw(32)<<"Clientes Atendidos:";
    if(cantidad_clientes_servidos== 0){
        arch<<" NO SE ATENDIERON PEDIDOS"<<endl;
    } else {
        for(int i=0;i<cantidad_clientes_servidos;i++){
            arch<<setw(12)<<clientes_servidos[i];
        }
    }
    arch<<endl<<left<<setw(32)<<"Clientes NO Atendidos:";
    if(cantidad_clientes_no_servidos == 0){
        arch<<"NO HAY CLIENTES SIN ATENDER"<<endl;
    } else {
        for(int i=0;i<cantidad_clientes_no_servidos;i++){
            arch<<setw(12)<<clientes_no_servidos[i];
        }
    }
    arch<<endl;
}
void operator << (ofstream &arch, Producto &pro){
    char cod[8], descripcion[110];
    pro.GetCodigo(cod);
    pro.GetDescripcion(descripcion);
    arch<<left<<setw(12)<<cod<<descripcion<<right<<setw(15)<<pro.GetPrecio()<<setw(8)<<pro.GetStock()<<endl;
    pro.imprimirClientes(arch);         
}
void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetDescripcion(const char* cad) {
    if (descripcion != nullptr) delete descripcion;
    descripcion = new char[strlen(cad) + 1];
    strcpy(descripcion, cad);
}

void Producto::GetDescripcion(char * cad) const {
    if (descripcion == nullptr) cad[0] = 0;
    else strcpy(cad, descripcion);
}

void Producto::SetCodigo(const char* cad) {
    if (codigo != nullptr) delete codigo;
    codigo = new char[strlen(cad) + 1];
    strcpy(codigo, cad);
}

void Producto::GetCodigo(char * cad) const {
    if (codigo == nullptr) cad[0] = 0;
    else strcpy(cad, codigo);
}