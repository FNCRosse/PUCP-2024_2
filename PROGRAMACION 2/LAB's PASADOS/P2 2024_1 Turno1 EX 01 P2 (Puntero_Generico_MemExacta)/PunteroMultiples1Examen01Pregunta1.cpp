/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PunteroMultiples1Examen01Pregunta1.cpp
 * Author: Rosse
 * 
 * Created on 2 de octubre de 2024, 19:52
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "PunteroMultiples1Examen01Pregunta1.h"
#include "AperturaDeArchivos.h"
#include "Comunes.hpp"
#define INCREMENTO 5

void inicializarVentas(char **&VentasLibroCodigo, int **&ventasDniFechaPuntaje, int capacidad) {
    VentasLibroCodigo = new char*[capacidad] {};
    ventasDniFechaPuntaje = new int*[capacidad] {};
    for (int i = 0; i < capacidad; i++) {
        VentasLibroCodigo[i] = nullptr;
        ventasDniFechaPuntaje[i] = nullptr;
    }
}
void incrementarEspaciosVentas(char **&VentasLibroCodigo, int **&ventasDniFechaPuntaje, int &capacidad){
    char **Ventas_Libros_ant = VentasLibroCodigo;
    int **Ventas_enteros = ventasDniFechaPuntaje;
    int cap_ant = capacidad;
    capacidad += INCREMENTO;
    VentasLibroCodigo = new char*[capacidad] {};
    ventasDniFechaPuntaje = new int*[capacidad] {};
    for (int i = 0; i < capacidad; i++) {
        if (i < cap_ant){
            VentasLibroCodigo[i] = Ventas_Libros_ant[i];
            ventasDniFechaPuntaje[i] = Ventas_enteros[i];
        }
        else{
            VentasLibroCodigo[i] = nullptr;
            ventasDniFechaPuntaje[i] = nullptr;
        }
    }
}
int *LeerDatosEnteros(ifstream& arch){
    int * datos = new int [3],dni,aa,mm,dd,puntaje;
    char c;
    arch>>dni>>c>>dd>>c>>mm>>c>>aa>>c>>puntaje;
    arch.get();
    datos[0] = dni;
    datos[1] = aa*10000+mm*100+dd;
    datos[2] = puntaje;
    return datos;
}
//CRY6839,34460612,15/10/2023,93
void cargaVenta(char **&VentasLibroCodigo, int **&ventasDniFechaPuntaje, const char *namefile) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, namefile);
    int capacidad = INCREMENTO, nd = 0;
    char DatoLibro[8];
    inicializarVentas(VentasLibroCodigo,ventasDniFechaPuntaje,capacidad);
    while (true) {
        arch.getline(DatoLibro,8,',');
        if(arch.eof()) break;
        if (capacidad == nd) incrementarEspaciosVentas(VentasLibroCodigo,ventasDniFechaPuntaje, capacidad);
        VentasLibroCodigo[nd] = mi_strdup(DatoLibro);
        ventasDniFechaPuntaje[nd] = LeerDatosEnteros(arch);
        nd++;
    }
    if (capacidad == nd) incrementarEspaciosVentas(VentasLibroCodigo,ventasDniFechaPuntaje, capacidad);
    VentasLibroCodigo[nd] = nullptr;
    ventasDniFechaPuntaje[nd] = nullptr;
}

void PruebaDeCargaDeVenta(char **VentasLibroCodigo, int **ventasDniFechaPuntaje, const char *namefile) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, namefile);
    for (int i = 0; ventasDniFechaPuntaje[i]; i++) {
        char * codLibro = VentasLibroCodigo[i];
        int *datosventa = ventasDniFechaPuntaje[i];
        arch << left << setw(10) << codLibro << setw(15) << datosventa[0] <<setw(15)<< datosventa[1]
                << datosventa[2]<<endl;
    }
}

//IIM5175,Diamantes y pedernales,Jose Maria Arguedas


bool operator>>(ifstream &arch, char **&datolibro) {
    datolibro = new char *[3];
    char codigo[8], titulo[80], autor[60];
    arch.getline(codigo, 8, ',');
    if (arch.eof()) return false;
    arch.getline(titulo, 80, ',');
    arch.getline(autor, 60, '\n');
    datolibro[0] = mi_strdup(codigo);
    datolibro[1] = mi_strdup(titulo);
    datolibro[2] = mi_strdup(autor);
    return true;
}

void incrementarEspaciosLibro(char ***&Libro, int &capacidad) {
    char ***Libros_ant = Libro;
    int cap_ant = capacidad;
    capacidad += INCREMENTO;
    Libro = new char**[capacidad] {};
    for (int i = 0; i < capacidad; i++) {
        if (i < cap_ant) Libro[i] = Libros_ant[i];
        else Libro[i] = nullptr;
    }
}

void cargaLibros(char ***&Libro, const char *namefile) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, namefile);
    int capacidad = INCREMENTO, nd = 0;
    char **DatoLibro;
    Libro = new char**[capacidad] {
    };
    for (int i = 0; i < capacidad; i++) Libro[i] = nullptr;
    while (arch >> DatoLibro) {
        if (capacidad == nd) incrementarEspaciosLibro(Libro, capacidad);
        Libro[nd] = DatoLibro;
        nd++;
    }
    if (capacidad == nd) incrementarEspaciosLibro(Libro, capacidad);
    Libro[nd] = nullptr;
}

void pruebaDeCargaDeLibros(char ***Libro, const char *namefile) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, namefile);
    for (int i = 0; Libro[i]; i++) {
        char **datosLibro = Libro[i];
        arch << left << setw(10) << datosLibro[0] << setw(60) << datosLibro[1] << datosLibro[2] << endl;
    }
}