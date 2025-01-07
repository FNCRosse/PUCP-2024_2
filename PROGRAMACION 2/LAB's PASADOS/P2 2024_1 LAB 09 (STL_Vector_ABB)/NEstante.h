/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NEstante.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 12:14
 */

#ifndef NESTANTE_H
#define NESTANTE_H
#include "NLibro.h"
#include <vector>
class NEstante{
private:
    int id;
    double capacidad;
    double disponible;
    vector<class NLibro> vLibros;
    class NEstante *izq;
    class NEstante *der;
public:
    NEstante();
    NEstante(const class NEstante &est);
     ~NEstante();
    void SetDisponible(double disponible);
    double GetDisponible() const;
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
     
    void AgregarLibro(class NLibro &dato);
    void LeerEstante(ifstream &arch);
    void ImprimeEstante(ofstream &arch);
    friend class Arbol;
};
#endif /* NESTANTE_H */
