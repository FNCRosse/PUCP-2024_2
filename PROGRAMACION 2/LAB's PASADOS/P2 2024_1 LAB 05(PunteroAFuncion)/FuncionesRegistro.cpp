/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesRegistro.cpp
 * Author: Rosse
 * 
 * Created on 22 de octubre de 2024, 08:21
 */

#include <cstring>
#include <iomanip>

#include "FuncionesRegistro.h"
char *ConvertirPtrCadena(char *codigo){
    char *ptr;
    ptr = new char[strlen(codigo)+1];
    strcpy(ptr,codigo);
    return ptr;
}
void* leerRegistro (ifstream &arch){
    void **Registro = new void *[3];
    int *num = new int,*dni = new int;
    char codigo[8];
    arch>>*num; arch.get();
    arch>>*dni; arch.get();
    arch.getline(codigo,8,'\n');
    Registro[0] = num;
    Registro[1] = dni;
    Registro[2] = ConvertirPtrCadena(codigo);
    return Registro;
}
void imprimeRegistro(ofstream &arch ,void *Pedido){
    if(Pedido == nullptr) return;
    void **DatoPedido = (void **)Pedido;
    arch<<left<<setw(5)<<*(int*)DatoPedido[0]<<setw(10)<<*(int*)DatoPedido[1]<<(char*)DatoPedido[2]<<endl;
}
bool cmpRegistro (const void *a,const void *b){
    void **DatoPedidoA = (void **)a;
    void **DatoPedidoB = (void **)b;
    return *(int*)DatoPedidoA[0] < *(int*)DatoPedidoB[0];
}