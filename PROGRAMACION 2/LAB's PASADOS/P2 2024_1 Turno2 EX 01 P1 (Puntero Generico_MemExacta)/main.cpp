/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de octubre de 2024, 18:36
 */
#include <iostream>
#include "PunteroVoid.h"
#include "MuestraVoid.h"
using  namespace std;

int main(int argc, char** argv) {
    void *ventas;
  
    cargaLibros(ventas);
    cargaventas(ventas);
    muestraventas(ventas);

    return 0;
}

