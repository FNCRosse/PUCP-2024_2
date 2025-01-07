/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de octubre de 2024, 18:36
 */
#include "PunteroVoid.h"
#include "MuestraVoid.h"
using  namespace std;
#include "PunterosFuncion2Examen01Pregunta02.h"
#include "ColaDoblementeEnlazada.h"
#include "Registro.h"

int main(int argc, char** argv) {
    void *ventas;
    void *Ranking;
  
    cargaLibros(ventas);
    cargaventas(ventas);
    //muestraventas(ventas);
    
    cargarRanking(Ranking,crearRegistro,ventas);
    MuestraRanking(Ranking,imprimeRegistro,"Rankigs.txt");
    return 0;
}

