/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: Rosse
 *
 * Created on 25 de septiembre de 2024, 09:35
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

void lecturaDeLibros(const char *namefile, char ***&Libros, int **&Stock);
void PrubaDeLecturaDeLibros(const char *namefile, char ***Libros, int **Stock);

void AtencionDePedidos(const char *namefile, char ***Libros, int **&Stock, int **&PedidosClientes,
        char ***&PedidoLibros, bool **&PedidosAtendidos);
void OrdenarPedidosClientes(int **&PedidosClientes);
void reporteDeEntregaDePedidos(const char *namefile, int **PedidosClientes, char ***PedidoLibros,
        bool **PedidosAtendidos);

bool operator >> (ifstream &arch, char**&datosLib);
void operator >> (ifstream &arch, int *&datosStock);
void inicializacionDatosLibros(char ***&Libros,int &capLib,int **&Stock,int &capStock);
char *mi_strdup(const char *cadena) ;
void incrementarLibros(int &capLib,char ***&Libros);
void incrementarStock(int &capStock,int **&Stock);

void InicializacionPedidosCliente(int &capCli, int **&PedidosClientes, int *&capacidadesCli);
void InicializacionPedidosLibYAte(int &capLib, char ***&PedidoLibros, bool **&PedidosAtendidos);
void incluirPedido(int **&PedidosClientes, int posicion, int dni, int numPed, int &capacidad);
void LeerEIncluirLibroyAtendido(char ***&PedidoLibros, bool **&PedidosAtendidos, char ***Libros, int **&Stock,
        int &capLib,int , ifstream &arch);
int BuscarCliente(int **&PedidosClientes, int dni);
void incrementarDatosClientes(int &capacidad,int *&DatoCliente);
void incrementarPedidoLibrosYAte(char ***&PedidoLibros, bool **&PedidosAtendidos, int &capLib,int numped);
void insertarLibro(char ***Libros, int **&Stock,char* codigo,char ***&PedidoLibros, bool **&PedidosAtendidos,int );
bool ValidarLibro(char ***Libros, int **&Stock,char *codigo);
int buscarLibro(char ***Libros,char *codigo);
int ContarLibros(char ** buffer_pedLib);
void IncrementarPedidoCliente(int &capCli, int **&PedidosClientes, int *&capacidadesCli);
int ContarDatoscliente(int *DatoCliente);
void  imprimirLibros(char **PedidoLibros,bool *PedidosAtendidos,ofstream &arch);
void inicializarDatosClientes(int &capacidad,int *&DatoCliente);
#endif /* METODOEXACTODEMEMORIA_H */
