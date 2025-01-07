/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunterosGenericos.h
 * Author: Rosse
 *
 * Created on 25 de septiembre de 2024, 18:23
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
#include <fstream>
using namespace std;
void cargaClientes(void *&clientes);
void cargaReserva(void *&reserva);
void CargaRerservar(void *clientes, void *&reserva);

bool operator >> (ifstream &arch, void *& registro);
void *ObtenerRegistro(ifstream &arch);
int buscarLibro(void **reserva,char *codLibro);
void InsertarPedido(int dni,void *clientes,void *&Reserva);
void *ObtenerRegistroPedido(int dni,void *clientes);
char* buscarNombre(void **clientes,int dni);
#endif /* PUNTEROSGENERICOS_H */
