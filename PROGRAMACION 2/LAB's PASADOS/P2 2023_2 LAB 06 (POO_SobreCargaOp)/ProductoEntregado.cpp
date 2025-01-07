/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ProductoEntregado.cpp
 * Author: Rosse
 * 
 * Created on 28 de octubre de 2024, 19:12
 */

#include <cstring>

#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado(){
    
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(const char* cad) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

void ProductoEntregado::GetCodigo(char * cad) const {
    if(codigo == nullptr) cad[0] = 0;
    else strcpy(cad,codigo);
}