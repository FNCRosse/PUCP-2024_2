/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 1 de octubre de 2024, 03:15 PM
 */

#include <iostream>
#include <vector>
#include <algorithm>

struct pedido{
    int dimension;
    int cantidad;
    int ganancia;
};

using namespace std;

bool compara(pedido a,pedido b){
    return a.ganancia>b.ganancia;
}

int cortabarras(int *barra,pedido *lote,int nbar,int nped){
   int ganado=0;
   sort(lote,lote+nped,compara);
   
   for(int i=0;i<nped;i++){
       vector<int>temp;
       int cont=0;
       temp.insert(temp.begin(),barra,barra+nbar);
       for(int j=0;j<nbar;){
           if(temp[j]>=lote[i].dimension){
               temp[j]-=lote[i].dimension;
               cont++;
           }
           else
               j++;
           if(cont==lote[i].cantidad){
               ganado+=lote[i].ganancia;
               for(int k=0;k<nbar;k++)barra[k]=temp[k];
               break;
           }
       }
   }
   for(int i=0;i<nbar;i++)
       cout << barra[i] << " "; 
   return ganado;
}

int main(int argc, char** argv) {
    int n=6;
    int nbarras=20;
    int barra[nbarras];
    for(int i=0;i<nbarras;i++)barra[i]=10;
    pedido lote[]={ {10,5,10},
                    {20,10,20},
                    {1,18,15},
                    {3,1,5},
                    {1,1,2},
                    {10,20,1}};
    
    cout << endl<<cortabarras(barra,lote,nbarras,n);
                        
    return 0;
}

