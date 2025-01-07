/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: Rosse
 *
 * Created on 30 de octubre de 2024, 17:11
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include <fstream>
using namespace std;
#include "Libro.h"
#include "Espacio.h"
class Estante{
private:
    char* codigo;
    int anchura;
    int altura;
    class Libro libros[20];
    class Espacio *espacios;
    int cantidad_Libros;
public:
    Estante();
    virtual ~Estante();
    void SetCantidad_Libros(int cantidad_Libros);
    int GetCantidad_Libros() const;
    void SetEspacios(Espacio* espacios);
    Espacio* GetEspacios() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char* Codigo);
    void GetCodigo(char *&) const;
    
    void Leer (ifstream &arch);
    void Imprimir (ofstream &arch);
    bool operator += ( Libro& lib);
    int getSobrartes();
};
void operator >> (ifstream &arch, Estante & est);
void operator << (ofstream &arch, Estante & est);
#endif /* ESTANTE_H */
