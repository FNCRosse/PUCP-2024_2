/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PrioridadBaja.h
 * Author: Rosse
 *
 * Created on 6 de noviembre de 2024, 16:22
 */

#ifndef PRIORIDADBAJA_H
#define PRIORIDADBAJA_H

#include "Pedido.h"

class PrioridadBaja : public Pedido {
private:
    int dias_espera;
    int nueva_fecha_entrega;
public:
    PrioridadBaja();
    ~PrioridadBaja();
    PrioridadBaja(const PrioridadBaja &);
    void SetNueva_fecha_entrega(int nueva_fecha_entrega);
    int GetNueva_fecha_entrega() const;
    void SetDias_espera(int dias_espera);
    int GetDias_espera() const;

    void Lee(ifstream &arch);
    void imprime(ofstream &arch);
    void ActualizarOrden();
};
#endif /* PRIORIDADBAJA_H */
