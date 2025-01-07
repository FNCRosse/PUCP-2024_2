/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: Rosse
 * 
 * Created on 30 de octubre de 2024, 17:11
 */

#include <cstring>
#include <iomanip>

#include "Estante.h"

Estante::Estante() {
    espacios = nullptr;
    codigo = nullptr;
    cantidad_Libros = 0;
}

Estante::~Estante() {
    if (espacios != nullptr) delete espacios;
    if (codigo != nullptr) delete codigo;
}

void Estante::Leer(ifstream &arch) {
    char Buff[100];
    arch.getline(Buff, 100, ',');
    if (arch.eof()) return;
    SetCodigo(Buff);
    arch>>anchura;arch.get();
    arch>>altura;arch.get();
    Espacio *esp = new Espacio [altura*anchura];
    SetEspacios(esp);
}

void Estante::Imprimir(ofstream &arch) {
    arch << left << "Codigo Estante: " << setw(25) << codigo << "Cantidad de Libros: " << cantidad_Libros << endl;
    arch << left << "Anchura del estante: " << setw(25) << anchura << "Altura del estante: " << altura << endl;
    for (int i = 0; i < 80; i++) arch << "-";
    arch << endl;
    if (espacios != nullptr) {
    }
    arch << left << setw(15) << "CODIGO" << setw(50) << "NOMBRE" << setw(10) << "ANCHO" << "ALTO" << endl;
    for (int i = 0; i < 80; i++) arch << ".";
    arch << endl;
    for (int i = 0; i < cantidad_Libros; i++) {
        arch << libros[i];
    }
}
int Estante::getSobrartes(){
    int SumaAncLibros=0;
    for(int i=0;i<cantidad_Libros;i++){
        SumaAncLibros += libros[i].GetAncho();
    }
    return anchura-SumaAncLibros;
}
bool Estante::operator+=(Libro& lib) {
    int sobrante = getSobrartes();
    int altoLib = lib.GetAlto();
    int anchoLibr = lib.GetAncho();
    if(sobrante>0 and anchoLibr<=sobrante and altoLib<=altura){
        //Colocar los espacios del libro 
        for(int i=1; i<=anchoLibr;i++){
            int cont=0;
            int pos=(anchura-sobrante) * altura+(altura*i) -1;
            for(int k=pos;cont<altoLib;k--){
                espacios[k].SetContenido('*');
                cont++;
            }
        }
        //Agregar libro
        libros[cantidad_Libros]= lib; //Uso del constructor de copia
        cantidad_Libros++;
        lib.SetColocado(true);
        return true;
    } else {
        return false;
    }
}

void operator>>(ifstream &arch, Estante & est) {
    est.Leer(arch);
}

void operator<<(ofstream &arch, Estante & est) {
    est.Imprimir(arch);
}

void Estante::SetCantidad_Libros(int cantidad_Libros) {
    this->cantidad_Libros = cantidad_Libros;
}

int Estante::GetCantidad_Libros() const {
    return cantidad_Libros;
}

void Estante::SetEspacios(Espacio* espacios) {
    this->espacios = espacios;
}

Espacio* Estante::GetEspacios() const {
    return espacios;
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(const char* cod) {
    if (codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Estante::GetCodigo(char *&cad) const {
    if (codigo == nullptr) cad[0] = 0;
    else {
        cad = new char[strlen(codigo) + 1];
        strcpy(cad, codigo);
    }
}