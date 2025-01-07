/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Rosse
 * 
 * Created on 28 de noviembre de 2024, 12:44
 */

#include "Biblioteca.h"

Biblioteca::Biblioteca() {

}

void Biblioteca::Carga() {
    ifstream archEst ("Estantes3.csv");
    ifstream archLib ("Libros31.csv");
    char tipo;
    class NLibro lib;
    while(true){
        class NEstante estante;
        estante.LeerEstante(archEst);
        if(archEst.eof()) break;
        for(int i=0;i<10;i++){
            archLib>>tipo;
            archLib.get();
            lib.AsignarTipo(tipo);
            lib.Leer(archLib);
            estante.AgregarLibro(lib);
        }
        AEstante.insertar(estante);
    }
}

void Biblioteca::Muestra() {
    ofstream arch ("Reporte.txt");
    AEstante.Imprime(arch);
}

void Biblioteca::Prueba(double peso) {
    ofstream arch ("Busqueda.txt");
    AEstante.PruebaPeso(peso,arch);
}