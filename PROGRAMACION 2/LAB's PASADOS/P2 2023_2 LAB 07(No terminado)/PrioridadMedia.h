/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PrioridadMedia.h
 * Author: Rosse
 *
 * Created on 6 de noviembre de 2024, 16:17
 */

#ifndef PRIORIDADMEDIA_H
#define PRIORIDADMEDIA_H
#include <fstream>
using namespace std;
#include "Pedido.h"
class PrioridadMedia: public Pedido{
private:
    char * Descripcion;
    int nueva_fecha_Entrega;
public:
    PrioridadMedia();
    ~PrioridadMedia();
    PrioridadMedia(const PrioridadMedia &);
    void SetNueva_fecha_Entrega(int nueva_fecha_Entrega);
    int GetNueva_fecha_Entrega() const;
    void SetDescripcion(const char* Descripcion);
    void GetDescripcion(char *&) const;
    
    void Lee(ifstream &arch);
    void imprime(ofstream &arch);
};
#endif /* PRIORIDADMEDIA_H */
