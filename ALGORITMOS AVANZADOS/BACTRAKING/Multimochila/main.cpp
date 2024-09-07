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
bool resolverBacktracking(vector<int>& paquetes, vector<int>& capacidades, vector<vector<int>>& mochilas, int idx) {
    if (idx == n) {
        // Si ya hemos asignado todos los paquetes
        solucion = mochilas;
        return true;
    }
    
    // Intentamos asignar el paquete actual a cada mochila
    for (int i = 0; i < mochilas.size(); i++) {
        if (capacidades[i] >= paquetes[idx]) {
            // Si el paquete cabe en la mochila, lo asignamos
            mochilas[i].push_back(paquetes[idx]);
            capacidades[i] -= paquetes[idx];
            
            // Continuamos con el siguiente paquete
            if (resolverBacktracking(paquetes, capacidades, mochilas, idx + 1)) {
                return true;
            }
            
            // Si no fue una asignación válida, retrocedemos
            mochilas[i].pop_back();
            capacidades[i] += paquetes[idx];
        }
    }
    
    // Si no encontramos ninguna solución válida, devolvemos falso
    return false;
}

int main() {
    // Ejemplo de entrada: paquetes y capacidades de mochilas
    vector<int> paquetes = {5, 8, 3, 7, 10, 4, 6, 2}; // Pesos de los paquetes
    vector<int> capacidades = {10, 15, 20}; // Capacidades de las mochilas (camiones)

    n = paquetes.size();
    
    // Inicializamos las mochilas
    vector<vector<int>> mochilas(3);  // Tres mochilas
    
    // Intentamos resolver usando backtracking
    if (resolverBacktracking(paquetes, capacidades, mochilas, 0)) {
        cout << "Asignación válida encontrada:\n";
        imprimirSolucion(solucion);
    } else {
        cout << "No se encontró una asignación válida.\n";
    }
    
    return 0;
}


