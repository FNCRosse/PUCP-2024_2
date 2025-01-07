/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Plato.h
 * Author: Rosse
 *
 * Created on 6 de noviembre de 2024, 12:03
 */

#ifndef PLATO_H
#define PLATO_H
#include <fstream>
using namespace std;
class Plato{
private:
    char* codigo;
    char* nombre;
    double precio;
    char* categoria;
    int preparados;
    double descuento;
    int atendidos;
    int noatendidos;
    double totalEsperado;
    double TotalBruto;
    double totalNeto;
public:
    Plato();
    virtual~Plato();
    Plato(const Plato&);
    void SetTotalNeto(double totalNeto);
    double GetTotalNeto() const;
    void SetTotalBruto(double TotalBruto);
    double GetTotalBruto() const;
    void SetTotalEsperado(double totalEsperado);
    double GetTotalEsperado() const;
    void SetNoatendidos(int noatendidos);
    int GetNoatendidos() const;
    void SetAtendidos(int atendidos);
    int GetAtendidos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPreparados(int preparados);
    int GetPreparados() const;
    void SetCategoria(const char* categoria);
    void GetCategoria(char*&) const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*&) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*&) const;
    
    void operator = (const Plato & cli);
    double ConvertirDouble(const char *cad);
    void Leer(ifstream &arch);
    void Imprimir(ofstream &arch);
    bool ColocarPedido(double TotalPlato,int );
};
void operator >>(ifstream &arch,Plato &pla);
void operator <<(ofstream &arch,Plato &pla);
#endif /* PLATO_H */
