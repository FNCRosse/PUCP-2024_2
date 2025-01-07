/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 3 de septiembre de 2024, 12:05
 */

#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 10
#define MAX_MOV 8
int movimientos[8][2];
int Solucion[MAX][MAX];

void generarMovimientos() {
    /*Arriba, abajo, izquierda, derecha, no precisamente en ese orden*/
    movimientos[0][0] = 1;
    movimientos[0][1] = 0;
    movimientos[1][0] = 0;
    movimientos[1][1] = -1;
    movimientos[2][0] = 0;
    movimientos[2][1] = 1;
    movimientos[3][0] = -1;
    movimientos[3][1] = 0;

    /*Ahora las diagonales*/
    movimientos[4][0] = 1;
    movimientos[4][1] = 1;
    movimientos[5][0] = -1;
    movimientos[5][1] = -1;
    movimientos[6][0] = 1;
    movimientos[6][1] = -1;
    movimientos[7][0] = -1;
    movimientos[7][1] = 1;
}

void imprime(int tablero[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(3) << tablero[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void inicializarTablero(int tablero[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            tablero[i][j] = 0;
        }
    }
}

bool EsValidoElMovimiento(int x, int y, int n, int m) {
    if (x >= 0 and x < n and y >= 0 and y < m and Solucion[x][y] == 0) {
        return true;
    }
    return false;
}


bool CaminoValido(int x, int y, int n, int m, int dir, int c) {
    int k = 0;
    for (k = 0; k < c; k++) {
        if (!EsValidoElMovimiento(x, y, n, m)) break;
        x += movimientos[dir][0];
        y += movimientos[dir][1];
    }
    if (k == c) return true;
    return false;
}

void marcar(int x, int y, int dir, int n, int m, int c, int num) {
    int nueva_x = x, nueva_y = y;
    for (int i = c; i > 0; i--) {
        Solucion[nueva_x][nueva_y] = num;
        nueva_x -= movimientos[dir][0];
        nueva_y -= movimientos[dir][1];
    }
}

bool CalcularRectangulos(int cesped[][MAX], int n, int m, int c, int x, int y, int cantidad) {
    //Caso base o condicion de parada
    bool hayMovimientoValido = false;
    int nueva_x = x, nueva_y = y, dir, X_c, Y_c;
    for (int i = 0; i < MAX_MOV; i++) {
        if (EsValidoElMovimiento(nueva_x, nueva_y, n, m)) {
            for (int dir = 0; i < MAX_MOV; i++) {
                X_c = nueva_x, Y_c = nueva_y;
                if (CaminoValido(X_c, Y_c, n, m, dir, c)) {
                    marcar(nueva_x, nueva_y, dir, n, m, c, cantidad);
                    imprime(Solucion, n, m);
                    if (CalcularRectangulos(cesped, n, m, c, nueva_x, nueva_y, cantidad + 1)) return true;
                    //backtraking
                    marcar(nueva_x, nueva_y, dir, n, m, c, 0);
                    imprime(Solucion, n, m);
                }
            }
        }
        nueva_x = x + movimientos[i][0];
        nueva_y = y + movimientos[i][1];
    }
    if (!hayMovimientoValido) return true; 
    return false;
}

int main(int argc, char** argv) {
    int n = 4, m = 5, c = 3, cantidad = 1;
    int cesped[MAX][MAX]{};
    inicializarTablero(cesped);
    inicializarTablero(Solucion);
    generarMovimientos();

    CalcularRectangulos(cesped, n, m, c, 0, 0, cantidad);
    imprime(Solucion, n, m);
    return 0;
}

