/* 
 * File:   Pedido.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 19:59
 */

#include <cstring>
#include <iomanip>

#include "Pedido.h"

Pedido::Pedido() {
    nombre = nullptr;
    total = 0;
}

void Pedido::lee(ifstream &arch) {
    char buff[100],c;
    int dd,mm,aa;
    arch.getline(buff,100,',');
    SetNombre(buff);
    arch>>cantidad>>c>>total>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
    arch.get();
    SetFecha(aa*10000+mm*100+dd);
}

void Pedido::imprime(ofstream &arch) {
    ImprimirFecha(arch);
    arch<<left<<setw(12)<<codigo<<nombre<<endl;
    arch<<"DNI: "<<right<<setw(15)<<dni<<endl;
    arch<<"Monto Total: "<<right<<setw(10)<<total<<endl;
}
void Pedido::Actualiza() {

}
void Pedido::ImprimirFecha(ofstream &arch){
    int aa,dd,mm,fch = fecha;
    aa = fch/10000;
    fch = fch % 10000;
    mm = fch /100;
    dd = fch %100;
    arch<<dd<<"/"<<mm<<"/"<<aa<<endl;
}
Pedido::~Pedido() {
    if (nombre != nullptr) delete nombre;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetNombre(const char* nomb) {
    if (nombre != nullptr) delete nombre;
    nombre = new char [strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Pedido::GetNombre(char* & cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(nombre) + 1];
        strcpy(cad, nombre);
    }
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}