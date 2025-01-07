/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 1 de octubre de 2024, 02:24 PM
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8

using namespace std;

struct nodo{
    int punto;
    int distancia;
};

bool compara(nodo a,nodo b){
    return a.distancia<b.distancia;
}

int minruta(int ini,int fin,int mapa[][MAX]){
    int total=0;
    int ciudad=ini;
    while(1){
        vector<nodo>vecinos;
        nodo paso;
        //Cargando vecinos
        for(int i=0;i<MAX;i++){
            if(mapa[ciudad][i]>0){
                paso.punto=i;
                paso.distancia=mapa[ciudad][i];
                vecinos.push_back(paso);
            }
        }
        if(not vecinos.empty()){
            sort(vecinos.begin(),vecinos.end(),compara);
            ciudad = vecinos[0].punto;
            total+=vecinos[0].distancia;
        }
        else{
            cout <<"No se encontro la solucion";
            total= 0;
            break;
        }
        if(ciudad==fin) break;
    }
    
    return total;
}


int main(int argc, char** argv) {
    int mapa[][MAX]={{0,4,5,6,0,0,0,0},
                     {0,0,0,0,2,0,0,0},
                     {0,0,0,0,0,0,0,3},
                     {0,0,0,0,0,3,0,0},
                     {0,0,0,0,0,0,10,0},
                     {0,0,0,0,0,0,2,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0}};
    
    cout << endl<<minruta(2,6,mapa);
    return 0;
}

