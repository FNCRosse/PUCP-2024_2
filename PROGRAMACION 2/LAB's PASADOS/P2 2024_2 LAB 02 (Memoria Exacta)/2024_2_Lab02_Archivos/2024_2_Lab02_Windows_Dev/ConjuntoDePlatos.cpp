/* 
 * Archivo: ConjuntoDePlatos.cpp
 * Autor: Andrés Melgar
 * Fecha: 30 de agosto de 2024, 22:50
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "ConjuntoDePlatos.hpp"
#include "AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_platos(ConjuntoDePlatos &conjuntoDePlatos, const char *nombre_de_archivo) {
    ifstream archivo_de_platos;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_platos, nombre_de_archivo);
    archivo_de_platos >> conjuntoDePlatos;
    archivo_de_platos.close();
}

void operator>>(istream &archivo_de_platos, ConjuntoDePlatos &conjuntoDePlatos) {
    struct Plato Buff[120];
    int nd = 0;
    while (archivo_de_platos >> Buff[nd]) {
        nd++;
    }
    conjuntoDePlatos.conjunto_de_datos = new struct Plato [nd + 1]{};
    conjuntoDePlatos.cantidad = nd;
    for (int i = 0; i < nd; i++)conjuntoDePlatos.conjunto_de_datos[i] = Buff[i];
}

void liberar_conjunto_de_platos(ConjuntoDePlatos &conjuntoDePlatos) {
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        delete [] conjuntoDePlatos.conjunto_de_datos[i].codigo;
        delete [] conjuntoDePlatos.conjunto_de_datos[i].nombre;
        delete [] conjuntoDePlatos.conjunto_de_datos[i].tipo;
        conjuntoDePlatos.conjunto_de_datos[i].precio =0;
    }
}

double operator+=(const ConjuntoDePlatos &conjuntoDePlatos, const char *codigo) {
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        if (strcmp(conjuntoDePlatos.conjunto_de_datos[i].codigo, codigo) == 0)
            return conjuntoDePlatos.conjunto_de_datos[i].precio;
    }
}

char* operator==(const ConjuntoDePlatos &conjuntoDePlatos, const char *codigo) {
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        if (strcmp(conjuntoDePlatos.conjunto_de_datos[i].codigo, codigo) == 0)
            return conjuntoDePlatos.conjunto_de_datos[i].nombre;
    }
    return nullptr;
}