/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 17:33
 */

#include "Libro.h"

Libro::Libro() {

}

Libro::Libro(const Libro & lib) {
    this->autor = lib.autor;
    this->codigo = lib.codigo;
    this->genero = lib.genero;
    this->tema = lib.tema;
    this->titulo = lib.titulo;
}

Libro::~Libro() {
    
}

void Libro::Leer(ifstream &arch) {
    getline(arch,codigo,',');
    if(arch.eof()) return;
    getline(arch,titulo,',');
    getline(arch,autor,',');
    getline(arch,genero,',');
    getline(arch,tema,'\n');
}
bool Libro::operator < (const Libro & lib) const {
    return this->GetCodigo() < lib.GetCodigo();
}
void Libro::SetTema(string tema) {
    this->tema = tema;
}

string Libro::GetTema() const {
    return tema;
}

void Libro::SetGenero(string genero) {
    this->genero = genero;
}

string Libro::GetGenero() const {
    return genero;
}

void Libro::SetAutor(string autor) {
    this->autor = autor;
}

string Libro::GetAutor() const {
    return autor;
}

void Libro::SetTitulo(string titulo) {
    this->titulo = titulo;
}

string Libro::GetTitulo() const {
    return titulo;
}

void Libro::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string Libro::GetCodigo() const {
    return codigo;
}
