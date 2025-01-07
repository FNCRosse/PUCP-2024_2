/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 21 de noviembre de 2024, 10:32
 */

#include <iostream>
using namespace std;
#include "Procesa.h"

int main(int argc, char** argv) {
    Procesa pro;
    pro.carga();
    pro.Ordena();
    pro.Muestra();
    return 0;
}

