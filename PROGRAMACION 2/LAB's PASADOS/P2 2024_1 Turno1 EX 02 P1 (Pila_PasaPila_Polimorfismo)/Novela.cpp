/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Novela.cpp
 * Author: Rosse
 * 
 * Created on 21 de noviembre de 2024, 15:23
 */

#include <cstring>

#include "Novela.h"

Novela::Novela() {
    Editorial = nullptr;
    Autor = nullptr;
}

Novela::~Novela() {
    if (Autor != nullptr) delete Autor;
    if (Editorial != nullptr) delete Editorial;
}

void Novela::Leer(ifstream &arch) {
    Libro::Leer(arch);
    char buff[100];
    arch.getline(buff, 100, ',');
    SetAutor(buff);
    arch.getline(buff, 100, '\n');
    SetEditorial(buff);
}

void Novela::Imprimir(ofstream &arch) {
    Libro::Imprimir(arch);
    arch << "Autor: " << Autor << endl;
    arch << "Editorial: " << Editorial << endl<<endl;
}

void Novela::SetEditorial(const char* Edit) {
    if (Editorial != nullptr) delete Editorial;
    Editorial = new char [strlen(Edit) + 1];
    strcpy(Editorial, Edit);
}

void Novela::GetEditorial(char *&cad) const {
    if (Editorial == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(Editorial) + 1];
        strcpy(cad, Editorial);
    }
}

void Novela::SetAutor(const char* Au) {
    if (Autor != nullptr) delete Autor;
    Autor = new char [strlen(Au) + 1];
    strcpy(Autor, Au);
}

void Novela::GetAutor(char *&cad) const {
    if (Autor == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(Autor) + 1];
        strcpy(cad, Autor);
    }
}