/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Envio.h
 * Author: Rosse
 *
 * Created on 21 de noviembre de 2024, 10:35
 */

#ifndef ENVIO_H
#define ENVIO_H
#include "Pedido.h"

class Envio : public Pedido {
private:
    char * direccion;
    int fecha;
    double costo;
public:
    Envio();
    ~Envio();
    void SetCosto(double costo);
    double GetCosto() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDireccion(const char* direccion);
    void GetDireccion(char *&cad) const;

    void Leer(ifstream &arch);
    void Imprimir(ofstream &arch);
};
#endif /* ENVIO_H */
