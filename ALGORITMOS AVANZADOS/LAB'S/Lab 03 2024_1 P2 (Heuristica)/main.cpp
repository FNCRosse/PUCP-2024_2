/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 3 de octubre de 2024, 16:11
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Datos{
    int ganacia;
    int Peso;
    int Maximizar;
};
bool comparar (struct Datos & a,struct Datos& b){
    return a.Maximizar > b.Maximizar;
}
void HallarSolucion(vector<struct Datos> &Valores,int pesoMax,int n,int &sobrante,int &gananciaFinal){
    for(int i=0;i<Valores.size();i++){
        Valores[i].Maximizar = Valores[i].ganacia/Valores[i].Peso;
    }
    sort(Valores.begin(),Valores.end(),comparar);
    sobrante = pesoMax;
    gananciaFinal = 0;
    for(int i=0;i<Valores.size();i++){
        if(sobrante - Valores[i].Peso >= 0) {
            sobrante -=Valores[i].Peso;
            gananciaFinal += Valores[i].ganacia;
        }
    }
}
int main(int argc, char** argv) {
    vector<struct Datos> Valores {{10,2},{15,3},{10,5},{24,12},{8,2}};
    int tamno=5;
    int pesoMax =16;
    int sobrante,gananciaFinal;
    HallarSolucion(Valores,pesoMax,tamno,sobrante,gananciaFinal);
    
    cout<<"Solucion empleando un algoritmo heuristico voraz"<<endl;
    cout<<"Peso Sobrante en el contenedor: "<<sobrante<<" Tn"<<endl;
    cout<<"Ganancia de la exportaciónr: "<<gananciaFinal<<" en miles de dólares"<<endl;
    

    return 0;
}

