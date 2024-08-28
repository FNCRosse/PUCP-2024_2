/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   SobrecargaOp.h
 * Author: Rosse
 *
 * Created on 28 de agosto de 2024, 07:30
 */

#ifndef SOBRECARGAOP_H
#define SOBRECARGAOP_H
#include <fstream>
using namespace std;

//LECTURA
bool operator >> (ifstream &arch,struct StCurso & curso);
bool operator >> (ifstream &arch,struct StAlumno & al);
bool operator >> (ifstream &arch,struct StRegistroDeMatricula & mat);
//AGREGACION
void operator  += (struct StCurso *ArrCurso,const struct StCurso &Curso);
void operator  += (struct StAlumno *ArrAlumnos,const struct StAlumno &Al);
void operator  *= (struct StCurso *ArrCurso,struct StRegistroDeMatricula &mat);
void operator  *= (struct StAlumno *ArrAlumnos,struct StRegistroDeMatricula &mat);
//iMPRESION
void ImprimirAlumno(ofstream &arch,int alumno);
void operator << (ofstream &arch,const struct StCurso & curso);
void operator << (ofstream &arch,const struct StAlumno & al);
#endif /* SOBRECARGAOP_H */
