/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 12 de septiembre de 2024, 15:35
 */
#include "Util.h"
#include "Estructuras.h"
#include "SobreCargar.h"
#include "AperturaDeArchivos.h"

int main(int argc, char** argv) {
    struct Plato ArrPlatos[120];
    struct Repartidor ArrRepartidor[40];
    ifstream archP,archR,archO;
    ofstream archRepPlatos,archRepRep;
    int ndPlatos=0,ndRep=0;
    AperturaDeUnArchivoDeTextosParaLeer(archO,"OrdenesDeCompra.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archP,"PlatosOfrecidos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archR,"RepartidoresContratados.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepPlatos,"ReportePlatos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRepRep,"ReporteRepartidor.txt");
    
    while(true){
        archP>>ArrPlatos[ndPlatos];
        if(archP.eof()) break;
        ndPlatos++;
    }
    strcpy(ArrPlatos[ndPlatos].codigo,"FIN");
    
    
    while(true){
        archR>>ArrRepartidor[ndRep];
        if(archR.eof()) break;
        ndRep++;
    }
    strcpy(ArrRepartidor[ndRep].codigo,"FIN");
    
    
    struct Pedido ped;
    while(true){
        archO>>ped;
        if(archO.eof()) break;
        if(ped <= ArrPlatos){
            ArrRepartidor <= ped;
        }
    }
    for(int i=0; strcmp(ArrRepartidor[i].codigo,"FIN")!=0;i++){
        for(int k=0;k<ArrRepartidor[i].cantidadDeOrdenes;k++){
            !ArrRepartidor[i].ordenesDeCompra[k];
        }
        !ArrRepartidor[i];
    }
    
    for(int i=0; strcmp(ArrPlatos[i].codigo,"FIN")!=0;i++){
        archRepPlatos<<ArrPlatos[i];
    }
    for(int i=0; strcmp(ArrRepartidor[i].codigo,"FIN")!=0;i++){
        archRepRep<<ArrRepartidor[i];
    }

    return 0;
}

