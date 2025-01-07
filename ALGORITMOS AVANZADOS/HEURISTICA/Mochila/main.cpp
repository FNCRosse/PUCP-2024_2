/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 24 de septiembre de 2024, 03:20 PM
 */

#include <iostream>
#include <algorithm>

using namespace std;

bool compara(int a,int b){
    return a>b;
}

int cargamochila(int *paq,int peso,int n){
    sort(paq,paq+n,compara);
    
    int resto=peso;
    for(int i=0;i<n;i++)
        if(resto-paq[i]>=0)
            resto-=paq[i];
        
    return resto;
}

int main(int argc, char** argv) {
    int paq[]={10,12,5,2};
    int n,peso=15;
    n = sizeof(paq)/sizeof(paq[0]);
    
    cout <<"El residual:" <<cargamochila(paq,peso,n);

    return 0;
}

