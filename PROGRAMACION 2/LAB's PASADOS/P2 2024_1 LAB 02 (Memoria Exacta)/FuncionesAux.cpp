/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesAux.cpp
 * Author: Rosse
 * 
 * Created on 12 de septiembre de 2024, 15:57
 */
#include "Util.h"
#include "FuncionesAux.h"
#define NO_ENCONTRADO -1
//IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23

bool operator>>(ifstream &arch, char**&buff_Lib) {
    char *codigo, *nombre, *autor;
    codigo = LeerCadena(arch, ',');
    if (arch.eof()) return false;
    nombre = LeerCadena(arch, ',');
    autor = LeerCadena(arch, ',');
    buff_Lib = new char*[3];
    buff_Lib[0] = codigo;
    buff_Lib[1] = nombre;
    buff_Lib[2] = autor;
    return true;
}

void operator>>(ifstream &arch, int*&buff_stock) {
    buff_stock = new int [2];
    int stock;
    arch>>stock;
    while (arch.get() != '\n');
    buff_stock[0] = stock;
    buff_stock[1] = 0;
}

char* LeerCadena(ifstream &arch, char letra) {
    char cadena[110], *ptrcad;
    arch.getline(cadena, 110, letra);
    ptrcad = new char[strlen(cadena) + 1];
    strcpy(ptrcad, cadena);
    return ptrcad;
}

char* LeerCadena2(ifstream &arch) {
    char cadena[10], *ptrcad;
    arch>>cadena;
    ptrcad = new char[strlen(cadena) + 1];
    strcpy(ptrcad, cadena);
    return ptrcad;
}

int BuscarCliente(int dni, int **Buff_PedCliente) {
    for (int i = 0; Buff_PedCliente[i]; i++) {
        int *DatoCliente = Buff_PedCliente[i];
        if (DatoCliente[0] == dni) return i;
    }
    return NO_ENCONTRADO;
}
int BuscarLibro(const char* cod, char ***Libros) {
    for (int i = 0; Libros[i]; i++) {
        char **DatoLibro= Libros[i];
        if (strcmp(cod,DatoLibro[0])==0) return i;
    }
    return NO_ENCONTRADO;
}

int *ColocarPedidos(int dni, int numPed, int posCliente, int *&Buff_PedCliente) {
    int *Aux, buff[20]{}, i = 0;
    if (posCliente == NO_ENCONTRADO) {
        buff[0] = dni;
        buff[1] = 1;
        buff[2] = numPed;
        i = 3;
    } else {
        for (i = 0; i < 2 + Buff_PedCliente[1]; i++) {
            buff[i] = Buff_PedCliente[i];
        }
        delete []Buff_PedCliente;
        buff[1]++;
        buff[i] = numPed;
        i++;
    }
    Aux = new int [i] {};
    for (int k = 0; k < i; k++) Aux[k] = buff[k];
    return Aux;
}
bool VerificarAtendido(char *cod, char ***Libros, int **&Stock){
    int posLibro = BuscarLibro(cod,Libros);
    if(posLibro != NO_ENCONTRADO){
        int *DatoStock = Stock[posLibro];
        if(DatoStock[0]>0){
            DatoStock[0]--;
            return true;
        } else{
            DatoStock[0]=0;
            DatoStock[1]++;
            return false;
        }
    } 
    return false;
}
void AgregarLibros(ifstream &arch, char**&Buff_PedLibros, bool *&Buff_PedAten, char ***Libros, int **&Stock) {
    char *cod, *BuffLib[30]{};
    int nd = 0;
    bool buff_Ate[30]{};
    while (true) {
        cod = LeerCadena2(arch);
        BuffLib[nd] = cod;
        buff_Ate[nd] = VerificarAtendido(cod, Libros, Stock);
        nd++;
        if (arch.get() == '\n') break;
    }
    Buff_PedLibros = new char*[nd + 1] {};
    Buff_PedAten = new bool [nd + 1] {};
    for (int i = 0; i < nd; i++) {
        Buff_PedLibros[i] = BuffLib[i];
        Buff_PedAten[i] = buff_Ate;
    }
}

void ColocarMemoriaExacta(int **&PedidosClientes, char ***&PedidosLibros, bool **&PedidosAtendidos,
        int **Buff_PedCliente, bool **Buff_PedAten, char ***Buff_PedLibros, int nd, int cantPed) {
    PedidosClientes = new int *[nd+1]{};
    PedidosLibros = new char**[cantPed+2]{};
    PedidosAtendidos = new bool*[cantPed+2]{};
    for(int i=0;i<nd;i++)PedidosClientes[i] = Buff_PedCliente[i];
    for(int i=0;i<cantPed+1;i++){
        PedidosLibros[i] = Buff_PedLibros[i];
        PedidosAtendidos[i] = Buff_PedAten[i];
    }
}