/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Procesa.h
 * Author: Rosse
 *
 * Created on 21 de noviembre de 2024, 10:52
 */

#ifndef PROCESA_H
#define PROCESA_H
#include "Pila.h"
class Procesa{
private:
    class Pila ppedidos;
public:
    Procesa();
    void carga();
    void Ordena();
    void Muestra();
};
#endif /* PROCESA_H */
