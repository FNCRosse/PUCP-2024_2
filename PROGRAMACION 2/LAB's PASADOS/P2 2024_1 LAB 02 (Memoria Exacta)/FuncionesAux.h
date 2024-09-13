/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesAux.h
 * Author: Rosse
 *
 * Created on 12 de septiembre de 2024, 15:57
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
#include "Util.h"
bool operator >>(ifstream &arch, char**&buff_Lib);
void operator >>(ifstream &arch, int*&buff_Lib);
char* LeerCadena(ifstream &arch,char letra);
int BuscarCliente(int dni,int **Buff_PedCliente);
int BuscarLibro(const char* cod, char ***Libros) ;
int *ColocarPedidos(int dni,int numPed,int posCliente,int *&Buff_PedCliente);
void AgregarLibros(ifstream &arch,char**&Buff_PedLibros,bool *&Buff_PedAten,char ***Libros, int **&Stock);
void ColocarMemoriaExacta(int **&PedidosClientes,
        char ***&PedidosLibros, bool **&PedidosAtendidos,int **Buff_PedCliente,bool **Buff_PedAten,
            char ***Buff_PedLibros,int nd,int cantPed);
bool VerificarAtendido(char *cod, char ***Libros, int **&Stock);
#endif /* FUNCIONESAUX_H */
