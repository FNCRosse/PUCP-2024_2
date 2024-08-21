/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesAux.cpp
 * Author: Rosse
 * 
 * Created on 21 de agosto de 2024, 10:48
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesAux.h"
#include "SobreCargaOperadores.h"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"

void LeerLibros(struct Libro *ArrLib, const char* nameFile) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nameFile);
    int nd = 0;
    while (arch >> ArrLib[nd]) nd++;
    strcpy(ArrLib[nd].codigo, "FIN");
}

void LeerClientes(struct Cliente *ArrCli, const char* nameFile) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nameFile);
    int nd = 0;
    while (arch >> ArrCli[nd]) nd++;
    ArrCli[nd].dni = 0;
}

bool ClienteEncontrado(int dni, struct Cliente *ArrCli, struct Libro *ArrLib, ifstream &arch, struct LibroSolicitado &libsol) {
    char CodigoLibro[8];
    for (int i = 0; ArrCli[i].dni != 0; i++) {
        if (ArrCli[i].dni == dni) {
            while (true) {
                arch>>CodigoLibro;
                strcpy(libsol.codigoDelLibro, CodigoLibro);
                libsol >> ArrLib;
                ArrCli[i] << libsol;
                if (arch.get() == '\n') break;
            }
            ++ArrCli[i];
            return true;
        }
    }
    return false;
}

void ColocarPedidos(struct Cliente *ArrCli, struct Libro *ArrLib, const char* nameFile) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nameFile);
    struct LibroSolicitado libsol;
    int dni;
    while (true) {
        arch >> libsol.numeroDePedido;
        if (arch.eof()) break;
        arch.get();
        arch>>dni;
        arch.get();
        if (!ClienteEncontrado(dni, ArrCli, ArrLib, arch, libsol)) while (arch.get() != '\n');
    }
}

void ImprimirReporte(const struct Cliente *ArrCli, const struct Libro *ArrLib, const char* nameFile) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nameFile);
    arch.precision(2);
    arch << fixed;
    arch << right << setw(30) << "REPORTE DE CLIENTES" << endl;
    arch << left;
    for (int i = 0; ArrCli[i].dni != 0; i++) arch << ArrCli[i];
    arch << right << setw(60) << "REPORTE DE LIBROS" << endl;
    arch << left;
    for (int i = 0; strcmp(ArrLib[i].codigo, "FIN") != 0; i++) arch << ArrLib[i];
}