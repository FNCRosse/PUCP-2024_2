/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PunteroVoid.cpp
 * Author: Rosse
 * 
 * Created on 2 de octubre de 2024, 21:14
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "PunteroVoid.h"
#include "Comunes.hpp"
enum Venta {COD,NOMB,AUTOR,LIBVEN,SUMA,PROM,RANKG};
void * AgregarDatosLibro(char **DatosLibro){
    void **Registro = new void *[7];
    Registro[COD] = mi_strdup(DatosLibro[0]);
    Registro[NOMB] = mi_strdup(DatosLibro[1]);
    Registro[AUTOR] = mi_strdup(DatosLibro[2]);
    Registro[LIBVEN] = retorna_referencia_a_entero(0);
    Registro[SUMA] = retorna_referencia_a_entero(0);
    Registro[PROM] = retorna_referencia_a_real(0);
    Registro[RANKG] = retorna_referencia_a_entero(0);
    return Registro;
}
void cargarVentas(char ***Libro,void *& ventas){
    void  **ArrVentas,*Buff[300];
    int i;
    for( i=0;Libro[i];i++){
        Buff[i] = AgregarDatosLibro(Libro[i]);
    }
    ArrVentas = new void *[i+1]{};
    for(int k=0;k<i;k++) ArrVentas[k] = Buff[k];
    ventas = ArrVentas;
}
void actualizarVentas(int **ventasDniFechaPuntaje, char **VentasLibroCodigo, void *&ventas){
    void **ArrVentas = (void **)ventas;
    int posVentas;
    for(int i=0;VentasLibroCodigo[i];i++){
        int *DatoEntetos = ventasDniFechaPuntaje[i];
        posVentas = BuscarVenta(ArrVentas,VentasLibroCodigo[i]);
        if(posVentas != -1){
            AgregarDatos(DatoEntetos[2],ArrVentas[posVentas]);
        }
    }
}
void AgregarDatos(int puntaje,void *&Venta){
    void **DatoVenta = (void **)Venta;
    int * Cantidad = (int *)DatoVenta[LIBVEN];
    int * Suma_ant = (int *)DatoVenta[SUMA];
    DatoVenta[LIBVEN] =retorna_referencia_a_entero(*Cantidad+1);
    DatoVenta[SUMA] = retorna_referencia_a_entero(*Suma_ant+puntaje);
    double promedio = *(int *)DatoVenta[SUMA]/(*(int *)DatoVenta[LIBVEN]);
    DatoVenta[PROM]  = retorna_referencia_a_real(promedio);
    if(promedio<30) DatoVenta[RANKG] = retorna_referencia_a_entero(1);
    if(promedio>= 30 and promedio<70) DatoVenta[RANKG] = retorna_referencia_a_entero(2);
    if(promedio>=70) DatoVenta[RANKG] = retorna_referencia_a_entero(3);
}
int BuscarVenta(void *Ventas,char *LibroCodigo){
    void **ArrVentas = (void **)Ventas;
    for(int i=0;ArrVentas[i];i++){
        void **DatoVenta = (void **)ArrVentas[i];
        char * codigo = (char*) DatoVenta[COD];
        if(strcmp(LibroCodigo,codigo)==0) return i;
    }
    return -1;
}
