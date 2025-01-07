/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 3 de octubre de 2024, 17:41
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Pedidos {
    int dimension;
    int cantidad;
    int ganancia;
};
bool compara ( struct Pedidos &a, struct Pedidos &b){
    return a.ganancia>b.ganancia;
}
void AtencionDePedidos(vector<int> &Barras, Pedidos *pedidos, int numBarras, int numPed) {
    //El sort es para maximizar por ganacia
    sort(pedidos,pedidos+numPed,compara);
    int GananciaTotal = 0;
    for (int i = 0; i < numPed; i++) {
        //IDEA: Usar la misma barra hasta terminarla o que quede poquito
        // temp[j] -> Es la barra cual voy a seguir usando hasta que no quede
        vector<int> temp(Barras);
        int cont =0;
        for (int k = 0; k < numBarras;) {
            if (temp[k] >= pedidos[i].dimension) {
                temp[k] -= pedidos[i].dimension;
                cont++;
            } else k++;
            if(cont == pedidos[i].cantidad){// Por que tiene q ser pedido total
                Barras.assign(temp.begin(),temp.end());
                GananciaTotal += pedidos[i].ganancia;
                break;
            }
        }
    }
    cout<<"Ganancia: $ "<<GananciaTotal<<" k"<<endl;
    for(int num: Barras) cout<<setw(3)<<num;
}

int main(int argc, char** argv) {
    int numBarras = 20, numPed = 5, tamBarra = 10;
    vector<int> Barras(numBarras, tamBarra);
    struct Pedidos pedidos[]{
        {10, 5, 10},
        {20, 10, 20},
        {1, 18, 15},
        {3, 1, 5},
        {1, 1, 2}};

    AtencionDePedidos(Barras, pedidos, numBarras, numPed);

    return 0;
}

