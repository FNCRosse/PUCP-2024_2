/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 17:39
 */

#include <iomanip>

#include "Cliente.h"

Cliente::Cliente() {
    cantidad_Libros_vendidos = 0;
}

Cliente::Cliente(const Cliente & cli) {
    this->cantidad_Libros_vendidos = cli.cantidad_Libros_vendidos;
    this->codigo = cli.codigo;
    this->libros_comprados = cli.libros_comprados;
    this->nombre = cli.nombre;
    this->recomendaciones = cli.recomendaciones;
}

Cliente::~Cliente() {

}

void Cliente::Leer(ifstream &arch, vector<class Libro> &ConjuntoLibros) {
    getline(arch, codigo, ',');
    if (arch.eof()) return;
    getline(arch, nombre, ',');
    arch>>cantidad_Libros_vendidos;
    arch.get();
    for (int i = 0; i < cantidad_Libros_vendidos; i++) {
        string codLibro;
        getline(arch, codLibro, ',');
        int posLibro = ObtenerLibro(ConjuntoLibros, codLibro);
        if (posLibro != -1)
            libros_comprados.push_back(ConjuntoLibros[posLibro]);
    }
    arch.get();
}

int Cliente::ObtenerLibro(vector<class Libro> &ConjuntoLibros, string codLibro) {
    for (int i = 0; i < ConjuntoLibros.size(); i++) {
        if (codLibro == ConjuntoLibros[i].GetCodigo()) return i;
    }
    return -1;
}

void Cliente::ObtenerRecomendaciones(vector<class Libro> &ConjuntoLibros) {
    for (class Libro libCom : libros_comprados) {
        vector<class Libro> librosRecom;
        for (class Libro lib : ConjuntoLibros) {
            if (libCom.GetCodigo() == lib.GetCodigo()) continue;
            if(libCom.GetAutor() == lib.GetAutor() and libCom.GetGenero() == lib.GetGenero() and
                    libCom.GetTema() == lib.GetTema())
                librosRecom.push_back(lib);
        }
        recomendaciones[libCom] = librosRecom;
    }
}
void Cliente::Imprimir(ofstream &arch){
    arch<<"Codigo de Cliente: "<<left<<setw(12)<<codigo<<"Nombre: "<<nombre<<endl;
    int i=1;
    for(auto recom : recomendaciones){
        arch<<"Libro Comprado "<<i<<") "<<recom.first.GetTitulo()<<endl;
        arch<<"Libros Recomendados: "<<endl;
        if(!recom.second.empty()){
            for(class Libro libRec : recom.second){
                arch<<libRec.GetTitulo()<<endl;
            }
        } else arch<<"No hay Recomendaciones"<<endl;
    }
}

void Cliente::SetCantidad_Libros_vendidos(int cantidad_Libros_vendidos) {
    this->cantidad_Libros_vendidos = cantidad_Libros_vendidos;
}

int Cliente::GetCantidad_Libros_vendidos() const {
    return cantidad_Libros_vendidos;
}

void Cliente::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Cliente::GetNombre() const {
    return nombre;
}

void Cliente::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string Cliente::GetCodigo() const {
    return codigo;
}