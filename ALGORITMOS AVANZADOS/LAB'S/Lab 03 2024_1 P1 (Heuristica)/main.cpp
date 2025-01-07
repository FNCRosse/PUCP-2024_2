/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 3 de octubre de 2024, 16:49
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <valarray>
using namespace std;
#define MAX 8

struct Nodo {
    int punto;
    int distancia;
};
bool compara (struct Nodo &a , struct Nodo &b){
    return a.distancia < b.distancia;
}
int CalcularTiempoViaje(int inicio, int fin, int mapa [][MAX]) {
    int total = 0;
    int ciudad = inicio;
    do {
        vector<struct Nodo> Vecinos;
        Nodo Paso;
        for (int i = 0; i < MAX; i++) {
            if (mapa[ciudad][i] > 0) {
                Paso.punto = i;
                Paso.distancia = mapa[ciudad][i];
                Vecinos.push_back(Paso);
            }
        }
        if( not Vecinos.empty()){
            sort(Vecinos.begin(),Vecinos.end(),compara); // Ordena de menor a mayor por defecto
            ciudad = Vecinos[0].punto;
            total += Vecinos[0].distancia;
        } else {
            total =0;
            break;
        }
    } while (ciudad != fin);
    return total;
}

int main(int argc, char** argv) {
    int mapa [][MAX] = {
        {0, 4, 5, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 0, 0, 10, 0},
        {0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };
    int inicio = 0;
    int fin = 6;
    int TimpoViaje = CalcularTiempoViaje(inicio, fin, mapa);
    if (TimpoViaje != 0) {
        cout << "Tiempo de viaje " << TimpoViaje << " min";
    } else {
        cout << "No se encontro una solucion" << endl;
    }
    return 0;
}

