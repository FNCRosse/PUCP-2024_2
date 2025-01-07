/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Novela.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 12:08
 */

#include <cstring>

#include "Novela.h"

Novela::Novela() {
    autor = nullptr;
}

Novela::~Novela() {
    if (autor != nullptr) delete autor;
}

void Novela::Leer(ifstream &arch) {
    Libro::Leer(arch);
    char buff[100];
    arch.getline(buff,100,'\n');
    SetAutor(buff);
}

void Novela::Imprime(ofstream &arch) {
    Libro::Imprime(arch);
    arch << "Autor: " << autor << endl << endl;
}

void Novela::SetAutor(const char* aut) {
    if (autor != nullptr) delete autor;
    autor = new char [strlen(aut) + 1];
    strcpy(autor, aut);
}

char* Novela::GetAutor() const {
    return autor;
}