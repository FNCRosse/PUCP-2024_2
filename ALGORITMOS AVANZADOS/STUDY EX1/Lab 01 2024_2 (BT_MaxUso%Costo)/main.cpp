/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de octubre de 2024, 08:44
 */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Piso{
    int id;
    int cantInter;
    int pesoMaxLav;
    double costo;
    int PesoUsado;
    vector<int> KilosRopa;
    vector<int> solucionA; 
};
void Lavadoras(struct Piso &piso,int capLav,int inicio, int fin,vector<int> &tempsol, int& maxUso,int pesoactual, int uso){
    if ( inicio == fin || pesoactual> capLav){
        if(pesoactual <= capLav && uso > maxUso){
            piso.PesoUsado = pesoactual;
            maxUso = uso;
            piso. solucionA = tempsol;
        }
        return;
    }
    Lavadoras(piso,capLav, inicio +1, fin, tempsol,maxUso,pesoactual,uso);
    if(pesoactual + piso.KilosRopa[inicio] <= capLav){
        tempsol.push_back(inicio+1);
        Lavadoras(piso,capLav,inicio+1,fin,tempsol,maxUso,pesoactual + piso.KilosRopa[inicio], uso +piso.KilosRopa[inicio]/piso.costo );
        tempsol.pop_back();// this backtraking
    }
}
int main(int argc, char** argv) {
    vector<struct Piso> Pisos {
        {1,6,50,5,0,{14,11,10,19,14,11}},
        {2,7,50,6,0,{20,11,11,10,15,17,8}},
        {3,4,50,8,0,{15,16,15,16}},
        {4,5,50,5,0,{11,4,19,12,10}},
        {5,2,50,9,0,{18,12}},
    };
    double porcentaje;
    int totalkilos = 0, captotal=0, maxpiso=0,minpiso=99999999999999;
    int indmin, indmax,KgRopaSobrante, indmaxSob, indminSob;
    for(int i=0;i<Pisos.size();i++){
        vector<int> tempsol;
        int maxUso=0,uso=0;
        Lavadoras(Pisos[i],Pisos[i].pesoMaxLav,0,Pisos[i].cantInter,tempsol,maxUso,0,0);
        cout << "Piso " << Pisos[i].id << " (Capacidad: " << Pisos[i].pesoMaxLav << " kg, Costo: S/" << Pisos[i].costo << " por kg)" << endl;
        cout << "Pacientes con ropa lavada son: ";
        for (int k : Pisos[i].solucionA) {cout << setw(3)<<"R"<<k;
        }
        cout <<endl<< "Pacientes con ropa no lavada son: ";
        for (int k=1,t=0;k<=Pisos[i].KilosRopa.size();k++) {
            if(k == Pisos[i].solucionA[t]) {
                t++;
                continue;
            }
            cout << setw(3)<<"R"<<k;
        }
        KgRopaSobrante = Pisos[i].pesoMaxLav - Pisos[i].PesoUsado;
        cout << "\nTotal de kilos lavados: " << Pisos[i].PesoUsado << " kg" << endl;
        cout << "Total de kilos no lavados: " << KgRopaSobrante << " kg" << endl;
        cout << endl;
        totalkilos += Pisos[i].PesoUsado;
        captotal += Pisos[i].pesoMaxLav;
        if(maxpiso < Pisos[i].PesoUsado){
            maxpiso = Pisos[i].PesoUsado;
            indmax = i+1;
             indminSob = i+1;
        }
        if(minpiso > Pisos[i].PesoUsado){
            minpiso = Pisos[i].PesoUsado ;
            indmin = i+1;
              indmaxSob = i+1;
        }
    }
    porcentaje = (totalkilos/(double)captotal)*100;
    cout<<setprecision(2)<<fixed;
    cout<<"El porcentaje total de las lavadoras es : "<<porcentaje<<"%"<<endl;
    cout<<"El piso que mas ocupa su lavadora es : "<<indmax<<endl;
    cout<<"El piso que menos ocupa su lavadora es : "<<indmin<<endl;
    cout<<"El piso con más kilos de ropa sucia a lavar por los parientes de los interno es : "<<indmaxSob<<endl;
    cout<<"El piso con menos kilos de ropa sucia a lavar por los parientes de los internos es : "<<indminSob<<endl;
    
    return 0;
}

