/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 21 de agosto de 2024, 10:46
 */

#include <iostream>
using namespace std;
#include "FuncionesAux.h"
#include "Estructuras.h"

int main(int argc, char** argv) {
    struct Libro ArrLibro[300];
    struct Cliente ArrCliente[60];
    
    LeerLibros(ArrLibro,"Libros.csv");
    LeerClientes(ArrCliente,"Cientes.csv");
    ColocarPedidos(ArrCliente,ArrLibro,"Pedidos.txt");
    ImprimirReporte(ArrCliente,ArrLibro,"ReporteFinal.txt");
    
    return 0;
}

