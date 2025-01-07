/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de octubre de 2024, 18:24
 */

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;
bool esCapicua(vector<int>& mensaje, int inicio, int fin){
    for(;inicio<fin;inicio++,fin--){
        if(mensaje[inicio] != mensaje[fin]) return false;
    }
    return true;
}
int CantidadCortes(vector<int>& mensaje, int n){
    //Lo inicializamos con INT_MAX por que buscas una solucion eficiente, cuanto menos
    //Corte hagas mas eficiente es
    vector<int> fn (n,INT_MAX);
    //Si solo hay un elemento pues hay 0 cortes
    fn[0] = 0;
    for(int i=1;i<n;i++){ // Recorre el arreglo
        //si todo el subarreglo de 0 a i es capicua , no hay cortes por realizar
        // EJ: [11, 20, 20, 11] y i = 3 -> true -> no requiere cortes
        if( esCapicua(mensaje,0,i)) fn[i] = 0;
        else { // Buscamos la mejor manera de hacer cortes
            for(int j = 0; j < i ;j++){ // buscar subArreglos Capicuas que termina en i
                if( esCapicua(mensaje,j+1,i)){ 
                    //Tenemos una particion valida
                    fn[i] = min(fn[i], fn[j]+1);
                }
            }
        }
    }
    for( int num: fn) cout<<setw(2)<<num;
    cout<<endl;
    return fn[n-1];
}
int main(int argc, char** argv) {
    vector<int> mensaje1 {10,20,20,10,11,23,13,23,30,25};
    vector<int> mensaje2 {16,22,22,52,11,11,11,4,28,19,28,28};
    int n = mensaje1.size(), m = mensaje2.size();
    cout<<"cantidad de cortes son: "<<CantidadCortes(mensaje1,n )<<endl;
    cout<<"cantidad de cortes son: "<<CantidadCortes(mensaje2,m )<<endl;

    return 0;
}

