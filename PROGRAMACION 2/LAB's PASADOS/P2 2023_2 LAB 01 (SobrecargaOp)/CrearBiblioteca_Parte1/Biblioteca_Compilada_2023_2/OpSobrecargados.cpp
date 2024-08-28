/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   OpSobrecargados.cpp
 * Author: Rosse
 * 
 * Created on 22 de agosto de 2024, 08:34
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "OpSobrecargados.h"
#include "Estructuras.h"

//LECTURA
bool operator >>(ifstream &arch, struct Cliente & cli){
    arch>>cli.dni;
    if(arch.eof()) return false;
    arch.get();
    arch.getline(cli.nombre,60,',');
    arch>>cli.telefono;
    arch.get();
    cli.montoTotal=0;
    cli.cantidadProductosEntrgados=0;
    return true;
}
bool operator >>(ifstream &arch, struct Producto & pro){
    arch.getline(pro.codigo,8,',');
    if(arch.eof()) return false;
    arch.getline(pro.descripcion,60,',');
    arch>>pro.precio;
    arch.get();
    arch>>pro.stock;
    arch.get();
    pro.cantidadClientesNoServidos =0;
    pro.cantidadClientesServidos=0;
    return true;
}
bool operator >>(ifstream &arch, struct Pedido & ped){
    arch.getline(ped.CodigoProducto,8,',');
    if(arch.eof()) return false;
    arch>>ped.dniCliente;
    arch.get();
    ped.precioProducto=0;
    return true;
}

//AGREGACION
void operator += (struct Cliente *ArrCli, const struct Pedido &ped){
    for(int i=0;ArrCli[i].dni != 0;i++){
        if(ArrCli[i].dni == ped.dniCliente){
            struct ProductoEntregado pro;
            strcpy(pro.codigo,ped.CodigoProducto);
            pro.precio = ped.precioProducto;
            ArrCli[i].productosEntregados[ArrCli[i].cantidadProductosEntrgados] = pro;
            ArrCli[i].cantidadProductosEntrgados++;
            break;
        }
    }
}
bool operator += (struct Producto* ArrPro, struct Pedido &ped){
    for(int i=0;strcmp(ArrPro[i].codigo,"XXXXXXX")!=0;i++){
        if(strcmp(ArrPro[i].codigo,ped.CodigoProducto)==0){
            if(ArrPro[i].stock>0){
                ArrPro[i].stock--;
                ped.precioProducto = ArrPro[i].precio;
                ArrPro[i].clientesServidos[ArrPro[i].cantidadClientesServidos] = ped.dniCliente;
                ArrPro[i].cantidadClientesServidos++;
                return true;
            } else {
                ArrPro[i].stock = 0;
                ArrPro[i].clientesNoServidos[ArrPro[i].cantidadClientesNoServidos] = ped.dniCliente;
                ArrPro[i].cantidadClientesNoServidos++;
                return false;
            }
        }
    }
    return false;
}

//IMPRESION
void operator << (ofstream &arch, const struct Cliente &cli){
    arch<<left<<setw(10)<<cli.dni<<setw(45)<<cli.nombre<<setw(12)<<cli.telefono<<setw(10)<<cli.montoTotal;
    arch<< setw(20)<<"Productos Entregados: ";
    if(cli.cantidadProductosEntrgados == 0)  arch<<"NO SE LE ENTREGARON PRODUCTOS";
    for(int i=0;i<cli.cantidadProductosEntrgados;i++){
        arch<<cli.productosEntregados[i].codigo<<"   ";
    }
    arch<<endl;
}
void operator << (ofstream &arch, const struct Producto &pro){
    arch<<left<<setw(10)<<pro.codigo<<setw(55)<<pro.descripcion<<setw(12)<<pro.precio<<pro.stock<<endl;
    arch<< setw(24)<<"Clientes Atendidos: ";
    if(pro.cantidadClientesServidos == 0)  arch<<"NO SE ATENDIERON PEDIDOS";
    for(int i=0;i<pro.cantidadClientesServidos;i++) arch<<pro.clientesServidos[i]<<"   ";
    arch<<endl;
    arch<< setw(24)<<"Clientes no Atendidos: ";
    if(pro.cantidadClientesNoServidos == 0)  arch<<"NO HAY CLIENTES SIN ATENDER";
    for(int i=0;i<pro.cantidadClientesNoServidos;i++) arch<<pro.clientesNoServidos[i]<<"   ";
    arch<<endl<<endl;
}