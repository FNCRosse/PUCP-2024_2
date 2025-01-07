/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesEnteras.cpp
 * Author: Rosse
 * 
 * Created on 22 de octubre de 2024, 08:21
 */

#include "FuncionesEnteras.h"
void* leenum (ifstream &arch){
    int *num = new int,dato;
    arch >>dato;
    *num = dato;
    return num;
}
void imprimenum(ofstream &arch ,void *Pedido){
    if(Pedido == nullptr) return;
    arch<<*(int*) Pedido<<endl;
}
bool cmpnum (const void *a,const void *b){
    int enteroA  = *(int*) a;
    int enteroB  = *(int*) b;
    return enteroA<enteroB;
}