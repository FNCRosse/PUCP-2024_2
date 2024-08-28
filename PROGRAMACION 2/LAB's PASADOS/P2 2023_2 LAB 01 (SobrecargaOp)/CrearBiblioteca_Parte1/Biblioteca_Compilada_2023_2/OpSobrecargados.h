/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   OpSobrecargados.h
 * Author: Rosse
 *
 * Created on 22 de agosto de 2024, 08:38
 */

#ifndef OPSOBRECARGADOS_H
#define OPSOBRECARGADOS_H
#include <fstream>
using namespace std;

//LECTURA
bool operator >>(ifstream &arch, struct Cliente & cli);
bool operator >>(ifstream &arch, struct Producto & cli);
bool operator >>(ifstream &arch, struct Pedido & cli);

//AGREGACION
void operator += (struct Cliente *ArrCli, const struct Pedido &ped);
bool operator += (struct Producto* ArrPro, struct Pedido &ped);

//IMPRESION
void operator << (ofstream &arch, const struct Cliente &cli);
void operator << (ofstream &arch, const struct Producto &pro);
#endif /* OPSOBRECARGADOS_H */
