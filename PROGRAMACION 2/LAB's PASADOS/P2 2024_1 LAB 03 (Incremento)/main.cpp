/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 17 de septiembre de 2024, 12:13
 */

#include <iostream>
using namespace std;
#include "MetodoExactoDeMemoria.h"

int main(int argc, char** argv) {
    char ***Libros,***PedidoLibros;
    int **Stock,**PedidosClientes;
    bool **PedidosAtendidos;
    
    lecturaDeLibros("Libros.csv", Libros,Stock);
    PrubaDeLecturaDeLibros("ReporteDeLibrosInicial.txt", Libros,Stock);
    
    AtencionDePedidos("Pedidos.txt", Libros,Stock,PedidosClientes,PedidoLibros,PedidosAtendidos);
    PrubaDeLecturaDeLibros("ReporteDeLibrosFinal.txt", Libros,Stock);
    
    OrdenarPedidosClientes(PedidosClientes);
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidoss.txt",PedidosClientes,PedidoLibros,PedidosAtendidos);

    return 0;
}

