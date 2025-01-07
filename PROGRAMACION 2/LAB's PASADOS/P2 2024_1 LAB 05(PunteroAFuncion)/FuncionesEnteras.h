/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesEnteras.h
 * Author: Rosse
 *
 * Created on 22 de octubre de 2024, 08:21
 */

#ifndef FUNCIONESENTERAS_H
#define FUNCIONESENTERAS_H
#include <fstream>
using namespace std;
void* leenum (ifstream &arch);
void imprimenum(ofstream &arch ,void *Pedido);
bool cmpnum (const void *a,const void *b);

#endif /* FUNCIONESENTERAS_H */
