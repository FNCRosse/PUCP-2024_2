//LABORATORIO 5 2022-1 ALGORITMIA P2
// Problama del robot detecta minas
#include <iostream>
#include <iomanip>
using namespace std;
#define N 5

int Buscaminas(char Terreno[N][M],int n, int m,int x, int y,char solu[N][M],char paso){
	//Caso base
	if(x == n-1 and y==m-1){//Eso significa que ya llego a la final de la matriz
		//Imprime(n,m,solu);
		return 1;
	}
}
int main (int argc,char** argv){
	int n=9,m=5;
	char paso = 'A';//es nuestro primer paso
	char Terreno[N][M],Solu[N][M];
	
	generatepos(); // ahi esta los movimientos
	generateTable(Terreno,n,m); //Creas el terreno lleno de 0
	generateTable(Solu,n,m); //inicializas toda la solu en 0
	cargaminas(Terreno); //Colocas minas en el terreno
	
	//Primer paso seria que el primero ya sea este marcado por el paso
	Solu[0][0] = paso;
	cout<<Buscaminas(Terreno,n,m,0,0,solu,paso)<<endl;
}
