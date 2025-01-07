/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NPedido.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 14:49
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H
#include <fstream>
using namespace std;

class NPedido {
private:
    char * codigo;
    int cantidad;
    double peso;
public:
    NPedido();
    ~NPedido();
    NPedido(const NPedido &ped);
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(const char* codigo);
    char* GetCodigo() const;

    void Leer(ifstream &arch);
    void Imprimir(ofstream &arch);
};
#endif /* NPEDIDO_H */
