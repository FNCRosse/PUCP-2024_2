/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   MetodoExactoDeMemoria.cpp
 * Author: Rosse
 * 
 * Created on 25 de septiembre de 2024, 09:35
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "MetodoExactoDeMemoria.h"
#include "AperturaDeArchivos.h"
#define INCREMENTO 5

char *mi_strdup(const char *cadena) {
    int tamanho_cadena = strlen(cadena);
    char *bloque_nuevo = new char[tamanho_cadena + 1];
    strcpy(bloque_nuevo, cadena);
    return bloque_nuevo;
}

bool operator>>(ifstream &arch, char**&datosLib) {
    datosLib = new char *[3];
    char buff_cod[8], buff_titulo[80], buff_Autor[60];
    arch.getline(buff_cod, 8, ',');
    if (arch.eof()) return false;
    arch.getline(buff_titulo, 80, ',');
    arch.getline(buff_Autor, 60, ',');
    datosLib[0] = mi_strdup(buff_cod);
    datosLib[1] = mi_strdup(buff_titulo);
    datosLib[2] = mi_strdup(buff_Autor);
    return true;
}

void operator>>(ifstream &arch, int *&datosStock) {
    datosStock = new int [2];
    int num;
    arch>>num;
    while (arch.get() != '\n');
    datosStock[0] = num;
    datosStock[1] = 0;
}

void inicializacionDatosLibros(char ***&Libros, int &capLib, int **&Stock, int &capStock) {
    capLib = INCREMENTO;
    capStock = INCREMENTO;
    Libros = new char **[capLib] {};
    Stock = new int *[capStock] {};
    for (int i = 0; i < capLib; i++) {
        Libros[i] = nullptr;
        Stock[i] = nullptr;
    }
}

void incrementarLibros(int &capLib, char ***&Libros) {
    char *** Buff_Lib = Libros;
    int cap_ant = capLib;
    capLib += INCREMENTO;
    Libros = new char **[capLib];
    for (int i = 0; i < capLib; i++) {
        if (i < cap_ant) Libros[i] = Buff_Lib[i];
        else Libros[i] = nullptr;
    }
    delete []Buff_Lib;
}

void incrementarStock(int &capStock, int **&Stock) {
    int ** Buff_stock = Stock;
    int cap_ant = capStock;
    capStock += INCREMENTO;
    Stock = new int *[capStock];
    for (int i = 0; i < capStock; i++) {
        if (i < cap_ant) Stock[i] = Buff_stock[i];
        else Stock[i] = nullptr;
    }
    delete [] Buff_stock;
}

void lecturaDeLibros(const char *namefile, char ***&Libros, int **&Stock) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, namefile);
    int capLib, capStock, nd = 1, *DatosStock;
    char **DatosLib;
    inicializacionDatosLibros(Libros, capLib, Stock, capStock);
    while (arch >> DatosLib) {
        arch>>DatosStock;
        if (nd == capLib) incrementarLibros(capLib, Libros);
        if (nd == capStock) incrementarStock(capStock, Stock);
        Libros[nd-1] = DatosLib;
        Stock[nd-1] = DatosStock;
        nd++;
    }
}

void PrubaDeLecturaDeLibros(const char *namefile, char ***Libros, int **Stock) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, namefile);
    for (int i = 0; Libros[i]; i++) {
        char **DatoLib = Libros[i];
        int *DatoStock = Stock[i];
        arch << left << setw(10) << DatoLib[0] << setw(60) << DatoLib[1] << setw(55) << DatoLib[2] << right << setw(5) << DatoStock[0]
                << setw(5) << DatoStock[1] << endl;
    }
}

void AtencionDePedidos(const char *namefile, char ***Libros, int **&Stock, int **&PedidosClientes,
        char ***&PedidoLibros, bool **&PedidosAtendidos) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, namefile);
    int capCli, capLib, nd = 0, *capacidadesCli, numPed, dni, PosCliente;
    InicializacionPedidosCliente(capCli, PedidosClientes, capacidadesCli);
    InicializacionPedidosLibYAte(capLib, PedidoLibros, PedidosAtendidos);
    while (true) {
        arch>>numPed;
        if (arch.eof()) break;
        arch.get();
        arch>>dni;
        if(nd == capCli) IncrementarPedidoCliente(capCli, PedidosClientes, capacidadesCli);
        PosCliente = BuscarCliente(PedidosClientes, dni);
        if (PosCliente != -1) {
            incluirPedido(PedidosClientes, PosCliente, dni, numPed, capacidadesCli[PosCliente]);
        } else {
            incluirPedido(PedidosClientes, nd, dni, numPed, capacidadesCli[nd]);
            nd++;
        }
        LeerEIncluirLibroyAtendido(PedidoLibros, PedidosAtendidos, Libros, Stock, capLib,numPed, arch);
    }
}
int BuscarCliente(int **&PedidosClientes, int dni){
    for(int i=0;PedidosClientes[i];i++){
        int *DatoCliente = PedidosClientes[i];
        if(DatoCliente[0] == dni) return i;
    }
    return -1;
}
void InicializacionPedidosCliente(int &capCli, int **&PedidosClientes, int *&capacidadesCli){
    capCli = INCREMENTO;
    PedidosClientes = new int *[capCli]{};
    capacidadesCli = new int [capCli]{};
    for(int i=0;i<capCli;i++){
        PedidosClientes[i] = nullptr;
        capacidadesCli[i] = 0;
    }
}
void IncrementarPedidoCliente(int &capCli, int **&PedidosClientes, int *&capacidadesCli){
    int **Buffer_cliente = PedidosClientes;
    int *Buffer_cap = capacidadesCli;
    int cap_ant = capCli;
    capCli += INCREMENTO;
    PedidosClientes = new int *[capCli]{};
    capacidadesCli = new int [capCli]{};
    for(int i=0;i<capCli;i++){
        if(i<cap_ant) {
            PedidosClientes[i] = Buffer_cliente[i];
            capacidadesCli[i] = Buffer_cap[i];
        }
        else{
            PedidosClientes[i] = nullptr;
            capacidadesCli[i] = 0;
        }
    }
}
void InicializacionPedidosLibYAte(int &capLib, char ***&PedidoLibros, bool **&PedidosAtendidos){
    capLib = INCREMENTO;
    PedidoLibros = new char **[capLib]{};
    PedidosAtendidos = new bool *[capLib]{};
    for(int i=0;i<capLib;i++){
        PedidoLibros[i] = nullptr;
        PedidosAtendidos[i] = nullptr;
    }
}
void inicializarDatosClientes(int &capacidad,int *&DatoCliente){
    capacidad = INCREMENTO;
    DatoCliente = new int[capacidad]{};
    for(int i=0;i<capacidad;i++){
        DatoCliente[i] = 0;
    }
}
void incluirPedido(int **&PedidosClientes, int posicion, int dni, int numPed, int &capacidad){
    int *DatoCliente = PedidosClientes[posicion];
    if(DatoCliente == nullptr) inicializarDatosClientes(capacidad,DatoCliente);
    int cantidadCli = ContarDatoscliente(DatoCliente);
    if(capacidad == cantidadCli) incrementarDatosClientes(capacidad,DatoCliente);
    if(cantidadCli == 0){
        DatoCliente[0] = dni;
        DatoCliente[1] = 1;
        DatoCliente[2] = numPed;
    } else {
        DatoCliente[cantidadCli]=numPed;
        DatoCliente[1]++;
        cantidadCli++;
    }
    if(capacidad == cantidadCli) incrementarDatosClientes(capacidad,DatoCliente);
    PedidosClientes[posicion] = DatoCliente;
}
void incrementarDatosClientes(int &capacidad,int *&DatoCliente){
    int *Buffer_dato_cliente = DatoCliente;
    int cap_ant = capacidad;
    capacidad+= INCREMENTO;
    DatoCliente = new int [capacidad]{};
    for(int i=0;i<capacidad;i++){
        if(i<cap_ant) DatoCliente[i] = Buffer_dato_cliente[i];
        else DatoCliente[i] =  0;
    }
}
int ContarDatoscliente(int *DatoCliente){
    if(DatoCliente == nullptr) return 0;
    int contador =0;
    for(int i=0;DatoCliente[i]!=0;i++){
        contador++;
    }
    return contador;
}
void LeerEIncluirLibroyAtendido(char ***&PedidoLibros, bool **&PedidosAtendidos, char ***Libros, int **&Stock,
        int &capLib,int numped, ifstream &arch){
    char codigo[8];
    while(true){
        arch>>codigo;
        if(capLib <= numped) incrementarPedidoLibrosYAte(PedidoLibros,PedidosAtendidos,capLib,numped);
        insertarLibro(Libros,Stock,codigo,PedidoLibros,PedidosAtendidos,numped);
        if(arch.get() == '\n') break;
    }
}
void incrementarPedidoLibrosYAte(char ***&PedidoLibros, bool **&PedidosAtendidos, int &capLib,int numped){
    char *** buffer_pedLib = PedidoLibros;
    bool ** Buffer_pedAte = PedidosAtendidos;
    int cap_ant = capLib;
    capLib = numped + INCREMENTO;
    PedidoLibros = new char **[capLib]{};
    PedidosAtendidos = new bool *[capLib]{};
    for(int i=0;i<capLib;i++){
        if(i<cap_ant){
            PedidoLibros[i] = buffer_pedLib[i];
            PedidosAtendidos[i] = Buffer_pedAte[i];
        } else {
            PedidoLibros[i] = nullptr;
            PedidosAtendidos[i] = nullptr;
        }
    }
    delete []buffer_pedLib;
    delete []Buffer_pedAte;
}
void insertarLibro(char ***Libros, int **&Stock,char* codigo,char ***&PedidoLibros, bool **&PedidosAtendidos,int numPed){
    char ** buffer_pedLib = PedidoLibros[numPed];
    bool * Buffer_pedAte = PedidosAtendidos[numPed];
    if(buffer_pedLib == nullptr){
        char ** Nueno_buffer_pedLib = new char *[2]{};
        bool *Nueno_buffer_pedAte = new bool [2];
        Nueno_buffer_pedLib[0] = mi_strdup(codigo);
        Nueno_buffer_pedAte[0] = ValidarLibro(Libros,Stock,codigo);
        PedidoLibros[numPed]  = Nueno_buffer_pedLib;
        PedidosAtendidos[numPed] = Nueno_buffer_pedAte;
    } else {
        int cant = ContarLibros(buffer_pedLib);
        char ** Nueno_buffer_pedLib = new char *[cant+2]{};
        bool *Nueno_buffer_pedAte = new bool [cant+2];
        for(int i=0;i<cant;i++){
            Nueno_buffer_pedLib[i] = buffer_pedLib[i];
            Nueno_buffer_pedAte[i] = Buffer_pedAte[i];
        }
        Nueno_buffer_pedLib[cant] = mi_strdup(codigo);
        Nueno_buffer_pedAte[cant] = ValidarLibro(Libros,Stock,codigo);
        PedidoLibros[numPed]  = Nueno_buffer_pedLib;
        PedidosAtendidos[numPed] = Nueno_buffer_pedAte;
    }
    delete []buffer_pedLib;
    delete []Buffer_pedAte;
}
bool ValidarLibro(char ***Libros, int **&Stock,char *codigo){
    int posLibro = buscarLibro(Libros,codigo);
    if(posLibro != -1){
        int *DatosStock = Stock[posLibro];
        if(DatosStock[0] > 0 ){
            DatosStock[0]--;
            return true;
        } else {
            DatosStock[0] = 0;
            DatosStock[1]++;
            return false;
        }
    }
    return false;
}
int ContarLibros(char ** buffer_pedLib){
    int contador =0;
    for(int i=0;buffer_pedLib[i]!= nullptr;i++){
        contador++;
    }
    return contador;
}
int buscarLibro(char ***Libros,char *codigo){
    for(int i=0;Libros[i];i++){
        char **Dato = Libros[i];
        if(strcmp(Dato[0],codigo) == 0) return i;
    }
    return -1;
}
void OrdenarPedidosClientes(int **&PedidosClientes) {
    
}

void reporteDeEntregaDePedidos(const char *namefile, int **PedidosClientes, char ***PedidoLibros,
        bool **PedidosAtendidos) {
    ofstream arch ;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,namefile);
    for(int i=0;PedidosClientes[i];i++){
        int *DatoCliente = PedidosClientes[i];
        int cant = ContarDatoscliente(DatoCliente);
        arch<<"Clientes: "<<DatoCliente[0]<<"   Cantidad Pedido: "<<cant-2<<endl;
        for(int k=2;k<cant;k++){
            arch<<DatoCliente[k] <<endl;
            imprimirLibros(PedidoLibros[DatoCliente[k]],PedidosAtendidos[DatoCliente[k]],arch);
            arch<<endl<<endl;
        }
    }
}
void  imprimirLibros(char **PedidoLibros,bool *PedidosAtendidos,ofstream &arch){
    for(int i=1;PedidoLibros[i];i++){
        arch<<PedidoLibros[i]<<"   ";
        if(PedidosAtendidos[i] == true) arch<<"ATENDIDO"<<endl;
        if(PedidosAtendidos[i] == false) arch<<"NO ATENDIDO"<<endl;
    }
}