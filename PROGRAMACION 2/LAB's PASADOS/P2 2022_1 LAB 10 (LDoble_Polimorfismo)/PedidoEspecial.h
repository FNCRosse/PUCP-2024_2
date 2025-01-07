/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PedidoEspecial.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 20:14
 */

#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H
#include "Pedido.h"

class PedidoEspecial : public Pedido {
private:
    double descuento;
public:
    PedidoEspecial();
    ~PedidoEspecial();
    void SetDescuento(double descuento);
    double GetDescuento() const;

    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void Actualiza();
};
#endif /* PEDIDOESPECIAL_H */
