/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de octubre de 2024, 17:10
 */

#include <iostream>
using namespace std;
#include "biblioteca.h"

int main(int argc, char** argv) {
    Biblioteca biblioteca;
    
    biblioteca.Carga_Libros();
    biblioteca.Carga_Estantes();
    biblioteca.Posicionar_Libros();
    biblioteca.Mostrar_Datos();

    return 0;
}

