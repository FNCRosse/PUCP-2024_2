/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Vehiculo.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 14:55
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include <fstream>
using namespace std;
class Vehiculo{
private:
    int cliente;
    char* placa;
    double maxcarga;
    double actcarga;
public:
    Vehiculo();
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(const char* placa);
    char* GetPlaca() const;
    void SetCliente(int cliente);
    int GetCliente() const;
    
    virtual void Leer(ifstream &arch);
    virtual void Imprimir(ofstream &arch);
    virtual void AgregarPedido(class NPedido &datoPed);
   
};
#endif /* VEHICULO_H */
