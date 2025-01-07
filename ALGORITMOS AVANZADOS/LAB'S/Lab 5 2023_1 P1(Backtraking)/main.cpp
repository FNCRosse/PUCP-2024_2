/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 3 de septiembre de 2024, 10:33
 */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
#include "Controles.h"
vector<class Controles> Solucion;
int contador=0;
int indexGananciaMayor;
int GananciaMayor;

void ColocarControles(vector<class Controles> &ArrControl, int id,int inversion,
        int* Requisitos,int beneficios){
    class Controles control;
    vector<int> requi;
    control.SetId(id);
    control.SetInversion(inversion);
    for(int i=0; Requisitos[i]!=0;i++) requi.push_back(Requisitos[i]);
    control.SetRequisitos(requi);
    control.SetBeneficio(beneficios);
    ArrControl.push_back(control);
}
void imprime(){
    cout<<"Solucion: "<<contador<<endl;
    for(class Controles control : Solucion){
        cout<<control.id<<"  "<<right<<setw(7)<<control.inversion;
        cout<<right<<setw(8)<<control.Beneficio;
        if(!control.Requisitos.empty()) for(int requi: control.Requisitos) cout<<setw(2)<<requi;
        cout<<endl;
    }
}
bool EncontroRequisito(int requi){
    for(class Controles control : Solucion){
        if(control.id == requi) return true;
    }
    return false;
}
int ObtenerGanacia(){
    int gananciaParcial=0;
    for(class Controles control : Solucion){
        gananciaParcial += control.Beneficio;
    }
    return gananciaParcial;
}
bool validacion(){
    int cumpleRequisito=0;
    for(class Controles control : Solucion){
        if(!control.Requisitos.empty()){
            int existe=0;
            for(int requi: control.Requisitos){
                if(EncontroRequisito(requi)) existe++;
            }
            if(existe == control.Requisitos.size()) cumpleRequisito++;
        } else cumpleRequisito++;
    }
    if(cumpleRequisito == Solucion.size()) return true;
    else return false;
}
void MaximoBeneficios(int P,vector<class Controles>ArrControl,int i){
    if(P==0 and validacion()){
        contador++;
        int GananciaParcial=ObtenerGanacia();
        imprime();
        cout<<"Beneficio generado: "<<GananciaParcial<<endl<<endl;
        if(GananciaParcial > GananciaMayor) {
            GananciaMayor = GananciaParcial;
            indexGananciaMayor = contador;
        }
        return;
    }
    if(i==ArrControl.size() or P<0) return;
    
    Solucion.push_back(ArrControl[i]);
    MaximoBeneficios(P-ArrControl[i].inversion,ArrControl,i+1);
    
    Solucion.pop_back();
    MaximoBeneficios(P,ArrControl,i+1);
}
int main(int argc, char** argv) {
    int P = 100000;
    vector<class Controles> ArrControl;
    int requisitos1[3]{};
    int requisitos2[3]={1,2,0};
    int requisitos3[3]={6,0,0};
    int requisitos4[3]={2,0,0};
    ColocarControles(ArrControl,1,32000,requisitos1,60000);
    ColocarControles(ArrControl,2,8000,requisitos1,32000);
    ColocarControles(ArrControl,3,40000,requisitos2,120000);
    ColocarControles(ArrControl,4,40000,requisitos1,60000);
    ColocarControles(ArrControl,5,20000,requisitos1,32000);
    ColocarControles(ArrControl,6,4000,requisitos4,20000);
    ColocarControles(ArrControl,7,20000,requisitos3,48000);
    ColocarControles(ArrControl,8,20000,requisitos3,60000);
    
    
    MaximoBeneficios(P,ArrControl,0);
    cout<<"La Solucion con mayor ganancia es : "<<indexGananciaMayor<<" Con una ganancia de "
            <<GananciaMayor;
    return 0;
}

