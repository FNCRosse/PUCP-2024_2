/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 7 de septiembre de 2024, 06:32
 */

#include <iostream>
#include <vector>

using namespace std;

// Variables globales
vector<vector<int>> solucion; // Almacenará los paquetes asignados a cada mochila
int n;  // Número de paquetes

// Función para imprimir la solución
void imprimirSolucion(const vector<vector<int>>& mochilas) {
    for (int i = 0; i < mochilas.size(); i++) {
        cout << "Mochila " << i + 1 << ": ";
        for (int p : mochilas[i]) {
            cout << p << " ";
        }
        cout << endl;
    }
}

// Función recursiva de backtracking
void resolverBacktracking(vector<int>& paquetes, vector<int>& capacidades, vector<vector<int>>& mochilas, int idx) {
    if (idx == n) {
        // si quiero mostrar todas las soluciones
        imprimirSolucion(mochilas);  
        return ;
    }
    
    // Intentamos asignar el paquete actual a cada mochila
    for (int i = 0; i < mochilas.size(); i++) {
        if (capacidades[i] >= paquetes[idx]) {
            // Si el paquete cabe en la mochila, lo asignamos
            mochilas[i].push_back(paquetes[idx]);
            capacidades[i] -= paquetes[idx];
            
            // Continuamos con el siguiente paquete
            resolverBacktracking(paquetes, capacidades, mochilas, idx + 1);
            
            // Si no fue una asignación válida, retrocedemos
            mochilas[i].pop_back();
            capacidades[i] += paquetes[idx];
        }
    }
    
}

int main() {
    // Ejemplo de entrada: paquetes y capacidades de mochilas
    vector<int> paquetes = {4, 3, 2, 2, 5, 5}; // Pesos de los paquetes
    vector<int> capacidades = {10, 10, 10}; // Capacidades de las mochilas (camiones)

    n = paquetes.size();
    
    // Inicializamos las mochilas
    vector<vector<int>> mochilas(3);  // Tres mochilas
    
    // Intentamos resolver usando backtracking
    resolverBacktracking(paquetes, capacidades, mochilas, 0);
    return 0;
}


