/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: Rosse
 *
 * Created on 28 de octubre de 2024, 19:18
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <fstream>
using namespace std;
#include "Pedido.h"
class Producto{
private:
    char *codigo;
    char * descripcion;
    double precio;
    int stock;
    int  clientes_servidos[200];
    int  clientes_no_servidos[200];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
public:
    Producto();
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(const char* descripcion);
   void  GetDescripcion(char *Cad) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char * cad) const;
    bool operator += ( Pedido &ped);
    void imprimirClientes(ofstream &arch);
};
bool operator >> (ifstream &arch, Producto &pro);
void operator << (ofstream &arch,  Producto &pro);
#endif /* PRODUCTO_H */

