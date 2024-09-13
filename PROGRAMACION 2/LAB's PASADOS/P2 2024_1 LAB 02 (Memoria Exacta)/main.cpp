/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 12 de septiembre de 2024, 15:41
 */

#include <iostream>
using namespace std;
#include "MetodoExactoDeMemoria.h"

int main(int argc, char** argv) {
    char ***Libros,***PedidosLibros;
    int **Stock,**PedidosClientes;
    bool **PedidosAtendidos;
    
    lecturaDeLibros("Libros.csv",Libros,Stock);
    PruebaDeLecturaDeLibros("ReporteDeLibroInicial.txt",Libros,Stock);
    atencionDePedidos("Pedidos.txt",Libros,Stock,PedidosClientes,PedidosLibros,PedidosAtendidos);
    PruebaDeLecturaDeLibros("ReporteDeLibroFinall.txt",Libros,Stock);
    ReporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt",PedidosClientes,PedidosLibros,PedidosAtendidos);
    return 0;
}

