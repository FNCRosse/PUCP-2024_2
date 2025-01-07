/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: Rosse
 *
 * Created on 22 de octubre de 2024, 08:22
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H
#include <fstream>
using namespace std;
void crearLista(void *&pedido1, void *(*Leer)(ifstream &),const char* namefile);
void insertarLista(void*&pedido, void *Dato);
void imprimeLista(void *pedido1, void (*imprime)(ofstream &,void *), const char* namefile);
void CombinaLista(void *pedido1,void*pedido2,void*&pedidoFinal, bool (*cmp)(const void *,const void *));
#endif /* BIBLIOTECAGENERICA_H */
