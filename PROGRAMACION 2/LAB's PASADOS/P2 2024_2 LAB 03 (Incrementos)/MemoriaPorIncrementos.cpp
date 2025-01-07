#include <iostream>
#include <cstring>
using namespace std;
#include "MemoriaPorIncrementos.hpp"
#include "ConjuntoDeRepartidores.hpp"
#include "Comunes.hpp"
#include "AperturaDeArchivos.h"
#define INCREMENTO 5

void cargar_estructuras(char ***&repartidores, int ***&clientes, double ***&subtotales, char ***cadenas, int **enteros, double **reales) {
    int capacidad,*capDatosCli,*capDatosSub,posRep,nd=0;
    inicializarEstructuras(repartidores,clientes,subtotales,capacidad,capDatosCli,capDatosSub);
    for(int i=0;cadenas[i];i++){
        char **DatoCadena = cadenas[i];
        int *DatoEntero = enteros[i];
        double *DatoReales = reales[i];
        if(nd == capacidad) IncrementarCapacidadEstructura(repartidores,clientes,subtotales,capacidad,capDatosCli,capDatosSub);
        posRep = BuscarRepartidor(repartidores,DatoCadena[0]);
        if( posRep == -1){
            incluirRepartidor(repartidores,nd,DatoCadena[0]);
            incluirCliente(clientes,nd,DatoEntero[0],capDatosCli[nd]);
            incluirSubTotales(subtotales,nd,DatoReales[0],capDatosSub[posRep]);
            nd++;
        } else {
            incluirCliente(clientes,posRep,DatoEntero[0],capDatosCli[posRep]);
            incluirSubTotales(subtotales,posRep,DatoReales[0],capDatosSub[posRep]);
        }
    }
}
void inicializarEstructuras(char ***&repartidores, int ***&clientes, double ***&subtotales, int &capacidad, 
        int *&capDatosCli,int *&capDatosSub){
    capacidad = INCREMENTO;
    repartidores = new char **[capacidad]{};
    clientes = new int **[capacidad]{};
    subtotales = new double **[capacidad]{};
    capDatosCli = new int[capacidad]{};
    capDatosSub = new int[capacidad]{};
    for(int i=0;i<capacidad;i++){
        repartidores[i] = nullptr;
        clientes[i] = nullptr;
        subtotales[i] = nullptr;
        capDatosCli[i]  = 0;
        capDatosSub[i]  = 0;
    }
}
void IncrementarCapacidadEstructura(char ***&repartidores, int ***&clientes, double ***&subtotales, int &capacidad,
        int *&capDatosCli,int *&capDatosSub){
    char ***Buff_Rep = repartidores;
    int *** Buff_clientes = clientes;
    double ***Buff_subtotales =subtotales;
    int * buff_cap_cli = capDatosCli;
    int * buff_cap_Sub = capDatosSub;
    int cap_ant = capacidad;
    capacidad += INCREMENTO;
    repartidores = new char **[capacidad]{};
    clientes = new int **[capacidad]{};
    subtotales = new double **[capacidad]{};
    capDatosCli = new int[capacidad]{};
    capDatosSub = new int[capacidad]{};
    for(int i=0;i<capacidad;i++){
        if(i<cap_ant){
            repartidores[i] = Buff_Rep[i];
            clientes[i] = Buff_clientes[i];
            subtotales[i] = Buff_subtotales[i];
            capDatosCli[i]  = buff_cap_cli[i];
            capDatosSub[i]  = buff_cap_Sub[i];
        } else {
            repartidores[i] = nullptr;
            clientes[i] = nullptr;
            subtotales[i] = nullptr;
            capDatosCli[i]  = 0;
            capDatosSub[i]  = 0;
        }
    }
    delete []Buff_Rep;
    delete []Buff_clientes;
    delete [] Buff_subtotales;
    delete [] buff_cap_cli;
    delete [] buff_cap_Sub;
}
int BuscarRepartidor(char ***&repartidores,char * codigo){
    for(int i=0;repartidores[i];i++){
        char **DatosRep = repartidores[i];
        if(strcmp(DatosRep[0],codigo) ==0) return i;
    }
    return -1;
}
void incluirRepartidor(char ***&repartidores,int posicion,char *codigo){
    ConjuntoDeRepartidores conjuntoRep;
    cargar_conjunto_de_repartidores(conjuntoRep,"repartidores.csv");
    char **DatosRep = new char *[2];
    char *nombre =  conjuntoRep==codigo;
    DatosRep[0] = mi_strdup(codigo);
    DatosRep[1] = mi_strdup(nombre);
    repartidores[posicion] = DatosRep;
}
void incluirCliente(int ***&clientes,int posicion,int dni, int &cap){
    int ** Buff_Cliente = clientes[posicion];
    if(Buff_Cliente == nullptr) InicializarDatoCliente(cap,Buff_Cliente);
    int cant = obtener_cantidad_de_cliente(Buff_Cliente);
    if( cant == cap) IncrementarEspacioDatoCliente(cap,Buff_Cliente);
    Buff_Cliente[cant] = retorna_referencia_a_entero(dni);
    Buff_Cliente[cant+1] = nullptr;
    if( cant == cap) IncrementarEspacioDatoCliente(cap,Buff_Cliente);
    clientes[posicion] = Buff_Cliente;
}
void InicializarDatoCliente(int &capacidad,int **&Dato_Cliente){
    capacidad = INCREMENTO;
    Dato_Cliente = new int *[capacidad]{};
    for(int i=0;i<capacidad;i++){
        Dato_Cliente[i] = nullptr;
    }
}
void IncrementarEspacioDatoCliente(int &cap,int **&Dato_Cliente){
    int **Buff_Datos_clientes = Dato_Cliente;
    int cap_ant = cap;
    cap += INCREMENTO;
    Dato_Cliente = new int *[cap]{};
    for(int i=0;i<cap;i++){
        if(i<cap_ant){
            Dato_Cliente[i] = Buff_Datos_clientes[i];
        } else {
            Dato_Cliente[i] = nullptr;
        }
    }
    delete []Buff_Datos_clientes;
}
void incluirSubTotales(double ***&subtotales,int posicion,double subtotal, int &cap){
    double ** Buff_SubTotal = subtotales[posicion];
    if(Buff_SubTotal == nullptr) InicializarDatoSubtotales(cap,Buff_SubTotal);
    int cant = obtener_cantidad_de_subtotales(Buff_SubTotal);
    if( cant == cap) IncrementarEspacioDatoSubtotales(cap,Buff_SubTotal);
    Buff_SubTotal[cant] = retorna_referencia_a_real(subtotal);
    Buff_SubTotal[cant+1] = nullptr;
    if( cant == cap) IncrementarEspacioDatoSubtotales(cap,Buff_SubTotal);
    subtotales[posicion] = Buff_SubTotal;
}
void InicializarDatoSubtotales(int &capacidad,double **&Dato_Subtotales){
    capacidad = INCREMENTO;
    Dato_Subtotales = new double *[capacidad]{};
    for(int i=0;i<capacidad;i++){
        Dato_Subtotales[i] = nullptr;
    }
}
void IncrementarEspacioDatoSubtotales(int &cap,double **&Dato_Subtotales){
    double **Buff_Datos_Subtotales = Dato_Subtotales;
    int cap_ant = cap;
    cap += INCREMENTO;
    Dato_Subtotales = new double *[cap]{};
    for(int i=0;i<cap;i++){
        if(i<cap_ant){
            Dato_Subtotales[i] = Buff_Datos_Subtotales[i];
        } else {
            Dato_Subtotales[i] = nullptr;
        }
    }
    delete []Buff_Datos_Subtotales;
}
void reporte_de_repartidores(const char*nombre_archivo, char ***repartidores, int ***clientes, double ***subtotales) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombre_archivo);
    for(int i=0;repartidores[i];i++){
        char **DatoRep = repartidores[i];
        int **DatoCliente = clientes[i];
        double **DatoSubtotales = subtotales[i];
        int cantidadClientes = obtener_cantidad_de_cliente(DatoCliente);
        int cantidadSubtotal = obtener_cantidad_de_subtotales(DatoSubtotales);
        double suma=0;
        for(int k=0;k<cantidadSubtotal;k++) suma += *DatoSubtotales[k];
        arch<<DatoRep[1]<<","<<cantidadClientes<<','<<suma<<endl;
    }
}

void reporte_por_repartidor(char ***repartidores, int ***clientes, double ***subtotales) {
    for(int i=0;repartidores[i];i++){
        char **DatoRep = repartidores[i];
        int **DatoCliente = clientes[i];
        double **DatoSubtotales = subtotales[i];
        ofstream arch;
        char nombre[50];
        obtener_nombre_archivo_por_repartidor(nombre,DatoRep[0]);
        AperturaDeUnArchivoDeTextosParaEscribir(arch,nombre);
        
        imprimir_linea(arch,'=');
        arch<<"CODIGO REPARTIDOR: "<<DatoRep[0]<<endl; 
        arch<<"NOMBRE REPARTIDOR: "<<DatoRep[1]<<endl; 
        imprimir_linea(arch,'=');
        arch<<right<<setw(14)<<"DNI CLIENTE"<<setw(25)<<"MONTO POR PEDIDO"<<endl;
        imprimir_linea(arch,'-');
        int cantidadClientes = obtener_cantidad_de_cliente(DatoCliente);
        for(int i=0;i<cantidadClientes;i++){
            arch<<right<<setfill(' ')<<setw(12)<<*DatoCliente[i]<<setfill('.')<<setw(20)<<*DatoSubtotales[i]<<endl;
        }
        imprimir_linea(arch,'=');
    }
}