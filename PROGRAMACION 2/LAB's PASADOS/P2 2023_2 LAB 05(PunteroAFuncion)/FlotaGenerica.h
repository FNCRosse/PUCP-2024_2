/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FlotaGenerica.h
 * Author: Rosse
 *
 * Created on 24 de octubre de 2024, 09:57
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H
#include <fstream>
using namespace std;
void inicializarFlota(void *&flota);
void cargaCamiones(void *&flota, int numCamiones,int pesoMaximo,void *(*leer)(ifstream &),
        double (*calcula)(void *), const char *namefile);
void muestraCamiones(void *flota, int numCamiones, void (*imprime)(ofstream &,void*), const char *namefile);
bool  EsPilaVacia(void *Pila);
void Push(void *&Flota,void *Dato);
double ObtenerPesoAcomulado(void *Flota);
void ActualizarPeso(void *Camion,double PesoDato);
#endif /* FLOTAGENERICA_H */
