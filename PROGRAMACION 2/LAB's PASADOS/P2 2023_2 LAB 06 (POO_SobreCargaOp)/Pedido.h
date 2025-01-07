/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Rosse
 *
 * Created on 28 de octubre de 2024, 19:23
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
using namespace std;
class Pedido{
private:
    char *codigo;
    int dni_cliente;
    double precio_producto;
public:
    Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const;
    
};
bool operator >> (ifstream &arch, Pedido &ped);
#endif /* PEDIDO_H */
