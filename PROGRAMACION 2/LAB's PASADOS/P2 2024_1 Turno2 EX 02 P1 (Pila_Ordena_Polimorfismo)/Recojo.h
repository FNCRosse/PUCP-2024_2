/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Recojo.h
 * Author: Rosse
 *
 * Created on 21 de noviembre de 2024, 10:39
 */

#ifndef RECOJO_H
#define RECOJO_H
#include "Pedido.h"

class Recojo : public Pedido {
private:
    char *Tienda;
    int dias;
public:
    Recojo();
    ~Recojo();
    void SetDias(int dias);
    int GetDias() const;
    void SetTienda(const char* Tienda);
    void GetTienda(char *&) const;
    
    void Leer(ifstream &arch);
    void Imprimir(ofstream &arch);
};
#endif /* RECOJO_H */
