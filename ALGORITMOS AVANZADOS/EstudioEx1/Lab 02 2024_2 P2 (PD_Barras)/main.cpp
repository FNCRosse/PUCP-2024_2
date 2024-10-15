/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de octubre de 2024, 11:27
 */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int CalcularGananciaTotal(vector<int> &precio,vector<int> &longitud){
    int n = precio.size();
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++) dp[0][i] = 0;
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(longitud[i-1] <= j){
                dp[i][j] = max(precio[i-1] + dp[i][j-longitud[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << left << setw(3) << dp[i][j];
        }
        cout << endl;
    }
    return dp[n][n];
}
int main(int argc, char** argv) {
    vector<int> precio {2,5,7,8} ;
    vector<int> longitud {1,2,3,4} ;
    int ganancia = CalcularGananciaTotal(precio,longitud);
    cout<<"La ganacia maxima obtenida es "<<ganancia<<endl;
    return 0;
}

