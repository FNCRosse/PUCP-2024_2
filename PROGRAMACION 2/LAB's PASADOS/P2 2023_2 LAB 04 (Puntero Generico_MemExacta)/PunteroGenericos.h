/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunteroGenericos.h
 * Author: Rosse
 *
 * Created on 2 de octubre de 2024, 15:52
 */

#ifndef PUNTEROGENERICOS_H
#define PUNTEROGENERICOS_H
#include <fstream>
using namespace std;

void CargaProdutos(void *&Productos);
void CargaCliente(void *&Clientes);
void cargaPedido(void *Productos, void *&Clientes);
bool operator >> (ifstream &arch, void *&Reg);
bool LeerDatosCliente(ifstream &arch, void *&Reg);

int BuscarCliente(int dniCliente,void **ArrCliente);
int BuscarProducto(char* codProd,void **ArrProducto);
void ColocarPedido(void *Producto,void *&Cliente,int cantidad);
void * AgregarDatosProducto(void **DatoProducto,int cantidad);
int CalcularCantidadPedidos(void *LISTAPED);
void imprimereporte(void *Clientes);
void ImprimirLinea(ofstream &arch, char c, int n);
void ImprimirListaDePedidos(void * ListaPedidos,ofstream &arch);

#endif /* PUNTEROGENERICOS_H */
