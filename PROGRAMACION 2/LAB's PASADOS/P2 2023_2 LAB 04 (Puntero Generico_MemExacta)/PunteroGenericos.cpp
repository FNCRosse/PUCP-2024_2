/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PunteroGenericos.cpp
 * Author: Rosse
 * 
 * Created on 2 de octubre de 2024, 15:52
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "PunteroGenericos.h"
#include "Comunes.hpp"

enum Productos {COD, DESC, PRECIO, TIPOPRO};
enum Cliente {DNI, NOMBRE, LISTAPED, LINESCRED};
enum Pedido {CODPRO, CANTIDAD, TOTAL};
//BIT-434,Campana Extractora modelo Glass,375.09,S

bool operator>>(ifstream &arch, void *&Reg) {
    void **Registro = new void *[4];
    char codigo[8], descripcion[80], tipo[2];
    double precio;
    arch.getline(codigo, 8, ',');
    if (arch.eof()) return false;
    arch.getline(descripcion, 80, ',');
    arch>>precio;
    arch.get();
    arch.getline(tipo, 2, '\n');
    Registro[COD] = mi_strdup(codigo);
    Registro[DESC] = mi_strdup(descripcion);
    Registro[PRECIO] = retorna_referencia_a_real(precio);
    Registro[TIPOPRO] = mi_strdup(tipo);
    Reg = Registro;
    return true;
}

void CargaProdutos(void *&Productos) {
    ifstream arch("Productos2.csv");
    void **ArrProductos, *Reg, *Buff[200];
    int nd = 0;
    while (arch >> Reg) {
        Buff[nd] = Reg;
        nd++;
    }
    ArrProductos = new void *[nd + 1] {
    };
    for (int i = 0; i < nd; i++) ArrProductos[i] = Buff[i];
    Productos = ArrProductos;
}
//79464412,PORTUGAL RAFFO ALEXANDER,3902394,10000

bool LeerDatosCliente(ifstream &arch, void *&Reg) {
    void **Registro = new void *[4];
    char nombre[80];
    int dni, telefono;
    double credito;
    arch>>dni;
    if (arch.eof()) return false;
    arch.get();
    arch.getline(nombre, 80, ',');
    arch>>telefono;
    arch.get();
    arch>>credito;
    arch.get();
    Registro[DNI] = retorna_referencia_a_entero(dni);
    Registro[NOMBRE] = mi_strdup(nombre);
    Registro[LISTAPED] = nullptr;
    Registro[LINESCRED] = retorna_referencia_a_real(credito);
    Reg = Registro;
    return true;
}

void CargaCliente(void *&Clientes) {
    ifstream arch("Clientes2.csv");
    void **ArrClientes, *Reg, *Buff[200];
    int nd = 0;
    while (LeerDatosCliente(arch, Reg)) {
        Buff[nd] = Reg;
        nd++;
    }
    ArrClientes = new void *[nd + 1] {
    };
    for (int i = 0; i < nd; i++) ArrClientes[i] = Buff[i];
    Clientes = ArrClientes;
}
//JXD-139,50375303,6

void cargaPedido(void *Productos, void *&Clientes) {
    ifstream arch("Pedidos2.csv");
    void **ArrProducto = (void **) Productos;
    void **ArrCliente = (void **) Clientes;
    char codProd[8];
    int dniCliente, cantidad, posCliente, posProd;
    while (true) {
        arch.getline(codProd, 8, ',');
        if (arch.eof()) break;
        arch>>dniCliente;
        arch.get();
        arch>>cantidad;
        arch.get();
        if(dniCliente == 79464412){
            cout << "here"<<endl;
        }
        posCliente = BuscarCliente(dniCliente, ArrCliente);
        posProd = BuscarProducto(codProd, ArrProducto);
        ColocarPedido(ArrProducto[posProd], ArrCliente[posCliente], cantidad);
    }
}

int BuscarCliente(int dniCliente, void **ArrCliente) {
    for (int i = 0; ArrCliente[i]; i++) {
        void **DatoCliente = (void **) ArrCliente[i];
        int *dni = (int *) DatoCliente[DNI];
        if (*dni == dniCliente) return i;
    }
    return -1;
}

int BuscarProducto(char* codProd, void **ArrProducto) {
    for (int i = 0; ArrProducto[i]; i++) {
        void **DatoProducto = (void **) ArrProducto[i];
        char *codigo = (char *) DatoProducto[COD];
        if (strcmp(codProd, codigo) == 0) return i;
    }
    return -1;
}

void ColocarPedido(void *Producto, void *&Cliente, int cantidad) {
    void **DatoCliente = (void **) Cliente;
    void **DatoProducto = (void **) Producto;
    void *registro = AgregarDatosProducto(DatoProducto, cantidad),**ListaPedido;
    char * Tipo = (char*) DatoProducto[TIPOPRO];
    double * precio = (double *) DatoProducto[PRECIO];
    double * LineaCredito = (double *) DatoCliente[LINESCRED];
    if (DatoCliente[LISTAPED] == nullptr) {
        ListaPedido = new void *[2]{};
        if (strcmp(Tipo, "N") == 0){
            ListaPedido[0] = registro;
        }
        else if (*LineaCredito - (*precio*cantidad)>= 0) {
            ListaPedido[0] = registro;
            double actualLineaCredito = *LineaCredito - (*precio*cantidad);
            DatoCliente[LINESCRED] = retorna_referencia_a_real(actualLineaCredito);
        } else ListaPedido = nullptr;
    } else {
        int cantidad_pedidos = CalcularCantidadPedidos(DatoCliente[LISTAPED]);
        void **Buff_Ant = (void **)DatoCliente[LISTAPED];
        ListaPedido = new void *[cantidad_pedidos+2]{};
        for(int i=0;i<cantidad_pedidos;i++){
            ListaPedido[i] = Buff_Ant[i];
        }
        if (strcmp(Tipo, "N") == 0) ListaPedido[cantidad_pedidos] = registro;
        else if (*LineaCredito - (*precio*cantidad) >= 0) {
            ListaPedido[cantidad_pedidos] = registro;
            double actualLineaCredito = *LineaCredito - (*precio*cantidad);
            DatoCliente[LINESCRED] = retorna_referencia_a_real(actualLineaCredito);
        }
        ListaPedido[cantidad_pedidos+1] =nullptr;
        delete []Buff_Ant;
    }
    DatoCliente[LISTAPED]= ListaPedido;
}

int CalcularCantidadPedidos(void *LISTAPED){
    int cantidad =0;
    void **Lista = (void **) LISTAPED;
    while(Lista[cantidad] != nullptr) cantidad++;
    return cantidad;
}
void * AgregarDatosProducto(void **DatoProducto, int cantidad) {
    void **Registro = new void*[3];
    Registro[CODPRO] = DatoProducto[COD];
    Registro[CANTIDAD] = retorna_referencia_a_entero(cantidad);
    Registro[TOTAL] = retorna_referencia_a_real(*(double *) DatoProducto[PRECIO] * cantidad);
    return Registro;
}
void imprimereporte(void *Clientes){
    ofstream arch ("ReporteDePedidos.txt");
    void **ArrClientes = (void **) Clientes;
    for(int i=0;ArrClientes[i];i++){
        void **DatoCliente = (void **) ArrClientes[i];
        ImprimirLinea(arch,'=',80);
        arch<<left<<setw(20)<<"DNI"<<setw(50)<<"Nombre"<<"Credito"<<endl;
        arch<<left<<setw(20)<<*(int *)DatoCliente[DNI]<<setw(50)<<(char *)DatoCliente[NOMBRE]<<
                *(double *)DatoCliente[LINESCRED]<<endl;
        ImprimirLinea(arch,'-',80);
        arch<<"Pedido atendidos:"<<endl;
        ImprimirLinea(arch,'-',80);
        arch<<left<<setw(10)<<"Codigo"<<setw(10)<<"Cantidad"<<"Total"<<endl;
        ImprimirLinea(arch,'-',80);
        if(DatoCliente[LISTAPED] != nullptr) ImprimirListaDePedidos(DatoCliente[LISTAPED],arch);
        arch<<endl;
    }
}
void ImprimirListaDePedidos(void * ListaPedidos,ofstream &arch){
    void **Lista = (void **) ListaPedidos;
    for(int i=0;Lista[i];i++){
        void **DatoPedido = (void **) Lista[i];
        arch<<left<<setw(10)<<(char *)DatoPedido[CODPRO]<<right<<setw(3)<<*(int *)DatoPedido[CANTIDAD]<<
                setw(12)<<*(double *)DatoPedido[TOTAL]<<endl;
    }
    
}
void ImprimirLinea(ofstream &arch, char c, int n){
    for(int i=0;i<n;i++) arch<<c;
    arch<<endl;
}