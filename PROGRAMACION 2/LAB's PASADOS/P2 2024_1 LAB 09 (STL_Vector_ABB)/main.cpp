/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de noviembre de 2024, 11:57
 */

#include <iostream>

#include "Biblioteca.h"
using namespace std;

int main(int argc, char** argv) {
    Biblioteca bli;
    bli.Carga();
    bli.Muestra();
    bli.Prueba(3);
    return 0;
}

