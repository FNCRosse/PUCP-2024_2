/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Rosse
 *
 * Created on 6 de noviembre de 2024, 15:52
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
using namespace std;
class Pedido{
private:
    char* codigo;
    int dni_cliente;
    double subtotal;
    int fecha;
    char* estado;
    double total;
public:
    Pedido();
    virtual ~Pedido();
    Pedido(const Pedido &);
    void SetTotal(double total);
    double GetTotal() const;
    void SetEstado(const char* estado);
    void GetEstado(char *&) const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetSubtotal(double subtotal);
    double GetSubtotal() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *&) const;
    
    virtual void Lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
     
};
#endif /* PEDIDO_H */
