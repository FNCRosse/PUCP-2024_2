//LABORATORIO 5 2023-2 ALGORITMIA
//Es el mismo esquema que el problema de la mochila
#include <iostream>
using namespace std;
#define N 5
int RobotDespacha(int x,int y,int c,int *ped,int alma[][N],int solu[][N]){
	if(valida()) return 1;
	if(x==N or y==N) return 0; //Si se sale del tablero
	//Condiciones de avance
	if(RobotDespacha(x+1,y,c,ped,alma,solu)) return 1;
	if(RobotDespacha(x,y+1,c,ped,alma,solu)) return 1;
	
	solu[x][y] = 0;
	//Si falla hacemos backtraking
}
int main (int argc,char** argv){
	//Colocar las matrices
	//A:1, M:2, V:3
	int alma[N][N] = {{120,310,110,225,210},
					  {110,301,210,105,315},
					  {301,220,250,205,101},
					  {325,110,108,105,315},
					  {210,202,208,210,110},};
	int solu[N][N];
	int c=4;
	int ped[c]={105,301,250,108};
	//Alma, ped y solu pueden tambien ser globales para no tener tanto parametro
	cout<<RobotDespacha(0,0,c,ped,alma,solu);
}
