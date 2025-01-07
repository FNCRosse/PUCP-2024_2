/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de septiembre de 2024, 18:18
 */

#include "PunterosGenericos.h"
#include "AperturaDeArchivos.h"
#include "MuestraPunteroGenerico.h"
using namespace std;

int main(int argc, char** argv) {
    void *clientes, *reserva;
    cargaClientes(clientes);
    muestraclientes(clientes);
    cargaReserva(reserva);
    muestrareservas(reserva);
    CargaRerservar(clientes,reserva);
    reportefinal(reserva);
    return 0;
}

