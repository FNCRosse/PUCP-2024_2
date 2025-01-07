/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PunteroVoid.cpp
 * Author: Rosse
 * 
 * Created on 2 de octubre de 2024, 18:39
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "PunteroVoid.h"
#include "AperturaDeArchivos.h"
#include "Comunes.hpp"

enum ventas {COD, NOMB, AUTOR, ARREGLO, LIBVEN, SUMA, PROM, RANK};
//IIM5175,Diamantes y pedernales,Jose Maria Arguedas
bool operator>>(ifstream &arch, void *&reg) {
    void **Registro = new void *[8];
    char codigo[8], titulo[80], autor[60];
    arch.getline(codigo, 8, ',');
    if (arch.eof()) return false;
    arch.getline(titulo, 80, ',');
    arch.getline(autor, 60, '\n');
    Registro[COD] = mi_strdup(codigo);
    Registro[NOMB] = mi_strdup(titulo);
    Registro[AUTOR] = mi_strdup(autor);
    Registro[ARREGLO] = nullptr;
    Registro[LIBVEN] = retorna_referencia_a_entero(0);
    Registro[SUMA] = retorna_referencia_a_entero(0);
    Registro[PROM] = retorna_referencia_a_real(0);
    Registro[RANK] = retorna_referencia_a_entero(0);
    reg = Registro;
    return true;
}

void cargaLibros(void *&ventas) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Libros.csv");
    void *reg, **ArrVentas, *Buff[300];
    int nd = 0;
    while (arch >> reg) {
        Buff[nd] = reg;
        nd++;
    }
    ArrVentas = new void *[nd + 1] {};
    for (int i = 0; i < nd; i++) ArrVentas[i] = Buff[i];
    ventas = ArrVentas;
}
//CRY6839,34460612,15/10/2023,93

void cargaventas(void *&ventas) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Ventas.csv");
    void **ArrVentas = (void **) ventas;
    char codigo[8];
    int posVenta, dni, puntaje;
    while (true) {
        arch.getline(codigo, 8, ',');
        if (arch.eof()) break;
        arch>>dni;
        arch.get();
        while (arch.get() != ',');
        arch>>puntaje;
        arch.get();
        posVenta = BuscarVenta(ArrVentas, codigo);
        if (posVenta != -1) ColocarVenta(ArrVentas[posVenta], dni, puntaje);
    }
}

int BuscarVenta(void **ArrVentas, char *codigo) {
    for (int i = 0; ArrVentas[i]; i++) {
        void **DatoVenta = (void **) ArrVentas[i];
        char *cod = (char*) DatoVenta[COD];
        if (strcmp(cod, codigo) == 0) return i;
    }
    return -1;
}

void ColocarVenta(void *&Venta, int dni, int puntaje) {
    void **DatoVenta = (void **) Venta;
    void **ArregloVenta;
    if (DatoVenta[ARREGLO] == nullptr) {
        ArregloVenta = new void *[1] {};
        ArregloVenta[0] = retorna_referencia_a_entero(dni);
        DatoVenta[LIBVEN] = retorna_referencia_a_entero(1);
        ActualizarDatosDeVenta(puntaje, DatoVenta);
    } else {
        int * cantidad = (int *)DatoVenta[LIBVEN];
        void** Arr_anterior = (void**) DatoVenta[ARREGLO];
        ArregloVenta = new void *[*cantidad+2]{};
        for(int i=0;i<*cantidad;i++){
            ArregloVenta[i] = Arr_anterior[i];
        }
        ArregloVenta[*cantidad] = retorna_referencia_a_entero(dni);
        DatoVenta[LIBVEN] = retorna_referencia_a_entero(*cantidad+1);
        ArregloVenta[*cantidad+1] =nullptr;
        ActualizarDatosDeVenta(puntaje, DatoVenta);
    }
    DatoVenta[ARREGLO] = ArregloVenta;
}

void ActualizarDatosDeVenta(int puntaje, void **&DatoVenta) {
    int * suma_ant = (int *) DatoVenta[SUMA];
    DatoVenta[SUMA] = retorna_referencia_a_entero(*suma_ant+puntaje);
    double promedio = *(int*) DatoVenta[SUMA] / (*(int*) DatoVenta[LIBVEN]);
    DatoVenta[PROM] = retorna_referencia_a_real(promedio);
    if (promedio < 30) DatoVenta[RANK] = retorna_referencia_a_entero(1);
    if (promedio >= 30 and promedio < 70) DatoVenta[RANK] = retorna_referencia_a_entero(2);
    if (promedio >= 70) DatoVenta[RANK] = retorna_referencia_a_entero(3);
}