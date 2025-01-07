/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Restaurante.cpp
 * Author: Rosse
 * 
 * Created on 6 de noviembre de 2024, 12:21
 */
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Restaurante.h"
#define INCREMENTO 5

Restaurante::Restaurante() {
    cantidadDeClientes = 0;
    cantidadDePlatos = 0;
    capacidadDeClientes = 0;
    capacidadDePlatos = 0;
    clientes = nullptr;
    platos = nullptr;
}

Restaurante::~Restaurante() {
    if (clientes != nullptr) delete clientes;
    if (platos != nullptr) delete platos;
}

Restaurante::Restaurante(const Restaurante &res) {
    clientes = nullptr;
    platos = nullptr;
    *this = res;
}

void Restaurante::operator<(const char*namefile) {
    ifstream arch(namefile);
    Cliente cli;
    while (true) {
        arch>>cli;
        if (arch.eof()) break;
        if (cantidadDeClientes == capacidadDeClientes)
            IncrementarEspaciosCliente();
        clientes[cantidadDeClientes] = cli;
        cantidadDeClientes++;
    }
}

void Restaurante::operator<=(const char*namefile) {
    ifstream arch(namefile);
    Plato pla;
    while (true) {
        arch>>pla;
        if (arch.eof()) break;
        if (cantidadDePlatos == capacidadDePlatos)
            IncrementarEspaciosPlato();
        platos[cantidadDePlatos] = pla;
        cantidadDePlatos++;
    }
}
//358019,93231760,PO11471,8,BE77572,7,BR15724,4,BR15921,2,PO11171,5,PA53957,4,AD39987,7,BR15592,2,BR15756,5

void Restaurante::operator<<=(const char*namefile) {
    ifstream arch(namefile);
    int numPed, dniCliente, cant, posCliente, posPlato;
    char codPlato[8];
    while (true) {
        arch>>numPed;
        if (arch.eof()) break;
        arch.get();
        arch>>dniCliente;
        arch.get();
        posCliente = buscarCliente(dniCliente);
        while (true) {
            arch.getline(codPlato, 8, ',');
            arch>>cant;
            posPlato = buscarPlato(codPlato);
            if (posCliente != -1 and posCliente != -1) {
                double totalPlato = platos[posPlato].GetPrecio() * cant;
                if(platos[posPlato].ColocarPedido(totalPlato,cant))
                    clientes[posCliente].ColocarPedido(totalPlato);
            }
            if (arch.get() == '\n') break;
        }
    }
}

int Restaurante::buscarCliente(int dniCliente) {
    for (int i = 0; i < cantidadDeClientes; i++) {
        if (clientes[i].GetDni() == dniCliente) return i;
    }
    return -1;
}

int Restaurante::buscarPlato(char *codPlato) {
    for (int i = 0; i < cantidadDePlatos; i++) {
        char *codigo;
        platos[i].GetCodigo(codigo);
        if (strcmp(codPlato, codigo) == 0) return i;
    }
    return -1;
}

void Restaurante::operator>>(const char*namefile) {
    ofstream arch(namefile);
    arch << setprecision(2) << fixed;
    arch << "RESTAURANTE 1INF25" << endl;
    arch << "VENTAS DEL DIA" << endl;
    imprimirLineas(arch, 100, '=');
    arch << "RELACION DE PLATOS VENDIDOS" << endl;
    imprimirLineas(arch, 100, '-');
    for (int i = 0; i < cantidadDePlatos; i++) {
        arch << platos[i];
    }
    imprimirLineas(arch, 100, '=');
    arch << "RELACION DE CLIENTES VENDIDOS" << endl;
    imprimirLineas(arch, 100, '-');
    for (int i = 0; i < cantidadDeClientes; i++) {
        arch << clientes[i];
    }
}

void Restaurante::IncrementarEspaciosPlato() {
    class Plato *aux;
    capacidadDePlatos += INCREMENTO;
    aux = new Plato[capacidadDePlatos];
    if (platos != nullptr) {
        for (int i = 0; i < cantidadDePlatos; i++) {
            aux[i] = platos[i];
        }
        delete[] platos;
    }
    platos = aux;
}

void Restaurante::IncrementarEspaciosCliente() {
    class Cliente *aux;
    capacidadDeClientes += INCREMENTO;
    aux = new Cliente[capacidadDeClientes];
    if (clientes != nullptr) {
        for (int i = 0; i < cantidadDeClientes; i++) {
            aux[i] = clientes[i];
        }
        delete[] clientes;
    }
    clientes = aux;
}

void Restaurante::imprimirLineas(ofstream& arch, int n, char c) {
    for (int i = 0; i < n; i++)arch << c;
    arch << endl;
}

void Restaurante::SetCapacidadDePlatos(int capacidadDePlatos) {
    this->capacidadDePlatos = capacidadDePlatos;
}

int Restaurante::GetCapacidadDePlatos() const {
    return capacidadDePlatos;
}

void Restaurante::SetCantidadDePlatos(int cantidadDePlatos) {
    this->cantidadDePlatos = cantidadDePlatos;
}

int Restaurante::GetCantidadDePlatos() const {
    return cantidadDePlatos;
}

void Restaurante::SetPlatos(Plato* platos) {
    this->platos = platos;
}

Plato* Restaurante::GetPlatos() const {
    return platos;
}

void Restaurante::SetCapacidadDeClientes(int capacidadDeClientes) {
    this->capacidadDeClientes = capacidadDeClientes;
}

int Restaurante::GetCapacidadDeClientes() const {
    return capacidadDeClientes;
}

void Restaurante::SetCantidadDeClientes(int cantidadDeClientes) {
    this->cantidadDeClientes = cantidadDeClientes;
}

int Restaurante::GetCantidadDeClientes() const {
    return cantidadDeClientes;
}

void Restaurante::SetClientes(Cliente* clientes) {
    this->clientes = clientes;
}

Cliente* Restaurante::GetClientes() const {
    return clientes;
}