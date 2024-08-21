/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   SobreCargaOperadores.h
 * Author: Rosse
 *
 * Created on 21 de agosto de 2024, 08:28
 */

#ifndef SOBRECARGAOPERADORES_H
#define SOBRECARGAOPERADORES_H
#include <fstream>
using namespace std;

bool operator >> (ifstream &arch, struct Libro &lib);
bool operator >> (ifstream &arch, struct Cliente &cli);

bool operator >> (struct LibroSolicitado &lib, struct Libro *arreglo);
bool operator << (struct Cliente &cli, const struct LibroSolicitado &arreglo);
struct Cliente & operator ++(struct Cliente &cli);

void operator <<(ofstream &arch, const struct Libro &lib);
void operator <<(ofstream &arch, const struct Cliente &cli);
#endif /* SOBRECARGAOPERADORES_H */
