/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 22 de agosto de 2024, 08:37
 */

#include <iostream>
using namespace std;
#include "FuncionesAux.h"
#include "Estructuras.h"

int main(int argc, char** argv) {
    struct Cliente arrClientes[150];
    struct Producto arrProductos[180];
    
    LeerClientes(arrClientes,"Clientes.csv");
    LeerProductos(arrProductos,"Productos.csv");
    AgregarPedidos(arrClientes,arrProductos,"Pedidos.csv");
    ImprimirReporte(arrClientes,arrProductos,"Reporte.txt");
    
    return 0;
}

