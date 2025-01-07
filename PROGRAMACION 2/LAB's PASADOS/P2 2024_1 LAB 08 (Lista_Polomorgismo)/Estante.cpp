/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 16:25
 */

#include "Estante.h"

Estante::Estante() {
    
}

Estante::~Estante() {

}

void Estante::Leer(ifstream &arch) {
    arch>>clase;
    arch.get();
    arch>>id;
    arch.get();
    arch>>capacidad;
    arch.get();
}

void Estante::Imprimir(ofstream &arch) {
    for(int i=0;i<50;i++)arch<<"=";arch<<endl;
    arch << "ID: " << id << endl;
    arch << "Tipo: ";
    if (clase == 'H') arch << " Horizontal" << endl;
    if (clase == 'V') arch << " Vertical" << endl;
    arch << "Capacidad: " << capacidad << endl;
    arch << "Libro Contenidos: " << endl;
    for(int i=0;i<50;i++)arch<<"=";arch<<endl;
    Llibros.imprimir(arch);
}

void Estante::Actualizar() {
    Llibros.Actualizar();
}

void Estante::Insertar(Nodo *dato) {
    Llibros.Insertar(dato);
}

bool Estante::EspacioDisponible(Nodo *dato) {
    double capa = capacidad;
    return Llibros.VerificarPeso(capa, dato);
}

void Estante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estante::GetCapacidad() const {
    return capacidad;
}

void Estante::SetClase(char clase) {
    this->clase = clase;
}

char Estante::GetClase() const {
    return clase;
}

void Estante::SetId(int id) {
    this->id = id;
}

int Estante::GetId() const {
    return id;
}