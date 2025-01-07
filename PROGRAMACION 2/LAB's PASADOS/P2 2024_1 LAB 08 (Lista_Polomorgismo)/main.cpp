/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de noviembre de 2024, 15:37
 */

#include <iostream>
using namespace std;
#include "Biblioteca.h"
int main(int argc, char** argv) {
    Biblioteca bli;
    bli.Carga();
    bli.Llena();
    bli.baja();
    bli.Muestra();
 
    return 0;
}

