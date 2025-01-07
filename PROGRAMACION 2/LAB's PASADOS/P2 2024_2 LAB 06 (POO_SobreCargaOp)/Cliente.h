/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Rosse
 *
 * Created on 6 de noviembre de 2024, 11:45
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <fstream>
using namespace std;
class Cliente{
private:
    int dni;
    char* nombre;
    char* Distrito;
    double Descuento;
    double TotalPagado;
public:
    Cliente();
    virtual ~Cliente();
    Cliente(const Cliente&);
    void SetTotalPagado(double TotalPagado);
    double GetTotalPagado() const;
    void SetDescuento(double Descuento);
    double GetDescuento() const;
    void SetDistrito(const char* Distrito);
    void GetDistrito(char*&) const;
    void SetNombre(const char* nombre);
    void GetNombre(char*&) const;
    void SetDni(int dni);
    int GetDni() const;
    
    void operator = (const Cliente & cli);
    double ConvertirDouble(const char *Buff);
    void Leer(ifstream &arch);
    void Imprimir(ofstream &arch);
    void ColocarPedido(double TotalPlato);
};
void operator >>(ifstream &arch,Cliente &cli);
void operator <<(ofstream &arch,Cliente &cli);
#endif /* CLIENTE_H */
