/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Pregunta1.cpp
 * Author: Rosse
 * 
 * Created on 2 de septiembre de 2024, 19:56
 */
#include <iostream>
#include <vector>
using namespace std;
#include "Pregunta1.h"
#define MAX 10
int contador = 0;
vector<vector<int>> TodasSoluciones;
vector<int> solucion;

bool valido(int k) {
    for (int i = 0; i < solucion.size() - 1; i++) {
        if (abs(solucion[i] - solucion[i + 1]) > k) return false;
    }
    return true;
}

void Quitar(int *t,int n) {
    for(int i=0,k=0;i<n;i++){
        if(t[i] == solucion[k]){
            t[i]=0;
            k++;
        }
    }
}
void Poner (int *t,int n) {
    for(int i=0,k=0;i<n;i++){
        if(t[i] == 0){
            t[i]=solucion[k];
            k++;
        }
    }
}

void CalcularPedidos(int *t, int p, int k, int i,int n) {
    //caso base
    bool bandera = false;
    if (p == 0 and valido(k)) {
        contador++;
        TodasSoluciones.push_back(solucion);
        Quitar(t,n);
        return;
    }
    if (i == n or p < 0) return;

    solucion.push_back(t[i]);
    CalcularPedidos(t, p - t[i], k, i + 1,n);
    
    if(bandera) Poner(t,n);
    solucion.pop_back();
    CalcularPedidos(t, p, k, i + 1,n);

}

void Pregunta1(){
    int P = 15, t[MAX] = {2, 8, 9, 6, 7,6}, k = 3,n=6;

    CalcularPedidos(t, P, k, 0,n);
    cout << "El numero de pedidos que se puede atender de " << P << " Kg: " << contador << endl;
    cout << "El Peso de los cortes de cada pedido: ";
    for (const auto& solucion : TodasSoluciones) {
        cout << "{ ";
        for (int num : solucion) {
            cout << num << " ";
        }
        cout << "}";
    }
}