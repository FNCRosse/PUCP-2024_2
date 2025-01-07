/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de octubre de 2024, 19:09
 */

#include <iostream>
using namespace std;
#include "Almacen.h"

int main(int argc, char** argv) {
    Almacen almacen;
    
    almacen.Carga_Cliente();
    almacen.Carga_productos();
    almacen.Carga_Pedidos();
    almacen.Mostrar_Datos();
    

    return 0;
}

