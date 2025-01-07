/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunteroMultiples1Examen01Pregunta1.h
 * Author: Rosse
 *
 * Created on 2 de octubre de 2024, 19:52
 */

#ifndef PUNTEROMULTIPLES1EXAMEN01PREGUNTA1_H
#define PUNTEROMULTIPLES1EXAMEN01PREGUNTA1_H
#include <fstream>
using namespace std;

void cargaVenta(char **&VentasLibroCodigo, int **&ventasDniFechaPuntaje, const char *namefile);
void PruebaDeCargaDeVenta(char **VentasLibroCodigo, int **ventasDniFechaPuntaje,const char *namefile);
void cargaLibros(char ***&Libro, const char *namefile);
void pruebaDeCargaDeLibros(char ***Libro, const char *namefile);

bool operator >> (ifstream &arch, char **&datolibro);
void incrementarEspaciosLibro(char ***&Libro,int &capacidad);
void inicializarVentas(char **&VentasLibroCodigo, int **&ventasDniFechaPuntaje, int capacidad);
void incrementarEspaciosVentas(char **&VentasLibroCodigo, int **&ventasDniFechaPuntaje, int &capacidad);
int *LeerDatosEnteros(ifstream& arch);
#endif /* PUNTEROMULTIPLES1EXAMEN01PREGUNTA1_H */
