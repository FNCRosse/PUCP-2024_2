/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   SobrecargaOp.cpp
 * Author: Rosse
 * 
 * Created on 28 de agosto de 2024, 07:30
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "SobrecargaOp.h"
#include "Estructuras.h"

//INF263   Algoritmia   3.75   35030611   INGA_FLORES_CESAR_ADOLFO
bool operator >> (ifstream &arch,struct StCurso & curso){
    arch>>curso.codigoDelCurso;
    if(arch.eof()) return false;
    arch>>curso.nombreDelCurso;
    arch>>curso.creditos;
    arch>>curso.codigoDelProfesor;
    arch>>curso.nombreDelProfesor;
    curso.numeroDeAlumnos =0;
    curso.ingresos=0;
    return true;
}
//20211,1397   ZEVALLOS/PRADO/RICARDO   S   50   G2
bool operator >> (ifstream &arch,struct StAlumno & al){
    char modalidad,extra;
    arch>>al.semestre;
    if(arch.eof()) return false;
    arch.get();
    arch>>al.codigo;
    arch>>al.nombre;
    arch>>modalidad;
    switch(modalidad){
        case 'G':
            strcpy(al.modalidad,"Presencial");
            break;
        case 'S':
            strcpy(al.modalidad,"Semi-Presencial");
            arch>>al.porcentaje;
            arch>>extra;
            break;
        case 'V':
            strcpy(al.modalidad,"Virtual");
            arch>>extra;
            break;
    }
    arch>>al.escala;
    al.numeroDeCursos =0;
    al.costoTotal=0;
    return true;
}
//INF263   20231,8320
bool operator >> (ifstream &arch,struct StRegistroDeMatricula & mat){
    arch>>mat.codigoDelCurso;
    if(arch.eof()) return false;
    arch>>mat.semestreDelAlumno;
    arch.get();
    arch>>mat.codigodelAlumno;
    arch.get();
    return true;
}
//AGREGACION
void operator  += (struct StCurso *ArrCurso,const struct StCurso &Curso){
    int indice =0;
    while(strcmp(ArrCurso[indice].codigoDelCurso,"XXXXXX")!=0) indice++;
    ArrCurso[indice] = Curso;
    strcpy(ArrCurso[indice+1].codigoDelCurso,"XXXXXX");
}
void operator  += (struct StAlumno *ArrAlumnos,const struct StAlumno &Al){
    int indice =0;
    while(ArrAlumnos[indice].semestre != 0) indice++;
    ArrAlumnos[indice] = Al;
    for(int i=0;i<10;i++){
        ArrAlumnos[indice].cursos[i] = new char[7]{};
    }
    ArrAlumnos[indice+1].semestre =0;
}
void operator  *= (struct StCurso *ArrCurso,struct StRegistroDeMatricula &mat){
    for(int i=0;strcmp(ArrCurso[i].codigoDelCurso,"XXXXXX")!=0;i++){
        if(strcmp(ArrCurso[i].codigoDelCurso,mat.codigoDelCurso)==0 ){
            int cant = ArrCurso[i].numeroDeAlumnos;
            ArrCurso[i].alumnos[cant] = mat.semestreDelAlumno*10000 + mat.codigodelAlumno;
            ArrCurso[i].numeroDeAlumnos++;
            break;
        }
    }
}
void operator  *= (struct StAlumno *ArrAlumnos,struct StRegistroDeMatricula &mat){
    for(int i=0;ArrAlumnos[i].semestre!=0;i++){
        int ArregloALCodigo = ArrAlumnos[i].semestre*10000+ArrAlumnos[i].codigo;
        int MatALCodigo = mat.semestreDelAlumno*10000 + mat.codigodelAlumno;
        if(ArregloALCodigo == MatALCodigo){
            int cant = ArrAlumnos[i].numeroDeCursos;
            strcpy(ArrAlumnos[i].cursos[cant],mat.codigoDelCurso);
            ArrAlumnos[i].numeroDeCursos++;
            break;
        }
    }
}
//iMPRESION
void ImprimirAlumno(ofstream &arch,int alumno){
    int semestre = alumno /10000;
    int codigo = alumno%10000;
    arch<<right<<setw(7)<<semestre<<setw(10)<<codigo<<endl;
    
}

void operator << (ofstream &arch,const struct StCurso & curso){
    arch<<left<<setw(15)<<"CODIGO"<<setw(50)<<"NOMBRE"<<"CREDITOS"<<endl;
    arch<<left<<setw(15)<<curso.codigoDelCurso<<setw(50)<<curso.nombreDelCurso
            <<curso.creditos<<endl;
    arch<<setw(12)<<"PROFESOR:"<<curso.nombreDelProfesor<<endl;
    arch<<"Alumnos matriculados:"<<endl;
    arch<<setw(12)<<"Semestre"<<"Codigo"<<endl;
    for(int i=0;i<curso.numeroDeAlumnos;i++){
        ImprimirAlumno(arch,curso.alumnos[i]);
    }
    arch<<left<<"Numero de alumnos:"<<curso.numeroDeAlumnos<<endl;
    arch<<"Total ingresado: "<<curso.ingresos<<endl<<endl;
    
}
void operator << (ofstream &arch,const struct StAlumno & al){
    arch<<left<<setw(15)<<"SEMESTRE"<<setw(12)<<"CODIGO"<<setw(45)<<"NOMBRE"
            <<setw(30)<<"MODALIDAD"<<"ESCALA"<<endl;
    arch<<left<<setw(15)<<al.semestre<<setw(12)<<al.codigo<<setw(45)<<al.nombre
            <<setw(16)<<al.modalidad;
    if(strcmp(al.modalidad,"Semi-Presencial")==0) arch<<"  Con "<<al.porcentaje<<setw(8)<<"%";
    else arch<<setw(16)<<" ";
    arch<<al.escala<<endl;
    arch<<"Codigo de cursos matriculados:"<<endl;
    for(int i=0;i<al.numeroDeCursos;i++){
        arch<<right<<setw(15)<<al.cursos[i]<<endl;
    }
    arch<<left<<"Numero de cursos: "<<al.numeroDeCursos<<endl;
    arch<<"Costo Total: "<<al.costoTotal<<endl<<endl;
}