/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de octubre de 2024, 10:56
 */

#include <iostream>
#include <vector>
using namespace std;
int N=4, M=5;
vector<int>solucion1 (M,0);
vector<int>solucion2 (M,0);
void imprime(vector<int> solu){
    cout<<"{ ";
    for(int num: solu){
        cout<<num<<" , ";
    }
    cout<<"}"<<endl;
}
bool UnaMochila(vector<int> & prod, vector<int> cap,int indice,int fin){
    if(indice == fin-1){
        imprime(solucion2);
        return true;
    }
    for(int i=0;i<fin;i++){
        if(cap[i] >= prod[indice]){
            cap[i] -= prod[indice];
            solucion2[i] += prod[indice];
            if(UnaMochila(prod,cap,indice+1,M)) return true;
            cap[i] += prod[indice];
            solucion2[i] -= prod[indice];
        }
    }
    return false;
}
void TodasMochilas(vector<int> & prod, vector<int> cap,int indice,int fin){
    if(indice == fin-1){
        imprime(solucion1);
        return;
    }
    for(int i=0;i<fin;i++){
        if(cap[i] >= prod[indice]){
            cap[i] -= prod[indice];
            solucion1[i] += prod[indice];
            TodasMochilas(prod,cap,indice+1,M);
            cap[i] += prod[indice];
            solucion1[i] -= prod[indice];
        }
    }
}
int main(int argc, char** argv) {
    vector<int> productos {2,3,1,4};
    vector<int> capacidad {3,2,5,1,3};
    cout<<"Todas la soluciones"<<endl;
    TodasMochilas(productos,capacidad,0,M);
    
    cout<<endl<<"Una solucion"<<endl;
    UnaMochila(productos,capacidad,0,M);
    

    return 0;
}

