/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunterosFuncion2Examen01Pregunta02.h
 * Author: Rosse
 *
 * Created on 24 de octubre de 2024, 15:07
 */

#ifndef PUNTEROSFUNCION2EXAMEN01PREGUNTA02_H
#define PUNTEROSFUNCION2EXAMEN01PREGUNTA02_H
#include <fstream>
using namespace std;
void cargarRanking(void *&Ranking, void *(*crear)(void*), void *ventas);
void MuestraRanking(void *Ranking, void(*imprime)(ofstream &, void*), const char* namefile);
#endif /* PUNTEROSFUNCION2EXAMEN01PREGUNTA02_H */
