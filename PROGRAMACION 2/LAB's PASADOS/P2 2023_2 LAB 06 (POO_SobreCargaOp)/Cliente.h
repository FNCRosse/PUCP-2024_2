/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Rosse
 *
 * Created on 28 de octubre de 2024, 19:14
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <fstream>
using namespace std;
#include "ProductoEntregado.h"
#include "Pedido.h"
class Cliente{
private:
    int dni;
    char* nombre;
    int telefono;
    class ProductoEntregado productos_entregados [200];
    int cantidad_productos_entregados;
    double monto_total;
public:
    Cliente();
    Cliente(int,char*,int);
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *cad) const;
    void SetDni(int dni);
    int GetDni() const;
    
    void operator += (const Pedido &ped);
    void imprimirProductos(ofstream &arch);
};
bool operator >> (ifstream &arch, Cliente &cli);
void operator << (ofstream &arch,  Cliente &cli);
#endif /* CLIENTE_H */
