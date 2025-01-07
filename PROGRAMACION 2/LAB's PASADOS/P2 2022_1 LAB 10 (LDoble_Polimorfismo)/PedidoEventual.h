/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PedidoEventual.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 20:22
 */

#ifndef PEDIDOEVENTUAL_H
#define PEDIDOEVENTUAL_H
#include "Pedido.h"

class PedidoEventual : public Pedido {
private:
    double flete;
public:
    PedidoEventual();
    ~PedidoEventual();
    void SetFlete(double flete);
    double GetFlete() const;
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void Actualiza();
};
#endif /* PEDIDOEVENTUAL_H */
