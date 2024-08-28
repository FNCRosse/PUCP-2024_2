/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de agosto de 2024, 13:15
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "SobrecargaOp.h"

int main(int argc, char** argv) {
    ifstream archA,archC,archE,archM;
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaLeer(archA,"Alumnos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archC,"Cursos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archE,"Escalas.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archM,"Matricula.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,"Pruba1.txt");
    
    struct StAlumno ArrAlumno[5], alumno;
    ArrAlumno[0].semestre = 0;
    for(int i=0;i<3;i++){
        archA>>alumno;
        ArrAlumno += alumno;
    }
    struct StCurso ArrCursos[5],curso;
    strcpy(ArrCursos[0].codigoDelCurso,"XXXXXX");
    for(int i=0;i<3;i++){
        archC>>curso;
        ArrCursos += curso;
    }
    
    struct StRegistroDeMatricula RegMat1,RegMat2;
    archM>>RegMat1;
    archM>>RegMat2;
    
    ArrCursos *= RegMat1;
    ArrCursos *= RegMat2;
    
    ArrAlumno *= RegMat1;
    ArrAlumno *= RegMat2;
    
    for(int i=0;strcmp(ArrCursos[i].codigoDelCurso,"XXXXXX")!=0 ;i++){
        archRep<<ArrCursos[i];
    }
    archRep<<endl<<endl;
     for(int i=0;ArrAlumno[i].semestre !=0 ;i++){
        archRep<<ArrAlumno[i];
    }
   
    return 0;
}

