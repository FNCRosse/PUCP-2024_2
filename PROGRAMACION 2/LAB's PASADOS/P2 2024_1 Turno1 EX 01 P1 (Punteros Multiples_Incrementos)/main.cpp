/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de octubre de 2024, 19:51
 */

#include "PunteroMultiples1Examen01Pregunta1.h"
using namespace std;

int main(int argc, char** argv) {
    char **VentasLibroCodigo,***Libro;
    int **ventasDniFechaPuntaje;
    cargaVenta (VentasLibroCodigo,ventasDniFechaPuntaje,"Ventas.csv");
    PruebaDeCargaDeVenta (VentasLibroCodigo,ventasDniFechaPuntaje,"PruebaVentas.txt");
    cargaLibros(Libro,"Libros.csv");
    pruebaDeCargaDeLibros(Libro,"PruebaLibros.txt");

    return 0;
}

