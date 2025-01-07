/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PilaConEnteros.h
 * Author: Rosse
 *
 * Created on 24 de octubre de 2024, 09:57
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H
#include<fstream>
using namespace std;
void *leeNumero(ifstream &arch);
double calculaNumero(void *Pila);
int  cmpNumero(const void *a,const void *b);
void imprimenumero(ofstream &arch, void *Camion);
#endif /* PILACONENTEROS_H */
