/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: Rosse
 * 
 * Created on 28 de agosto de 2024, 13:19
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "SobrecargaOp.h"
#include "Funciones.h"

void LeerCursos(struct StCurso *ArrCurso, const char* namefile){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,namefile);
    struct StCurso Curso;
    strcpy(ArrCurso[0].codigoDelCurso,"XXXXXX");
    while(arch>>Curso) ArrCurso += Curso;
}
void LeerAlumnos(struct StAlumno *ArrAlumno, const char* namefile){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,namefile);
    struct StAlumno alumno;
    ArrAlumno[0].semestre = 0;
    while(arch>>alumno) ArrAlumno += alumno;
}
void LeerMatricula(struct StAlumno *ArrAlumno,struct StCurso *ArrCurso, const char* namefile){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,namefile);
    struct StRegistroDeMatricula RegMat;
    while(arch>>RegMat){
        ArrCurso *= RegMat;
        ArrAlumno *= RegMat;
    }
}
void CalcularIngresos(struct StAlumno *ArrAlumno,struct StCurso *ArrCurso, const char* namefile){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,namefile);
    double PrecioEscala[5],Credito;
    int EscalaAlumno;
    LeerEscala(arch,PrecioEscala);
    for(int i=0;strcmp(ArrCurso[i].codigoDelCurso,"XXXXXX")!=0 ;i++){
        for(int k=0;k<ArrCurso[i].numeroDeAlumnos;k++){
            EscalaAlumno = BuscarEscala(ArrAlumno,ArrCurso[i].alumnos[k]);
            if(EscalaAlumno != -1)ArrCurso[i].ingresos += PrecioEscala[EscalaAlumno-1] * ArrCurso[i].creditos;
        }
    }
    
    for(int i=0;ArrAlumno[i].semestre!=0 ;i++){
        for(int k=0;k<ArrAlumno[i].numeroDeCursos;k++){
            Credito = BuscarCredito(ArrCurso,ArrAlumno[i].cursos[k]);
            ArrAlumno[i].costoTotal += PrecioEscala[ArrAlumno[i].escala-1] * Credito;
        }
    }
}
void LeerEscala(ifstream &arch, double *PrecioEscala){
    int escala;
    double precio;
    char extra;
    while(true){
        arch>>extra;
        if(arch.eof()) break;
        arch>>escala>>precio;
        PrecioEscala[escala-1] = precio;
    }
}
int BuscarEscala(struct StAlumno *ArrAlumno,int alumno){
    for(int i=0;ArrAlumno[i].semestre!=0;i++){
        int ArregloALCodigo = ArrAlumno[i].semestre*10000+ArrAlumno[i].codigo;
        if(ArregloALCodigo == alumno) return ArrAlumno[i].escala;
    }
    return -1;
}
double BuscarCredito(struct StCurso *ArrCurso,char* codigo){
    for(int i=0;strcmp(ArrCurso[i].codigoDelCurso,"XXXXXX")!=0 ;i++){
        if(strcmp(ArrCurso[i].codigoDelCurso,codigo)==0 ) return ArrCurso[i].creditos;
    }
    return -1;
}
void ImprimirReporte(struct StAlumno *ArrAlumno,struct StCurso *ArrCurso, const char* namefile){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,namefile);
    arch.precision(2);
    arch<<fixed;
    arch<<right<<setw(35)<<"REPORTE DE CURSOS"<<endl;
     for(int i=0;strcmp(ArrCurso[i].codigoDelCurso,"XXXXXX")!=0 ;i++){
        arch<<ArrCurso[i];
    }
    arch<<endl<<endl;
    arch<<right<<setw(55)<<"REPORTE DE ALUMNOS"<<endl;
     for(int i=0;ArrAlumno[i].semestre !=0 ;i++){
        arch<<ArrAlumno[i];
    }
}