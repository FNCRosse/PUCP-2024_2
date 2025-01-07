/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de octubre de 2024, 09:51
 */

#include <iostream>
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"
#include "FlotaGenerica.h"
using namespace std;

int main(int argc, char** argv) {
    int numCamiones;
    double pesoMaximo;
    void *flota;
    
    numCamiones = 5; pesoMaximo = 10;
    cargaCamiones(flota,numCamiones,pesoMaximo,leeNumero,calculaNumero,"numeros.txt");
    qsort(flota,numCamiones,sizeof(void*),cmpNumero);
    muestraCamiones(flota,numCamiones,imprimenumero,"reportenum.txt");
    
    numCamiones = 100; pesoMaximo = 400;
    cargaCamiones(flota,numCamiones,pesoMaximo,leeRegistro,calculaRegistro,"Pedidos3.csv");
    qsort(flota,numCamiones,sizeof(void*),cmpRegistro);
    muestraCamiones(flota,numCamiones,imprimeRegistro,"ReporteRegistro.txt");

    return 0;
}

