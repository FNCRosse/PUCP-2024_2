#include <iostream>
using namespace std;
int empaca(int *paq,int peso,int n,int index){
	//Caso base, == por que es un arreglo
	if(index == n or peso<0) return 0 ;
	//Aqui no hay otra variable, sino como voy tomando los peso y le resto al peso
	if(paq[index]== peso) return 1;
	if(empaca(paq,peso-paq[index],n,index+1)){
		return 1;
	}
	//Aqui es donde le sumo a las variables globales
	else{
		//esto es cuando la solucion salio mal y tengo q omitir
		//En caso de usar variables globales, aqui es donde se 
		// se borra lo que lo aplicaste
		return empaca(paq,peso,n,index+1);
	}
}
int main (int argc,char** argv){
	int n=4, peso =22;
	int paq[]={1,3,12,5};
	int posicion = 0;
	cout<<empaca(paq,peso,n,posicion);
}
