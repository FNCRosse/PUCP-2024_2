/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   biblioteca.cpp
 * Author: Rosse
 * 
 * Created on 30 de octubre de 2024, 17:11
 */

#include "biblioteca.h"

Biblioteca::Biblioteca() {
    cantidad_estantes = 0;
    cantidad_libros =0;
}

void Biblioteca::Carga_Libros() {
    ifstream arch("libros.csv");
    while(true){
        arch>>libros[cantidad_libros];
        if(arch.eof()) break;
        cantidad_libros++;
    }
}

void Biblioteca::Carga_Estantes() {
    ifstream arch("estantes.csv");
    while(true){
        arch>>estantes[cantidad_estantes];
        if(arch.eof()) break;
        cantidad_estantes++;
    }
}

void Biblioteca::Posicionar_Libros() {
    for(int i=0;i< cantidad_libros;i++){
        for(int k=0;k<cantidad_estantes;k++){
            if(estantes[k] += libros[i]) break;
        }
    }
}

void Biblioteca::Mostrar_Datos() {
    ofstream arch ("Reporte.txt");
    for(int i=0;i<cantidad_estantes;i++){
        arch<<estantes[i];
    }
}