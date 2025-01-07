/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PrioridadAlta.h
 * Author: Rosse
 *
 * Created on 6 de noviembre de 2024, 16:05
 */

#ifndef PRIORIDADALTA_H
#define PRIORIDADALTA_H
#include <fstream>
using namespace std;
#include "Pedido.h"
class PrioridadAlta : public Pedido {
private:
    double recargo;
    double total;
public:
    PrioridadAlta();
    ~PrioridadAlta();
    PrioridadAlta(const PrioridadAlta &);
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    
    void Lee(ifstream &arch);
    void imprime(ofstream &arch);
};
#endif /* PRIORIDADALTA_H */
