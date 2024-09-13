/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   SobreCargar.h
 * Author: Rosse
 *
 * Created on 12 de septiembre de 2024, 17:15
 */

#ifndef SOBRECARGAR_H
#define SOBRECARGAR_H
#include "Util.h"
void operator >> (ifstream &arch, struct Plato &pla);
void operator >> (ifstream &arch, struct Repartidor &rep);
void operator >> (ifstream &arch, struct Pedido &ped);

bool operator <= (struct Pedido &ped, struct Plato *ArrPlato);
void operator <= (struct Repartidor *ArrRep, const struct Pedido &Ped);
void operator ! (struct OrdenDeCompra &orden);
void operator ! (struct Repartidor &Rep);
void operator << (ofstream &arch, const struct Plato &pla);
void operator << (ofstream &arch, const struct Repartidor &rep);

int BuscarCliente (int dniDelCliente,struct OrdenDeCompra *ordenesDeCompra,int);
int BuscarPlatos (const char* codPlato,struct PlatoSolicitado *platos,int);
void AgregarPlato(const struct Pedido &Ped,int posCliente,struct OrdenDeCompra &orden);
#endif /* SOBRECARGAR_H */
