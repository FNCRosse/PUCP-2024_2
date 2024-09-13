/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   MetodoExactoDeMemoria.cpp
 * Author: Rosse
 * 
 * Created on 12 de septiembre de 2024, 15:52
 */
#include "Util.h"
#include "AperturaDeArchivos.h"
#include "MetodoExactoDeMemoria.h"
#include "FuncionesAux.h"
#define NO_ENCONTRADO -1

void lecturaDeLibros(const char*namefile, char ***&Libros, int **&Stock) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,namefile);
    int nd=0, *Buff_Stock[300];
    char **BuffLibros[300];
    while(arch>>BuffLibros[nd]){
        arch>>Buff_Stock[nd];
        nd++;
    }
    Libros = new char**[nd+1]{};
    Stock = new int *[nd+1]{};
    for(int i=0;i<nd;i++) {
        Libros[i] = BuffLibros[i];
        Stock[i] = Buff_Stock[i];
    }
}

void PruebaDeLecturaDeLibros(const char*namefile, char ***Libros, int **Stock) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,namefile);
    for(int i=0;Libros[i];i++){
        char**DatosLibro = Libros[i];
        int* DatoStock = Stock[i];
        arch<<left<<setw(12)<<DatosLibro[0]<<setw(60)<<DatosLibro[1]<<setw(50)<<DatosLibro[2]<<right<<
                setw(5)<<DatoStock[0]<<setw(5)<<DatoStock[1]<<endl;
    }
}

void atencionDePedidos(const char*namefile, char ***Libros, int **&Stock, int **&PedidosClientes,
        char ***&PedidosLibros, bool **&PedidosAtendidos) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,namefile);
    int nd=0, *Buff_PedCliente[180]{},numPed,dni,posCliente,cantPed=0;
    char **Buff_PedLibros[180]{};
    bool *Buff_PedAten[180]{};
    while(true){
        arch>>numPed;
        if(arch.eof()) break;
        arch.get();
        arch>>dni;
        posCliente = BuscarCliente(dni,Buff_PedCliente);
        if(posCliente == NO_ENCONTRADO){
            Buff_PedCliente[nd] = ColocarPedidos(dni,numPed,posCliente,Buff_PedCliente[nd]);
            nd++;
        } else {
            Buff_PedCliente[posCliente] = ColocarPedidos(dni,numPed,posCliente,Buff_PedCliente[posCliente]);
        }
    AgregarLibros(arch,Buff_PedLibros[numPed],Buff_PedAten[numPed],Libros,Stock);
        cantPed++;
    }
    ColocarMemoriaExacta(PedidosClientes,PedidosLibros,PedidosAtendidos,Buff_PedCliente,Buff_PedAten,
            Buff_PedLibros,nd,cantPed);
}

void ReporteDeEntregaDePedidos(const char*namefile, int **PedidosClientes,
        char ***PedidosLibros, bool **PedidosAtendidos) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,namefile);
    for(int i=0;PedidosClientes[i];i++){
        int *DatoCliente = PedidosClientes[i];
        imprimirLinea(arch,'=',70);
        arch<<"CLIENTE:"<<DatoCliente[0]<<endl;
        imprimirLinea(arch,'=',70);
        for(int k=2;k<2+DatoCliente[1];k++){
            int numPed=DatoCliente[k];
            arch<<left<<setw(18)<<"Pedido No,"<<setw(25)<<"Codigo del libro"<<"Observacion"<<endl;
            imprimirLinea(arch,'-',70);
            ImprimirPedido(arch,numPed,PedidosLibros[numPed],PedidosAtendidos[numPed]);
            imprimirLinea(arch,'-',70);
            
        }
    }
}
void ImprimirPedido(ofstream &arch,int numPed,char**PedidosLibros,bool*PedidosAtendidos){
    for(int i=1;PedidosLibros[i];i++){
        char * cad = PedidosLibros[1];
        if(i==1) arch<<right<<setw(5)<<numPed<<left<<setw(18)<<" "<<setw(20)<<PedidosLibros[i];
        else arch<<setw(23)<<" "<<setw(20)<<PedidosLibros[i];
        if(PedidosAtendidos[i] == true) arch<<"ATENDIDO"<<endl;
        if(PedidosAtendidos[i] == false) arch<<"NO ATENDIDO"<<endl;
    }
}
void imprimirLinea(ofstream &arch, char letra, int n){
    for(int i=0;i<n;i++) arch<<letra;
    arch<<endl;
}
