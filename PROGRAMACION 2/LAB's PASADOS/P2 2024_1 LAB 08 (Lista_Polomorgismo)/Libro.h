/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 15:37
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
using namespace std;
class Libro{
private:
    char * nombre;
    int paginas;
    double peso;
public:
    Libro();
    virtual ~Libro();
    Libro(const Libro &);
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *&) const;
    
    virtual void lee (ifstream &arch);
    virtual void imprime (ofstream &arch);
    virtual void actualiza () ;
    
};
#endif /* LIBRO_H */
