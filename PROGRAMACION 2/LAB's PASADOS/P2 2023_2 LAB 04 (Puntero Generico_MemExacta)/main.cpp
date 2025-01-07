/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de octubre de 2024, 15:50
 */
#include "PunteroGenericos.h"
#include "MuestraPunteros.h"
using namespace std;

int main(int argc, char** argv) {
    void *Productos, *Clientes;

    CargaProdutos(Productos);
    imprimeproductos(Productos);
    CargaCliente(Clientes);
    imprimeclientes(Clientes);
    cargaPedido(Productos, Clientes);
    imprimerepfinal(Clientes);
    imprimereporte(Clientes);
    return 0;
}

