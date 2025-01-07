/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 16:33
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Estante.h"
class Biblioteca{
private:
    class Estante AEstante [10];
public:
    Biblioteca();
    void Carga();
    void Llena();
    void baja();
    void Muestra();
    int EstanteDisponible(Nodo *dato);
};
#endif /* BIBLIOTECA_H */
