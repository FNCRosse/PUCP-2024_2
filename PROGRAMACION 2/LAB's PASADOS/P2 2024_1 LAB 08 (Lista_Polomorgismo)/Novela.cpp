/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Novela.cpp
 * Author: Rosse
 * 
 * Created on 20 de noviembre de 2024, 15:53
 */

#include <cstring>

#include "Novela.h"

Novela::Novela(){
    Autor = nullptr;
}
Novela::~Novela(){ 
    if(Autor != nullptr) delete Autor;
}
Novela::Novela(const Novela & nov){
    Autor = nullptr;
    *this  = nov;
}
void Novela::lee(ifstream &arch) {
    Libro::lee(arch);
    char buff[100];
    arch.getline(buff,100,'\n');
    SetAutor(buff);
}

void Novela::imprime(ofstream &arch) {
    Libro::imprime(arch);
    arch<<left<<"Autor:"<<Autor<<endl<<endl;
}

void Novela::actualiza() {
   
}
void Novela::SetAutor(const char* Au) {
    if (Autor != nullptr) delete Autor;
    Autor = new char [strlen(Au) + 1];
    strcpy(Autor, Au);
}

void Novela::GetAutor(char *& cad) const {
    if (Autor == nullptr) cad[0] = 0;
    else {
        cad = new char [strlen(Autor) + 1];
        strcpy(cad, Autor);
    }
}