/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 19:59
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
using namespace std;
class Pedido{
private:
    int codigo;
    char * nombre;
    int cantidad;
    int dni;
    int fecha;
    double total;
public:
    Pedido();
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *&) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    virtual void lee (ifstream &arch);
    virtual void imprime (ofstream &arch);
    virtual void Actualiza ();
    void ImprimirFecha(ofstream &arch);
};
#endif /* PEDIDO_H */
