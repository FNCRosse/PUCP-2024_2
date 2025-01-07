/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de octubre de 2024, 21:00
 */

#include <iostream>
using namespace std;
#include "PunteroMultiples1Examen01Pregunta1.h"
#include "PunteroVoid.h"

int main(int argc, char** argv) {
    char **VentasLibroCodigo,***Libro;
    int **ventasDniFechaPuntaje;
    cargaVenta (VentasLibroCodigo,ventasDniFechaPuntaje,"Ventas.csv");
    cargaLibros(Libro,"Libros.csv");
    
    void *ventas;
    cargarVentas(Libro,ventas);
    actualizarVentas(ventasDniFechaPuntaje,VentasLibroCodigo,ventas);
    
    return 0;
}

