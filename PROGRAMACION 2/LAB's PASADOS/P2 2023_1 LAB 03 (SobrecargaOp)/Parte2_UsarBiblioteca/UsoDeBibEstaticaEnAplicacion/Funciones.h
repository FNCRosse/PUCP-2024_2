/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.h
 * Author: Rosse
 *
 * Created on 28 de agosto de 2024, 13:19
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void LeerCursos(struct StCurso *ArrCurso, const char* namefile);
void LeerAlumnos(struct StAlumno *ArrAlumno, const char* namefile);
void LeerMatricula(struct StAlumno *ArrAlumno,struct StCurso *ArrCurso, const char* namefile);
void CalcularIngresos(struct StAlumno *ArrAlumno,struct StCurso *ArrCurso, const char* namefile);
void ImprimirReporte(struct StAlumno *ArrAlumno,struct StCurso *ArrCurso, const char* namefile);


void LeerEscala(ifstream &arch, double *PrecioEscala);
int BuscarEscala(struct StAlumno *ArrAlumno,int alumno);
double BuscarCredito(struct StCurso *ArrCurso,char* codigo);
#endif /* FUNCIONES_H */
