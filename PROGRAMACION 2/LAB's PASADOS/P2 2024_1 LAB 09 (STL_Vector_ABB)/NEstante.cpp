/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NEstante.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 12:14
 */

#include <iomanip>

#include "NEstante.h"

NEstante::NEstante() {
    izq = nullptr;
    der = nullptr;
}
NEstante::NEstante(const class NEstante &est){
    this->id =est.id;
    this->capacidad = est.capacidad;
    this->disponible = est.disponible;
    this->der = nullptr;
    this->izq = nullptr;
    this->vLibros = est.vLibros;
}

NEstante::~NEstante() {
    if(izq != nullptr) delete izq;
    if(der != nullptr) delete der;
}

void NEstante::AgregarLibro(class NLibro &dato) {
    double pesoLib = dato.getPeso();
    if(disponible - pesoLib >=0){
        vLibros.push_back(dato);
        disponible = disponible -pesoLib;
    }
}

void NEstante::LeerEstante(ifstream &arch) {
    arch>>id;
    if(arch.eof()) return;
    arch.get();
    arch>>capacidad;
    arch.get();
    disponible =capacidad;
}

void NEstante::ImprimeEstante(ofstream &arch) {
    arch<<"Estante: "<<id<<endl;
    arch<<"Capacidad: "<<left<<setw(10)<<capacidad<<"Disponible: "<<disponible<<endl;
    for(int i=0;i<50;i++)arch<<"=";arch<<endl;
    if(!vLibros.empty()){
        for(class NLibro dato : vLibros){
            dato.Imprime(arch);
        }
    }
    arch<<endl;
}

void NEstante::SetDisponible(double disponible) {
    this->disponible = disponible;
}

double NEstante::GetDisponible() const {
    return disponible;
}

void NEstante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double NEstante::GetCapacidad() const {
    return capacidad;
}

void NEstante::SetId(int id) {
    this->id = id;
}

int NEstante::GetId() const {
    return id;
}