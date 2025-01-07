/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Registro.h
 * Author: Rosse
 *
 * Created on 24 de octubre de 2024, 15:15
 */

#ifndef REGISTRO_H
#define REGISTRO_H
#include <fstream>
using namespace std;
void * crearRegistro(void *datos);
void imprimeRegistro(ofstream &arch,void *Libro);
#endif /* REGISTRO_H */
