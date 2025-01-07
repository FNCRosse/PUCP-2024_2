/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PedidoUsual.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 20:19
 */

#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H
#include "Pedido.h"

class PedidoUsual : public Pedido {
private:
    double descuento;
    double flete;
public:
    PedidoUsual();
    ~PedidoUsual();
    void setFlete(double flete);
    double getFlete() const;
    void setDescuento(double descuento);
    double getDescuento() const;

    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void Actualiza();
};
#endif /* PEDIDOUSUAL_H */
