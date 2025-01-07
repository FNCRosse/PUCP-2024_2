/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 17:42
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Libro.h"
#include "Autor.h"
#include "Cliente.h"
#include <map>
#include <vector>

class Biblioteca{
private:
    map<string,class Autor>autores;
    vector<class Libro>libros;
    vector<class Cliente> clientes;
public:
    Biblioteca();
    void carga_libros(const char *namefile);
    void carga_autores(const char *namefile);
    void carga_clientes(const char *namefile);
    void MostrarRecomendaciones(const char *namefile);
};
#endif /* BIBLIOTECA_H */
