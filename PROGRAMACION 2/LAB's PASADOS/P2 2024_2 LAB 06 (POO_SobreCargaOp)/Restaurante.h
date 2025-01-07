/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Restaurante.h
 * Author: Rosse
 *
 * Created on 6 de noviembre de 2024, 12:21
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include "Cliente.h"
#include "Plato.h"

class Restaurante {
private:
    class Cliente *clientes;
    int cantidadDeClientes;
    int capacidadDeClientes;
    class Plato* platos;
    int cantidadDePlatos;
    int capacidadDePlatos;
public:
    Restaurante();
    Restaurante(const Restaurante &);
    virtual ~Restaurante();
    void SetCapacidadDePlatos(int capacidadDePlatos);
    int GetCapacidadDePlatos() const;
    void SetCantidadDePlatos(int cantidadDePlatos);
    int GetCantidadDePlatos() const;
    void SetPlatos(Plato* platos);
    Plato* GetPlatos() const;
    void SetCapacidadDeClientes(int capacidadDeClientes);
    int GetCapacidadDeClientes() const;
    void SetCantidadDeClientes(int cantidadDeClientes);
    int GetCantidadDeClientes() const;
    void SetClientes(Cliente* clientes);
    Cliente* GetClientes() const;

    void operator<(const char*namefile);
    void operator<=(const char*namefile);
    void operator<<=(const char*namefile);
    void operator>>(const char*namefile);
    void IncrementarEspaciosPlato();
    void IncrementarEspaciosCliente();
    void imprimirLineas(ofstream& arch, int n, char c);
    int buscarCliente(int dniCliente);
    int buscarPlato(char *codPlato);
    void ColocarPlato(int posPlato, int posCliente, int cant);
};
#endif /* RESTAURANTE_H */
