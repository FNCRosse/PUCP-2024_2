/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: Rosse
 * 
 * Created on 6 de noviembre de 2024, 11:45
 */

#include <cstring>
#include <iomanip>

#include "Cliente.h"

Cliente::Cliente() {
    nombre = nullptr;
    Distrito = nullptr;
    TotalPagado = 0;
    Descuento = 0;
}

Cliente::~Cliente() {
    if (nombre != nullptr) delete nombre;
    if (Distrito != nullptr) delete Distrito;
}

Cliente::Cliente(const Cliente &cli) {
    nombre = nullptr;
    Distrito = nullptr;
    *this = cli;
}

void Cliente::operator=(const Cliente & cli) {
    this->dni = cli.dni;
    SetNombre(cli.nombre);
    SetDistrito(cli.Distrito);
    this->Descuento = cli.Descuento;
    this->TotalPagado = cli.TotalPagado;
}

void Cliente::Leer(ifstream &arch) {
    char Buff[100], caracter;
    arch>>dni;
    if (arch.eof()) return;
    arch.get();
    arch.getline(Buff, 100, ',');
    SetNombre(Buff);
    arch.getline(Buff, 100, ',');
    SetDistrito(Buff);
    arch>>caracter;
    if (caracter == 'S') {
        arch.get();
        arch.getline(Buff, 100, '%');
        double desc = ConvertirDouble(Buff);
        SetDescuento(desc);
    }
    arch.get();
}

double Cliente::ConvertirDouble(const char *cad) {
    double resultado = 0.0;
    double factor = 1.0;
    bool EsDecimal = false;
    for (int i = 0; cad[i] != '\0'; i++) {
        if (cad[i] == '.') EsDecimal = true;
        else {
            int digito = cad[i] - '0';
            if (EsDecimal) {
                factor *= 0.1;
                resultado += digito *factor;
            } else {
                resultado = resultado * 10 + digito;
            }
        }
    }
    return resultado;
}

void Cliente::Imprimir(ofstream &arch) {
    arch << left << setw(15) << dni << setw(45) << nombre << setw(30) << Distrito << right << setw(10) << Descuento << "%"
            << setw(10) << TotalPagado << endl;
}

void Cliente::ColocarPedido(double TotalPlato) {
    double pago = TotalPlato - TotalPlato*(Descuento/100);
    TotalPagado += pago;
}

void operator>>(ifstream &arch, Cliente &cli) {
    cli.Leer(arch);
}

void operator<<(ofstream &arch, Cliente &cli) {
    cli.Imprimir(arch);
}

void Cliente::SetTotalPagado(double TotalPagado) {
    this->TotalPagado = TotalPagado;
}

double Cliente::GetTotalPagado() const {
    return TotalPagado;
}

void Cliente::SetDescuento(double Descuento) {
    this->Descuento = Descuento;
}

double Cliente::GetDescuento() const {
    return Descuento;
}

void Cliente::SetDistrito(const char* Dis) {
    if (Distrito != nullptr) delete Distrito;
    Distrito = new char [strlen(Dis) + 1];
    strcpy(Distrito, Dis);
}

void Cliente::GetDistrito(char * &cad) const {
    if (Distrito == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(Distrito) + 1];
        strcpy(cad, Distrito);
    }
}

void Cliente::SetNombre(const char* nomb) {
    if (nombre != nullptr) delete nombre;
    nombre = new char [strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Cliente::GetNombre(char *& cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(nombre) + 1];
        strcpy(cad, nombre);
    }
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}