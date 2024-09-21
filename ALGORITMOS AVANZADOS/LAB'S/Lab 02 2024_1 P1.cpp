/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 20 de abril de 2024, 08:10 AM
 */

#include <iostream>
#include <iomanip>
#define N 5
#define MAXIMO 1000

using namespace std;

int asignarTareas(int tareas[],int cantRobots){
	//arregloSuma[N+1]: Se usa para almacenar la suma acumulativa de las tareas. 
	//Es decir, arregloSuma[i] contendrá la suma de las duraciones de las primeras i tareas.
    int arregloSuma[N+1]={}, dp[N][cantRobots+1], minSuma=MAXIMO, maxSuma=0;
    for(int i=1; i<N+1; i++){
        arregloSuma[i]=arregloSuma[i-1]+tareas[i-1];
    }
    
    /*Inicializamos nuestra matriz*/
    for(int i=0; i<N+1; i++)
        dp[i][0]=0; // Si no hay robots, no hay carga
    for(int i=0; i<=cantRobots; i++)
        dp[0][i]=0; //// Si no hay tareas, la carga es 0
        
    /*Si hay un solo robot, este robot tomará todas las tareas, así que en este caso 
	la carga máxima es la suma total de las tareas, que está en arregloSuma[i]*/
    for(int i=1; i<N+1; i++){
        dp[i][1]=arregloSuma[i];
    }
    
    /*Completamos la matriz*/
    /*El i avanzara en el numero de los robots*/
    /*El j avanzara en el numero de las tareas*/
    /*El k sera la posicion en donse se "parte" el arreglo para 
     dividirse la tarea*/
    for(int i=2; i<=cantRobots; i++){
        for(int j=1; j<N+1; j++){
            for(int k=1; k<j; k++){
                maxSuma=max(dp[k-1][i-1], arregloSuma[j]-arregloSuma[k]);
                /*arregloSuma[j] - arregloSuma[k] nos da la suma de las tareas desde k+1 
				hasta j. Es decir, este valor representa la carga de trabajo total que le 
				corresponde al robot al que se le asignen j-k tareas (las tareas que quedan).*/
				/*dp[k-1][i-1] es el valor de la carga máxima mínima cuando usamos i-1 robots 
				para manejar las primeras k-1 tareas.*/
            }
            dp[j][i]=min(minSuma,maxSuma);
            /*El objetivo es asegurar que al final, después de evaluar todas las particiones posibles, 
			se almacene en dp[j][i] la carga máxima mínima que garantice que el robot más cargado no 
			tenga que realizar mucho más trabajo que los demás, optimizando así la distribución de las 
			tareas entre los robots.*/
        }
    }
    
    
    for(int i=0; i<N+1; i++){
        for(int j=0; j<=cantRobots; j++){
            cout<<right<<setw(10)<<dp[i][j];
        }
        cout<<endl;
    }
  
    /*for(int i=0; i<N+1; i++){
        cout<<arregloSuma[i]<<" ";
    }*/
    return dp[N][cantRobots];
}



int main(int argc, char** argv) {
    int cantRobots=3, mejorAsignacion;
    int tareas[]={15,30,60,45,10};
    mejorAsignacion=asignarTareas(tareas,cantRobots);
    cout<<"El tiempo maximo que utilizarian "<<cantRobots<<" robots seria "<<
            mejorAsignacion<<" min"<<endl;
    return 0;
}

