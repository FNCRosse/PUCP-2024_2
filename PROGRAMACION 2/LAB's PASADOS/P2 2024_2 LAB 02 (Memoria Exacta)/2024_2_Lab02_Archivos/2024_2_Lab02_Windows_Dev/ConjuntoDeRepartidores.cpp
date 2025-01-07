/* 
 * Archivo: ConjuntoDeRepartidores.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 00:44
 */

#include <iostream>
#include <fstream>
#include "ConjuntoDeRepartidores.hpp"
#include "AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores, const char *nombre_de_archivo) {
    ifstream archivo_de_repartidores;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_repartidores, nombre_de_archivo);
    archivo_de_repartidores >> conjuntoDeRepartidores;
    archivo_de_repartidores.close();
}

void operator>>(istream &archivo_de_repartidores, ConjuntoDeRepartidores &conjuntoDeRepartidores) {
    struct Repartidor Buff[120];
    int nd = 0;
    while (archivo_de_repartidores >> Buff[nd]) {
        nd++;
    }
    conjuntoDeRepartidores.conjunto_de_datos = new struct Repartidor [nd + 1]{};
    conjuntoDeRepartidores.cantidad = nd;
    for (int i = 0; i < nd; i++)conjuntoDeRepartidores.conjunto_de_datos[i] = Buff[i];
}

void liberar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores) {
    for (int i = 0; i < conjuntoDeRepartidores.cantidad ; i++) {
        delete [] conjuntoDeRepartidores.conjunto_de_datos[i].codigo;
        delete [] conjuntoDeRepartidores.conjunto_de_datos[i].nombre;
        delete [] conjuntoDeRepartidores.conjunto_de_datos[i].vehiculo;
    }
}