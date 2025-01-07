/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de octubre de 2024, 15:12
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int CalcularMinAterrizajes(int *arr,int n){
    vector<int> jumps (n,INT_MAX);
    if(n==0 or arr[0] == 0) return INT_MAX;
    jumps[0] = 0;
    for(int i=1; i<n;i++){ //recorre cada ciudad ( i = la ciudad)
        for(int j=0;j<i;j++){ // recorre todas las ciudades anterior, representa la ciudad desde la que el avión podría intentar volar hacia la ciudad i
            // i< j + arr[j] -> verifica que el avian pueda llegar a la CI desde la CJ, significa hay combustible para el vuelo
            // jumps[j] != INT_MAX -> verifica si es un aterrizaje valido
            if(i <= j+ arr[j] && jumps[j] != INT_MAX){
                jumps[i] = min(jumps[i],jumps[j]+1); // actualizar con el numero menor
                // jumps[j] +1 -> necesitamos sumar uno más porque ahora vamos a hacer un aterrizaje adicional en i
            }
        }
    }
    for(int i=0;i<n;i++) cout<<jumps[i]<<" ";
    return jumps[n-1];
}
int main(int argc, char** argv) {
    int arr[] = {5,2,1,4,1},n=5;
    cout<<"El minimo de aterrizajes es : "<<CalcularMinAterrizajes(arr,n);

    return 0;
}

