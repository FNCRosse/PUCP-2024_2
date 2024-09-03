/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Pregunta2.cpp
 * Author: Rosse
 * 
 * Created on 2 de septiembre de 2024, 20:02
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Pregunta2.h"

void agruparEquipos(const vector<int>& equipos, int pos, string agrupacion) {
    if (pos == equipos.size()) {
        cout << agrupacion << endl;
        return;
    }
    
    // Agregar el equipo actual al grupo actual
    if (!agrupacion.empty()) {
        agrupacion += " ";
    }
    agruparEquipos(equipos, pos + 1, agrupacion + to_string(equipos[pos]));
    
    // Iniciar un nuevo grupo con el equipo actual
    if (pos > 0) { // Se puede iniciar un nuevo grupo solo si no estamos en la primera posición
        agruparEquipos(equipos, pos + 1, agrupacion + " " + to_string(equipos[pos]));
    }
}
void Pregunta2(){
    vector<int> equipos = {4, 5, 9, 2}; // Ejemplo de entrada
    agruparEquipos(equipos, 0, "");
    return ;
}