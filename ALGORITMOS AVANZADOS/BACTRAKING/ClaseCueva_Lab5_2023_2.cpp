//LABORATORIO 5 2023-2 ALGORITMIA
//Es el mismo esquema que el problema de la mochila
#include <iostream>
#include <iomanip>
using namespace std;
#define N 5
bool valida(int *ped,int c){
	int suma =0;
	for(int i=0;i<c;i++) suma += ped[i];
	if(suma == 0) return true;
	return false;
}
bool EstaElPedido(int *ped,int c, int num){
	for(int i=0;i<c;i++){
		if(ped[i] == num) return true;
	}
	return false;
}
void Quita(int num,int *ped,int c){
	for(int i=0;i<c;i++){
		if(ped[i] == num){
			ped[i] = 0;
			break;
		}
	}
}
void Pone(int num,int *ped,int c){
	for(int i=0;i<c;i++){
		if(ped[i] == 0){
			ped[i] = num;
			break;
		}
	}
}
int RobotDespacha(int x,int y,int c,int *ped,int alma[][N],int solu[][N]){
	int num; //Ahorro para no pasar mucho parametros
	if(valida(ped,c)) return 1;
	if(x==N or y==N) return 0; //Si se sale del tablero
	//Funcion para verificar si encontro el pedido
	num = alma[x][y];
	int bandera =0;
	if(EstaElPedido(ped,c,num)){
		solu[x][y] = num;
		Quita(num,ped,c);
		bandera = 1;
	}
	//Condiciones de avance
	if(RobotDespacha(x+1,y,c,ped,alma,solu)) return 1; 
	if(RobotDespacha(x,y+1,c,ped,alma,solu)) return 1;//Si falla va la derecha
	//Si falla hacemos backtraking
	if(bandera) Pone(num,ped,c); // solo si lo quite lo pongo
	solu[x][y] = 0;
	
}
int main (int argc,char** argv){
	//Colocar las matrices
	//A:1, M:2, V:3
	int alma[N][N] = {{120,310,110,225,210},
					  {110,301,210,105,315},
					  {301,220,250,205,101},
					  {325,110,108,105,315},
					  {210,202,208,210,110},};
	int solu[N][N]{};
	int c=4;
	int ped[c]={105,301,250,108};
	//Alma, ped y solu pueden tambien ser globales para no tener tanto parametro
	//SI hay de 8 a 16 movimientos si hay que hacer una matriz de movimiento
	cout<<RobotDespacha(0,0,c,ped,alma,solu)<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<setw(4)<<solu[i][j];
		}
		cout<<endl;
	}
}
