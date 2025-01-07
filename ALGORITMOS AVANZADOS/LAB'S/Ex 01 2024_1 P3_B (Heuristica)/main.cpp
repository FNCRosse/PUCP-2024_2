/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 3 de octubre de 2024, 19:12
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Telar{
    int tiempo;
    int tiempoTotal;
    vector<int> Telas;
};
struct Nodo{
    int telar;
    int tiempoParcial;
};
bool compara(struct Nodo &a,struct Nodo &b){
    return a.tiempoParcial< b.tiempoParcial;
}
void AsignacionTelares(vector<int>& Telas,vector<struct Telar> &Telares,int numTelares,int n){
    for(int i=0;i<Telas.size();i++){
        vector<struct Nodo>temp;
        Nodo datoParcial;
        for(int k=0;k<Telares.size();k++){
            datoParcial.tiempoParcial = (Telas[i] * Telares[k].tiempo)+ Telares[k].tiempoTotal;
            datoParcial.telar=k;
            temp.push_back(datoParcial); 
        }
        sort(temp.begin(),temp.end(),compara);
        Nodo dato = temp[0];
        Telares[dato.telar].tiempoTotal = dato.tiempoParcial;
        Telares[dato.telar].Telas.push_back(Telas[i]);
    }
    for(int k=0;k<Telares.size();k++){
        cout<<"Telar "<<k<<": ";
        for(int num: Telares[k].Telas){
            cout<<num<<", ";
        }
        cout<<" - Tiempo total de trabajo: "<<Telares[k].tiempoTotal<<" unidades de tiempo"<<endl;
    }
    cout<<"Tiempo total para terminar todas las telas: "<<Telares[numTelares].tiempoTotal<<" unidades de tiempo";
}
int main(int argc, char** argv) {
    vector<int> Telas {10,7,9,12,6,8};
    vector<struct Telar> Telares {{5,0},{4,0},{6,0}};
    int k=3,N=6;
    
    AsignacionTelares(Telas,Telares,k,N);

    return 0;
}

 