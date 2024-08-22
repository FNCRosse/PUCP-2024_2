/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesAux.cpp
 * Author: Rosse
 * 
 * Created on 22 de agosto de 2024, 08:39
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesAux.h"
#include "Estructuras.h"
#include "OpSobrecargados.h"
#include "AperturaDeArchivos.h"

void LeerClientes(struct Cliente *arrClientes, const char* namefile) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, namefile);
    int nd = 0;
    while (arch >> arrClientes[nd]) nd++;
    arrClientes[nd].dni = 0;
}

void LeerProductos(struct Producto *arrProduc, const char* namefile) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, namefile);
    int nd = 0;
    while (arch >> arrProduc[nd]) nd++;
    strcpy(arrProduc[nd].codigo, "XXXXXXX");
}

void AgregarPedidos(struct Cliente *arrClientes, struct Producto *arrProduc, const char* namefile) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, namefile);
    struct Pedido ped;
    while (arch >> ped) {
        if (arrProduc += ped) arrClientes += ped;
    }
}

void ImprimirReporte(const struct Cliente *arrClientes, const struct Producto *arrProduc, const char* namefile) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, namefile);
    arch.precision(2);
    arch << fixed;
    arch << right << setw(30) << "LISTADO DE CLIENTES" << left << endl;
    for (int i = 0; arrClientes[i].dni != 0; i++) arch << arrClientes[i];
    arch << endl << endl;
    arch << right << setw(30) << "LISTADO DE PRODUCTOS" << left << endl;
    for (int i = 0; strcmp(arrProduc[i].codigo, "XXXXXXX") != 0; i++) arch << arrProduc[i];
}