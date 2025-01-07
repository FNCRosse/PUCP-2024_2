/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Rosse
 *
 * Created on 30 de octubre de 2024, 17:10
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
using namespace std;
class Libro{
private:
    char * codigo;
    char * nombre;
    int ancho;
    int alto;
    bool Colocado;
public:
    Libro();
    virtual ~Libro();
    Libro(char* cod,char* nomb,int an,int al,bool col);
    Libro(const Libro &lib); //Costructor de copia
    void SetColocado(bool Colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*&) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*&) const;
    
    void Leer (ifstream &arch);
    void Imprimir (ofstream &arch);
    
};
void operator >> (ifstream &arch, Libro & lib);
void operator << (ofstream &arch, Libro & lib);
#endif /* LIBRO_H */
