/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de agosto de 2024, 13:18
 */

#include <iostream>
using namespace std;
#include "Estructuras.h"
#include "Funciones.h"

int main(int argc, char** argv) {
    struct StCurso ArrCurso[10];
    struct StAlumno ArrAlumno[80];
    
    LeerCursos(ArrCurso,"Cursos.txt");
    LeerAlumnos(ArrAlumno,"Alumnos.txt");
    LeerMatricula(ArrAlumno,ArrCurso,"Matricula.txt");
    CalcularIngresos(ArrAlumno,ArrCurso,"Escalas.txt");
    ImprimirReporte(ArrAlumno,ArrCurso,"Reporte_Final.txt");
    
    return 0;
}

