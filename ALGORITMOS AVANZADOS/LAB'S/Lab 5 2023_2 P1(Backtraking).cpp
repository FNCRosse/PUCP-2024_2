#include <iostream>
#include <iomanip>
using namespace std;
#define N 5
int solucion[N][N]{};

bool SolucionValida(int *pedido,int c){
	int suma=0;
	for(int i=0;i<c;i++) suma += pedido[i];
	if(suma == 0) return true;
	return false;
}
bool EsPaquete(int num,int *pedido,int c){
	for(int i=0;i<c;i++){
		if(pedido[i] == num){
			pedido[i] = 0;
			return true;
		}
	}
	return false;
}
void Poner(int num,int *pedido,int c){
	for(int i=0;i<c;i++){
		if(pedido[i] == 0){
			pedido[i] = num;
			break;
		}
	}
}
bool HayPedido(int almacen[][N],int *pedido,int c,int n,int x,int y){
	//Caso base
	if(x==n or y==n) return false;
	if(SolucionValida(pedido,c)) return true;
	//Condidion para marcar
	bool flag = false;
	if(EsPaquete(almacen[x][y],pedido,c)){
		solucion[x][y] = almacen[x][y];
		flag = true;
	}
	//Condiciones para el movimiento
	if (HayPedido(almacen,pedido,c,n,x+1,y)) return true; //abajo
	if (HayPedido(almacen,pedido,c,n,x,y+1)) return true; // derecha
	//Backtraking
	if(flag) Poner(almacen[x][y],pedido,c);
	solucion[x][y]=0;
	return false;
}
void ImprimeProducto(const int producto){
	int tipoNum = producto/100;
	int peso = producto%100;
	char tipo;
	if(tipoNum == 1) tipo = 'A';
	if(tipoNum == 2) tipo = 'M';
	if(tipoNum == 3) tipo = 'V';
	cout<<right<<setw(2)<<peso<<"("<<tipo<<")";
}
void imprimeSolucion(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(solucion[i][j] !=0){
				ImprimeProducto(solucion[i][j]);
				if(solucion[i][j+1] == 0){
					cout<<right<<setw(3)<<solucion[i][j+1]<<" ";
					j++;
				}  
			} 
			else cout<<right<<setw(4)<<solucion[i][j];
		}
		cout<<endl;
	}
}
int main(){
	//A=1,M=2,V=3
	int n=5,c=4;
	int pedido[c]={105,301,250,108};
	int almacen[N][N] = {{120,310,110,225,210},
						{110,301,210,105,315},
						{301,220,250,205,101},
						{325,110,108,105,315},
						{210,202,208,210,110}};
						
	if(HayPedido(almacen,pedido,c,n,0,0)){
		imprimeSolucion(n);
	}else{
		cout<<"No hay solucion"<<endl;
	}
	return 0;
}
