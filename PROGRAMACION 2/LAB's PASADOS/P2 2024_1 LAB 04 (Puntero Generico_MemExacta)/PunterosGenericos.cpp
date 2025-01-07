/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PunterosGenericos.cpp
 * Author: Rosse
 * 
 * Created on 25 de septiembre de 2024, 18:23
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
#include "Comunes.hpp"
enum Cliente {DNI,NOMBRE};
enum Reserva {COD,TITULO, AUTOR,PEDIDOS,STOCK};

bool operator >> (ifstream &arch, void *& registro){
    void **reg = new void *[2];
    int dni;
    char nombre[60];
    arch>>dni;
    if(arch.eof()) return false;
    arch.get();
    arch.getline(nombre,60,'\n');
    reg[DNI] = retorna_referencia_a_entero(dni);
    reg[NOMBRE] = mi_strdup(nombre);
    registro = reg;
    return true;
}
void cargaClientes(void *&clientes){
    ifstream arch ("clientes.csv");
    void **DatosClientes, *reg, *Buff[60];
    int nd=0;
    while(arch>>reg){
        Buff[nd] = reg;
        nd++;
    }
    DatosClientes = new void*[nd+1]{};
    for(int i=0;i<nd;i++) DatosClientes[i] = Buff[i];
    clientes = DatosClientes;
}
void cargaReserva(void *&reserva){
    ifstream arch ("Libros.csv");
    void **DatosReserva, *reg, *Buff[300];
    int nd=0;
    while(true){
        reg = ObtenerRegistro(arch);
        if(reg == nullptr) break;
        Buff[nd] = reg;
        nd++;
    }
    DatosReserva = new void*[nd+1]{};
    for(int i=0;i<nd;i++) DatosReserva[i] = Buff[i];
    reserva = DatosReserva;
}
void * ObtenerRegistro(ifstream &arch){
    void **reg = new void *[5]{}, **InicializacionPedCli;
    int stock;
    char titulo[80], codigo[8],autor[60];
    arch.getline(codigo,60,',');
    if(arch.eof()) return nullptr;
    arch.getline(titulo,60,',');
    arch.getline(autor,60,',');
    arch>>stock;
    InicializacionPedCli =new void *[stock]{};
    while(arch.get() != '\n');
    reg[COD] = mi_strdup(codigo);
    reg[TITULO] = mi_strdup(titulo);
    reg[AUTOR] = mi_strdup(autor);
    reg[PEDIDOS] = InicializacionPedCli;
    reg[STOCK] = retorna_referencia_a_entero(stock);
    return reg;
}

void CargaRerservar(void *clientes, void *&reserva){
    void **ArrReservas = (void **)reserva;
    ifstream arch ("Pedidos2.csv");
    int dni,posLibro;
    char codLibro[8];
    while(true){
        arch>>dni;
        if(arch.eof()) break;
        arch.get();
        arch.getline(codLibro,8,'\n');
        posLibro =  buscarLibro(ArrReservas,codLibro);
        if(posLibro != -1)
            InsertarPedido(dni,clientes,ArrReservas[posLibro]);
    }
}
int buscarLibro(void **reservas,char *codLibro){
    for(int i=0; reservas[i];i++){
        void **DatoReserva = (void **)reservas[i];
        char *codigo = (char*)DatoReserva[COD];
        if(strcmp(codLibro,codigo) == 0) return i;
    }
    return -1;
}
void InsertarPedido(int dni,void *clientes,void *&Reserva){
    void **DatoReserva = (void**)Reserva;
    void ** DatoPedidos = (void**) DatoReserva[PEDIDOS];
    void * Registro = ObtenerRegistroPedido(dni,clientes);
    int nd=0;
    while(DatoPedidos[nd] != nullptr) nd++;
    DatoPedidos[nd] = Registro;
}
void *ObtenerRegistroPedido(int dni,void *clientes){
    void **ArrClientes = (void **)clientes;
    void **Registro = new void*[2]{};
    char * nombre = buscarNombre(ArrClientes,dni);
    Registro[0] = retorna_referencia_a_entero(dni);
    Registro[1] = nombre;
    return Registro;
}
char* buscarNombre(void **clientes,int dni){
    for(int i=0; clientes[i];i++){
        void **DatoCliente = (void **)clientes[i];
        char *nombre = (char*)DatoCliente[NOMBRE];
        int *dni_cliente = (int*)DatoCliente[DNI];
        if(dni == *dni_cliente) return nombre;
    }
    return nullptr;
}