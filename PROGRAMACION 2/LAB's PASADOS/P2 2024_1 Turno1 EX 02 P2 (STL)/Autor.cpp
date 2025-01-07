/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Autor.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 17:36
 */

#include "Autor.h"

Autor::Autor(){
    
}
Autor::Autor(const Autor &au){
    this->codigo = au.codigo;
    this->libros = au.libros;
    this->nombre = au.nombre;
}
Autor::~Autor(){
    
}
void Autor::Leer(ifstream &arch) {
    getline(arch,codigo,',');
    if(arch.eof()) return;
    getline(arch,nombre,'\n');
}
void Autor::AgregarSusLibros(vector<class Libro> &ConjuntoLibros){
    for(class Libro lib: ConjuntoLibros){
        if(codigo == lib.GetAutor()){
            libros.push_front(lib);
        }
    }
}
void Autor::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Autor::GetNombre() const {
    return nombre;
}

void Autor::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string Autor::GetCodigo() const {
    return codigo;
}