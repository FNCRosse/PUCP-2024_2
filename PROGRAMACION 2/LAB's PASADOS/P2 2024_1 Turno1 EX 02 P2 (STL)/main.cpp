/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de noviembre de 2024, 17:25
 */

#include <iostream>

#include "Biblioteca.h"
using namespace std;

int main(int argc, char** argv) {
    Biblioteca bli;
    bli.carga_libros("Libros.csv");
    bli.carga_autores("Autores.csv");
    bli.carga_clientes("Clientes.csv");
    bli.MostrarRecomendaciones("Reporte.txt");
    return 0;
}

