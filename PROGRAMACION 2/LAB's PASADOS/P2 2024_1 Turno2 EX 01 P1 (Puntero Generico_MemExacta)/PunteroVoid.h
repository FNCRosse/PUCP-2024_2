/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunteroVoid.h
 * Author: Rosse
 *
 * Created on 2 de octubre de 2024, 18:39
 */

#ifndef PUNTEROVOID_H
#define PUNTEROVOID_H
#include <fstream>;
using namespace std;
void cargaLibros(void *&ventas);
bool operator >> (ifstream &arch, void *&reg);
void cargaventas(void *&ventas);
int BuscarVenta(void **ArrVentas,char *codigo);
void ColocarVenta(void *&Venta,int dni,int puntaje);
void ActualizarDatosDeVenta(int puntaje,void **&DatoVenta);
#endif /* PUNTEROVOID_H */
