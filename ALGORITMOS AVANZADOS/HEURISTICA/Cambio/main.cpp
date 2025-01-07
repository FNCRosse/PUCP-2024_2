/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 24 de septiembre de 2024, 02:35 PM
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void buscambio(int monto,int *deno,int n){
    vector<int>sol;
    sort(deno,deno+n);
    
    for(int i=n-1;i>=0;i--){
        while(monto>=deno[i]){
            monto-=deno[i];
            sol.push_back(deno[i]);
        }
    }
    for(int i=0;i<sol.size();i++)
        cout << sol[i]<<" ";
}


int main(int argc, char** argv) {
    
    int monto=27;
    int deno[]={50,100,2,1,5,10,20};
    buscambio(monto,deno,sizeof(deno)/sizeof(deno[0]));

    return 0;
}

