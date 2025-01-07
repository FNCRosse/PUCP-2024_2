/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Plato.cpp
 * Author: Rosse
 * 
 * Created on 6 de noviembre de 2024, 12:03
 */

#include <iomanip>
#include <cstring>

#include "Plato.h"

Plato::Plato() {
    codigo = nullptr;
    nombre = nullptr;
    categoria = nullptr;
    descuento = 0;
    atendidos = 0;
    noatendidos = 0;
    totalEsperado = 0;
    TotalBruto = 0;
    totalNeto = 0;
}

Plato::~Plato() {
    if (nombre != nullptr) delete nombre;
    if (codigo != nullptr) delete codigo;
    if (categoria != nullptr) delete categoria;
}

Plato::Plato(const Plato &pla) {
    codigo = nullptr;
    nombre = nullptr;
    categoria = nullptr;
    *this = pla;
}

void Plato::operator=(const Plato & pla) {
    this->TotalBruto = pla.TotalBruto;
    this->atendidos = pla.atendidos;
    SetCategoria(pla.categoria);
    SetCodigo(pla.codigo);
    this->descuento = pla.descuento;
    this->noatendidos = pla.noatendidos;
    SetNombre(pla.nombre);
    this->precio = pla.precio;
    this->preparados = pla.preparados;
    this->totalEsperado = pla.totalEsperado;
    this->totalNeto = pla.totalNeto;
}

void Plato::Leer(ifstream &arch) {
    char Buff[100], caracter;
    arch.getline(Buff, 100, ',');
    if (arch.eof()) return;
    SetCodigo(Buff);
    arch.getline(Buff, 100, ',');
    SetNombre(Buff);
    arch>>precio;
    arch.get();
    arch.getline(Buff, 100, ',');
    SetCategoria(Buff);
    arch>>preparados;
    arch.get(caracter);
    if (caracter == ',') {
        arch.getline(Buff, 100, '%');
        double desc = ConvertirDouble(Buff);
        SetDescuento(desc);
        arch.get();
    }
    totalEsperado = preparados*precio;
}

void Plato::Imprimir(ofstream &arch) {
    arch << left << setw(15) << codigo << setw(50) << nombre << setw(8) << precio << setw(10) << categoria << right
            << setw(10) << descuento << "%" << setw(10) << preparados << setw(12) << atendidos << setw(12) << noatendidos
            << setw(15) << totalEsperado << setw(15) << TotalBruto << setw(15) << totalNeto << endl;
}

double Plato::ConvertirDouble(const char *cad) {
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

bool Plato::ColocarPedido(double TotalPlato,int cant) {
    if(atendidos + cant <= preparados){
        atendidos += cant;
        double pago = TotalPlato - TotalPlato*(descuento/100);
        TotalBruto += TotalPlato;
        totalNeto += pago;
        return true;
    } else{
        noatendidos += cant;
        return false;
    }
}

void operator>>(ifstream &arch, Plato &pla) {
    pla.Leer(arch);
}

void operator<<(ofstream &arch, Plato &pla) {
    pla.Imprimir(arch);
}

void Plato::SetTotalNeto(double totalNeto) {
    this->totalNeto = totalNeto;
}

double Plato::GetTotalNeto() const {
    return totalNeto;
}

void Plato::SetTotalBruto(double TotalBruto) {
    this->TotalBruto = TotalBruto;
}

double Plato::GetTotalBruto() const {
    return TotalBruto;
}

void Plato::SetTotalEsperado(double totalEsperado) {
    this->totalEsperado = totalEsperado;
}

double Plato::GetTotalEsperado() const {
    return totalEsperado;
}

void Plato::SetNoatendidos(int noatendidos) {
    this->noatendidos = noatendidos;
}

int Plato::GetNoatendidos() const {
    return noatendidos;
}

void Plato::SetAtendidos(int atendidos) {
    this->atendidos = atendidos;
}

int Plato::GetAtendidos() const {
    return atendidos;
}

void Plato::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Plato::GetDescuento() const {
    return descuento;
}

void Plato::SetPreparados(int preparados) {
    this->preparados = preparados;
}

int Plato::GetPreparados() const {
    return preparados;
}

void Plato::SetCategoria(const char* cat) {
    if (categoria != nullptr) delete categoria;
    categoria = new char [strlen(cat) + 1];
    strcpy(categoria, cat);
}

void Plato::GetCategoria(char *& cad) const {
    if (categoria == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(categoria) + 1];
        strcpy(cad, categoria);
    }
}

void Plato::SetPrecio(double precio) {
    this->precio = precio;
}

double Plato::GetPrecio() const {
    return precio;
}

void Plato::SetNombre(const char* nomb) {
    if (nombre != nullptr) delete nombre;
    nombre = new char [strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Plato::GetNombre(char *& cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(nombre) + 1];
        strcpy(cad, nombre);
    }
}

void Plato::SetCodigo(const char* cod) {
    if (codigo != nullptr) delete codigo;
    codigo = new char [strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Plato::GetCodigo(char *& cad) const {
    if (codigo == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(codigo) + 1];
        strcpy(cad, codigo);
    }
}