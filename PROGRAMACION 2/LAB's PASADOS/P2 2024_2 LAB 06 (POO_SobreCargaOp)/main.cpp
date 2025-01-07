/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 6 de noviembre de 2024, 11:45
 */

#include <iostream>
using namespace std;
#include "Restaurante.h"

int main(int argc, char** argv) {
    Restaurante restaurante;
    restaurante < "Clientes.csv";
    restaurante <= "PlatosOfrecidos.csv";
    restaurante <<= "Pedidos.csv";
    restaurante >> "ReporteDeVentasDelDia.txt";

    return 0;
}

