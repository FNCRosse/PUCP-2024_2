/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de noviembre de 2024, 14:49
 */

#include <iostream>

#include "Flota.h"
using namespace std;

int main(int argc, char** argv) {
    Flota unidades;
    unidades.CargaFlota();
    unidades.CargaPedido();
    unidades.MuestraCarga();
    return 0;
}

