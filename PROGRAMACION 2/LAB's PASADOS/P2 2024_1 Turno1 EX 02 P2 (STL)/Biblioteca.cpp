/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 17:42
 */

#include "Biblioteca.h"

Biblioteca::Biblioteca() {

}

void Biblioteca::carga_libros(const char *namefile) {
    ifstream arch(namefile);
    class Libro lib;
    while(true){
        lib.Leer(arch);
        if(arch.eof()) break;
        libros.push_back(lib);
    }
}

void Biblioteca::carga_autores(const char *namefile) {
    ifstream arch(namefile);
    class Autor autor;
    while(true){
        autor.Leer(arch);
        if(arch.eof()) break;
        autor.AgregarSusLibros(libros);
        autores[autor.GetNombre()]=autor;
    }
}

void Biblioteca::carga_clientes(const char *namefile) {
    ifstream arch(namefile);
    while(true){
        class Cliente cli;
        cli.Leer(arch,libros);
        if(arch.eof()) break;
        cli.ObtenerRecomendaciones(libros);
        clientes.push_back(cli);
    }
}

void Biblioteca::MostrarRecomendaciones(const char *namefile) {
    ofstream arch(namefile);
    arch<<"REPORTE DE RECOMENDACIONES"<<endl;
    for(class Cliente cli : clientes){
        for(int i=0;i<50;i++)arch<<"=";arch<<endl;
        cli.Imprimir(arch);
        for(int i=0;i<50;i++)arch<<"=";arch<<endl;
    }
}