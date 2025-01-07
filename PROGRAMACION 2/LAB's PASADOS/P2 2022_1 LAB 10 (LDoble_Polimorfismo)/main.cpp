/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de noviembre de 2024, 19:59
 */

#include <iostream>
using namespace std;
#include "Promociones.h"
int main(int argc, char** argv) {
    Promociones pro;
    pro.LeePedidos();
    pro.ActualizaPedidos();
    pro.ImprimePedido();
    return 0;
}

