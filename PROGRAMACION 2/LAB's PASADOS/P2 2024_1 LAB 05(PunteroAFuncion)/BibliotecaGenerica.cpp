/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: Rosse
 * 
 * Created on 22 de octubre de 2024, 08:22
 */

#include "BibliotecaGenerica.h"
// ESTA LISTA TIENE CABEZA Y COLA 

/* [][] ---------
 *  |              |
 * V             V 
 * [][]->[][]->[][]
 */
void crearLista(void *&pedido1, void *(*Leer)(ifstream &), const char* namefile) {
    ifstream arch(namefile);
    void *Dato;
    pedido1 = nullptr;
    while (true) {
        Dato = Leer(arch);
        if (arch.eof()) break;
        insertarLista(pedido1, Dato);
    }
}
// INSETAR AL ULTIMO

void insertarLista(void*&pedido, void *Dato) {
    //Crear nuevo nodo
    void **Nodo = new void *[2];
    Nodo[0] = Dato;
    Nodo[1] = nullptr;
    if (pedido == nullptr) {// Si esta vacio
        //Creo la lista
        void **Lista = new void *[2];
        Lista[0] = Nodo;
        Lista[1] = Nodo;
        pedido = Lista;
    } else {// si la lista no esta vacia
        void **Lista = (void**) pedido;
        void **UltimoElemento = (void**) Lista[1];
        UltimoElemento[1] = Nodo;
        Lista[1] = Nodo;
    }
}

void imprimeLista(void *pedido1, void (*imprime)(ofstream &, void *), const char* namefile) {
    ofstream arch(namefile);
    if (pedido1 == nullptr) return;
    void **Lista = (void **) pedido1;
    void **nodo = (void **) Lista[0];
    while (nodo != nullptr) {
        void *Dato = nodo[0];
        imprime(arch, Dato);
        nodo = (void **) nodo[1];
    }
}

void CombinaLista(void *pedido1, void*pedido2, void*&pedidoFinal, bool (*cmp)(const void *, const void *)) {
    pedidoFinal = nullptr;
    if (pedido1 == nullptr and pedido2 == nullptr) return;
    void **Lista1 = (void **) pedido1;
    void **Lista2 = (void **) pedido2;
    void **nodo1 = (void **) Lista1[0];
    void **nodo2 = (void **) Lista2[0];
    while (nodo1 != nullptr and nodo2 != nullptr) {
        bool EsMenor = cmp(nodo1[0], nodo2[0]);
        if (EsMenor) { // El dato del nodo1 es menor que le dato del nodo2
            insertarLista(pedidoFinal, nodo1[0]);
            nodo1 = (void **) nodo1[1];
        } else {
            insertarLista(pedidoFinal, nodo2[0]);
            nodo2 = (void **) nodo2[1];
        }
    }
    // Si ya agregamos todos del la lista 2 y nos falta agregar de la lista 1
    while (nodo1 != nullptr) {
        insertarLista(pedidoFinal, nodo1[0]);
        nodo1 = (void **) nodo1[1];
    }
    // Si ya agregamos todos del la lista 1 y nos falta agregar de la lista 2
    while (nodo2 != nullptr) {
        insertarLista(pedidoFinal, nodo2[0]);
        nodo2 = (void **) nodo2[1];
    }
}