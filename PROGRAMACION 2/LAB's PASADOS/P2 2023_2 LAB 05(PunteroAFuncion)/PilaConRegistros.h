/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PilaConRegistros.h
 * Author: Rosse
 *
 * Created on 24 de octubre de 2024, 09:57
 */

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H
#include<fstream>
using namespace std;
void *leeRegistro(ifstream &arch);
double calculaRegistro(void *Pila);
int  cmpRegistro(const void *a,const void *b);
void imprimeRegistro(ofstream &arch, void *Camion);
char *ConvertirCharPtr(char* cad);
#endif /* PILACONREGISTROS_H */
