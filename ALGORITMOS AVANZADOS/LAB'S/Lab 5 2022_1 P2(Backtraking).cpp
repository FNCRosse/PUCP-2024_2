#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 20
#define MAX_MOV 8
int movimientos[8][2];
char Solucion[MAX][MAX];
int contador = 0;

void generarMovimientos(){
	/*Arriba, abajo, izquierda, derecha, no precisamente en ese orden*/
	movimientos[0][0] = 1; movimientos[0][1] = 0;
	movimientos[1][0] = 0; movimientos[1][1] = -1;
	movimientos[2][0] = 0; movimientos[2][1] = 1;
	movimientos[3][0] = -1; movimientos[3][1] = 0;
	
	/*Ahora las diagonales*/
	movimientos[4][0] = 1; movimientos[4][1] = 1;
	movimientos[5][0] = -1; movimientos[5][1] = -1;
	movimientos[6][0] = 1; movimientos[6][1] = -1;
	movimientos[7][0] = -1; movimientos[7][1] = 1;
}
int imprime(char tablero[MAX][MAX],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<setw(3)<<tablero[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
void inicializarTablero(char tablero[MAX][MAX]){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			tablero[i][j] = '0';
		}
	}
}
bool EsValido(int x,int y,int n,int m,char tablero[MAX][MAX]){
	if(x>=0 and y>= 0 and x<n and y<m and tablero[x][y] != '*' and Solucion[x][y] == '0')
	return true;
	return false;
}
bool ResolverRuta(char tablero[MAX][MAX],int n,int m,int x,int y,char paso){
	//Caso base : que llegue al punto final
	if(x == n-1 and y==m-1){
		contador++;
		cout<<"Solucion "<<contador<<":"<<endl;
		imprime(Solucion,n,m);
		if(contador == 20) return true;
		else return false;
	}
	//Buscar por los 8 lados a donde moverse
	for(int i=0;i<MAX_MOV;i++){
		int nueva_x = x + movimientos[i][0];
		int nueva_y = y + movimientos[i][1];
		//Verificar si ese movimiento es valido
		if(EsValido(nueva_x,nueva_y,n,m,tablero)){
			Solucion[nueva_x][nueva_y] = paso + 1;
			if(ResolverRuta(tablero,n,m,nueva_x,nueva_y,paso+1))return true;
			//Backtraking
			Solucion[nueva_x][nueva_y] = '0';
		}
	}
	return false;
}
void colocarMinas(char tablero[MAX][MAX]){
	tablero[0][4] = '*';
	tablero[2][2] = '*';
	tablero[4][1] = '*';
	tablero[4][2] = '*';
	tablero[4][4] = '*';
	tablero[5][1] = '*';
	tablero[5][2] = '*';
	tablero[5][4] = '*';
	tablero[6][1] = '*';
	tablero[6][3] = '*';
	tablero[7][0] = '*';
	tablero[7][1] = '*';
	tablero[7][2] = '*';
	tablero[7][3] = '*';
}
int main(){
	char tablero[MAX][MAX],paso='A';
	int n=9,m=5;
	
	generarMovimientos();
	inicializarTablero(tablero);
	inicializarTablero(Solucion);
	colocarMinas(tablero);
	colocarMinas(Solucion);
	
	Solucion[0][0] = paso;
	ResolverRuta(tablero,n,m,0,0,paso);
	
	
	return 0;
}
