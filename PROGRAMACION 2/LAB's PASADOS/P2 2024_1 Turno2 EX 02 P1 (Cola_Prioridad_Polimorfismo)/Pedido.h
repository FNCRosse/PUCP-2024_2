/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Rosse
 *
 * Created on 21 de noviembre de 2024, 10:33
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
using namespace std;
class Pedido{
private:
    int fecha;
    int dni;
    double monto;
public:
    Pedido();
    ~Pedido();
    void SetMonto(double monto);
    double GetMonto() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    
    virtual void Leer(ifstream &arch);
    virtual void Imprimir(ofstream &arch);
};
#endif /* PEDIDO_H */
