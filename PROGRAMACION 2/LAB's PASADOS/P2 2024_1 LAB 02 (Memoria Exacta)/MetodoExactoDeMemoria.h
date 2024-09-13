/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: Rosse
 *
 * Created on 12 de septiembre de 2024, 15:52
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

void lecturaDeLibros(const char*namefile, char ***&Libros, int **&Stock);
void PruebaDeLecturaDeLibros(const char*namefile, char ***Libros, int **Stock);
void atencionDePedidos(const char*namefile, char ***Libros, int **&Stock, int **&PedidosClientes,
        char ***&PedidosLibros, bool **&PedidosAtendidos);
void ReporteDeEntregaDePedidos(const char*namefile, int **PedidosClientes,
        char ***PedidosLibros, bool **PedidosAtendidos);
void imprimirLinea(ofstream &arch, char letra, int n);
void ImprimirPedido(ofstream &arch,int numPed,char**PedidosLibros,bool*PedidosAtendidos);
#endif /* METODOEXACTODEMEMORIA_H */
