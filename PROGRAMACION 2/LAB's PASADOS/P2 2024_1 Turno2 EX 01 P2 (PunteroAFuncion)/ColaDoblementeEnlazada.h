/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ColaDoblementeEnlazada.h
 * Author: Rosse
 *
 * Created on 24 de octubre de 2024, 15:07
 */

#ifndef COLADOBLEMENTEENLAZADA_H
#define COLADOBLEMENTEENLAZADA_H

void GenerarCola( void *&cola);
void Encolar(void *&Cola, void *Registro);
void * Desencolar(void *&Cola);
bool EsColaVacia(void *Cola);
void InsertarInicio(void *&Cola, void *Registro);
void InsertarEnPosicion(void *&Cola, void *Registro);
void InicializarNodo(void *&Nodo,void*);
#endif /* COLADOBLEMENTEENLAZADA_H */
