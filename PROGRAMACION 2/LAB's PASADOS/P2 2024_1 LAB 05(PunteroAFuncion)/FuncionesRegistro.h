/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesRegistro.h
 * Author: Rosse
 *
 * Created on 22 de octubre de 2024, 08:21
 */

#ifndef FUNCIONESREGISTRO_H
#define FUNCIONESREGISTRO_H

#include <fstream>
using namespace std;
void* leerRegistro (ifstream &arch);
char *ConvertirPtrCadena(char *codigo);
void imprimeRegistro(ofstream &arch ,void *Pedido);
bool cmpRegistro (const void *a,const void *b);

#endif /* FUNCIONESREGISTRO_H */
