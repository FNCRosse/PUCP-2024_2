/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 16:25
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include "Lista.h"
class Estante{
private:
    char clase;
    int id;
    double capacidad;
    class Lista Llibros;
public:
    Estante();
    ~Estante();
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetClase(char clase);
    char GetClase() const;
    void SetId(int id);
    int GetId() const;
    
    void Leer(ifstream &arch);
    void Imprimir(ofstream &arch);
    void Actualizar();
    void Insertar(Nodo *dato);
    bool EspacioDisponible(Nodo *dato);
};
#endif /* ESTANTE_H */
