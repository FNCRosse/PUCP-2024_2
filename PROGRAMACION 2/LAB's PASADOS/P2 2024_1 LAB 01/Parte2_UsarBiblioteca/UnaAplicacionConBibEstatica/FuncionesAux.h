/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesAux.h
 * Author: Rosse
 *
 * Created on 21 de agosto de 2024, 10:48
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

void LeerLibros(struct Libro *ArrLib,const char* nameFile);
void LeerClientes(struct Cliente *ArrCli,const char* nameFile);
void ColocarPedidos(struct Cliente *ArrCli,struct Libro *ArrLib,const char* nameFile);
void ImprimirReporte(const struct Cliente *ArrCli,const struct Libro *ArrLib,const char* nameFile);


#endif /* FUNCIONESAUX_H */
