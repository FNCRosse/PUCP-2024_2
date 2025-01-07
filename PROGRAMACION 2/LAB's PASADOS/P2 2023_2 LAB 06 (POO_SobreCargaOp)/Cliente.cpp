/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: Rosse
 * 
 * Created on 28 de octubre de 2024, 19:14
 */

#include <cstring>
#include <iomanip>

#include "Cliente.h"
#include "ProductoEntregado.h"
Cliente::Cliente() {
    cantidad_productos_entregados = 0;
    monto_total =0;
    nombre = nullptr;
}
Cliente::Cliente(int dni,char* nombre,int telefono){
    this->dni = dni;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
    this->telefono = telefono;
    this->cantidad_productos_entregados =0;
    this->monto_total = 0;
}
bool operator >> (ifstream &arch, Cliente &cli){
    char Nombre[60];
    int dni,telefono;
    arch>> dni;
    if(arch.eof()) return false;
     arch.get();
    arch.getline(Nombre,60,',');
    arch>> telefono; arch.get();
    Cliente cliente_local (dni,Nombre,telefono);
    cli = cliente_local;
    return true;
}
void Cliente::imprimirProductos(ofstream &arch){
    if(cantidad_productos_entregados == 0){
        arch<<left<<"  NO SE LE ENTREGARON PRODUCTOS ";
    } else {
        for(int i=0;i<cantidad_productos_entregados;i++){
            char cod [8];
            productos_entregados[i].GetCodigo(cod);
            arch<<left<<setw(12)<<cod;
        }
    }
    arch<<endl<<endl;
}
void operator << (ofstream &arch,  Cliente &cli){
    char nombre[60];
    cli.GetNombre(nombre);
    arch<<left<<setw(12)<<cli.GetDni()<<setw(40)<<nombre<<cli.GetTelefono()<<right<<setw(15)<<
            cli.GetMonto_total();
    cli.imprimirProductos(arch);
}
void Cliente::operator += (const Pedido &ped){
    ProductoEntregado prodEntregado;
    char codigo[8];
    ped.GetCodigo(codigo);
    prodEntregado.SetCodigo(codigo);
    prodEntregado.SetPrecio(ped.GetPrecio_producto());
    int indice = cantidad_productos_entregados;
    productos_entregados[indice] = prodEntregado;
    cantidad_productos_entregados++;
    monto_total+=ped.GetPrecio_producto();
}
void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetNombre(const char* cad) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Cliente::GetNombre(char *cad) const {
    if (nombre == nullptr) cad[0]=0 ;
    else strcpy(cad, nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}