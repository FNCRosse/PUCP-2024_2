/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 17:39
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include "Libro.h"
#include <vector>
#include <map>

class Cliente {
private:
    string codigo;
    string nombre;
    vector<class Libro> libros_comprados;
    int cantidad_Libros_vendidos;
    map<class Libro, vector<class Libro>> recomendaciones;
public:
    Cliente();
    Cliente(const Cliente&);
    ~Cliente();
    void SetCantidad_Libros_vendidos(int cantidad_Libros_vendidos);
    int GetCantidad_Libros_vendidos() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;

    void Leer(ifstream &arch,vector<class Libro> &ConjuntoLibros);
    int ObtenerLibro(vector<class Libro> &ConjuntoLibros,string codLibro);
    void ObtenerRecomendaciones(vector<class Libro> &ConjuntoLibros);
    void Imprimir(ofstream &arch);
};
#endif /* CLIENTE_H */
