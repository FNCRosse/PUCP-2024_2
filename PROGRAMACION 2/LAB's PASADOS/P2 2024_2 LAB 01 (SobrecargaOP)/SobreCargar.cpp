/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   SobreCargar.cpp
 * Author: Rosse
 * 
 * Created on 12 de septiembre de 2024, 17:15
 */
#include "Util.h"
#include "SobreCargar.h"
#include "Estructuras.h"

void operator>>(ifstream &arch, struct Plato &pla) {
    //PI-488,PIQUEOS CHORIZOS COCKTAIL,16.90,PIQUEO
    arch.getline(pla.codigo, 7, ',');
    if (arch.eof()) return;
    arch.getline(pla.nombre, 60, ',');
    arch >> pla.precio;
    while (arch.get() != '\n');
    pla.totalDePedidos = 0;
    pla.totalRecaudado = 0;
}

void operator>>(ifstream &arch, struct Repartidor &rep) {
    //JNV387,Justino Norabuena Virginia Karina,Motocicleta
    arch.getline(rep.codigo, 7, ',');
    if (arch.eof()) return;
    arch.getline(rep.nombre, 60, ',');
    arch.getline(rep.tipoDeVehiculo, 60, '\n');
    rep.cantidadDeOrdenes = 0;
    rep.pagoPorEntregas = 0;
}

void operator>>(ifstream &arch, struct Pedido &ped) {
    //15290194  BR-283    1    MCE193    11.69
    arch >> ped.dniDelCliente;
    if (arch.eof()) return;
    arch >> ped.codigoDelPlato;
    arch >> ped.cantidad;
    arch >> ped.codigoDelRepartidor;
    arch >> ped.distanciaARecorrer;
    ped.precio = 0;
}

bool operator<=(struct Pedido &ped, struct Plato *ArrPlato) {
    for (int i = 0; strcmp(ArrPlato[i].codigo, "FIN") != 0; i++) {
        if (strcmp(ArrPlato[i].codigo, ped.codigoDelPlato) == 0) {
            ped.precio = ArrPlato[i].precio;
            ArrPlato[i].totalDePedidos++;
            ArrPlato[i].totalRecaudado += ArrPlato[i].precio;
            return true;
        }
    }
    return false;
}

int BuscarCliente(int dniDelCliente, struct OrdenDeCompra *ordenesDeCompra, int cant) {
    for (int i = 0; i < cant; i++) {
        if (ordenesDeCompra[i].dniDelCliente == dniDelCliente) return i;
    }
    return -1;
}

int BuscarPlatos(const char* codPlato, struct PlatoSolicitado *platos, int cant) {
    for (int i = 0; i < cant; i++) {
        if (strcmp(codPlato, platos[i].codigo) == 0) return i;
    }
    return -1;
}

void AgregarPlato(const struct Pedido &Ped, int posCliente, struct OrdenDeCompra &orden) {
    int posPlato = BuscarPlatos(Ped.codigoDelPlato, orden.platosSolicitados, orden.cantidadDePlatos);
    if (posPlato == -1) {//es nuevo plato
        struct PlatoSolicitado platosol;
        strcpy(platosol.codigo, Ped.codigoDelPlato);
        platosol.precio = Ped.precio;
        platosol.cantidad = Ped.cantidad;
        orden.platosSolicitados[orden.cantidadDePlatos] = platosol;
        orden.cantidadDePlatos++;
    } else {
         orden.platosSolicitados[orden.cantidadDePlatos].cantidad += Ped.cantidad;
    }
}

void operator<=(struct Repartidor *ArrRep, const struct Pedido &Ped) {
    for (int i = 0; strcmp(ArrRep[i].codigo, "FIN") != 0; i++) {
        if (strcmp(ArrRep[i].codigo, Ped.codigoDelRepartidor) == 0) {
            struct Repartidor RepEncontrado = ArrRep[i];
            int posCliente = BuscarCliente(Ped.dniDelCliente, RepEncontrado.ordenesDeCompra, RepEncontrado.cantidadDeOrdenes);
            if (posCliente == -1) {//Nuevo cliente
                struct OrdenDeCompra orden;
                orden.dniDelCliente = Ped.dniDelCliente;
                orden.distancia = Ped.distanciaARecorrer;
                orden.cantidadDePlatos = 0;
                orden.montoPorCobrar = 0;
                orden.pagoPorEnvio = 0;
                AgregarPlato(Ped, posCliente, orden);
                RepEncontrado.ordenesDeCompra[RepEncontrado.cantidadDeOrdenes] = orden;
                RepEncontrado.cantidadDeOrdenes++;
                ArrRep[i] = RepEncontrado;
            } else {
                AgregarPlato(Ped, posCliente, RepEncontrado.ordenesDeCompra[posCliente]);
            }

        }
    }
}

void operator!(struct OrdenDeCompra &orden) {
    for(int i=0;i<orden.cantidadDePlatos;i++){
        struct PlatoSolicitado platosol = orden.platosSolicitados[i];
        orden.montoPorCobrar += platosol.precio*platosol.cantidad;
        if(orden.distancia < 8) orden.pagoPorEnvio = 10.50;
        if(orden.distancia >= 8 and orden.distancia<12) orden.pagoPorEnvio = 14.80;
        if(orden.distancia >= 12 and orden.distancia<20) orden.pagoPorEnvio = 23.60;
        if(orden.distancia >= 20 ) orden.pagoPorEnvio = 31.70;
    }

}

void operator!(struct Repartidor &Rep) {
    for(int i=0;i<Rep.cantidadDeOrdenes;i++){
        struct OrdenDeCompra orden = Rep.ordenesDeCompra[i];
        Rep.pagoPorEntregas += orden.montoPorCobrar;
    }
}

void operator<<(ofstream &arch, const struct Plato &pla) {
    arch << left << setw(10) << pla.codigo << setw(60) << pla.nombre << right << setw(10) << pla.precio << setw(10)
            << pla.totalDePedidos << setw(12) << pla.totalRecaudado << endl;

}

void operator<<(ofstream &arch, const struct Repartidor &rep) {
    arch << left << setw(10) << rep.codigo << setw(60) << rep.nombre << setw(20) << rep.tipoDeVehiculo
            << right << setw(10) << rep.pagoPorEntregas << endl;
    arch << "Ordenes Entregadas:" << endl;
    for (int i = 0; i < rep.cantidadDeOrdenes; i++) {
        struct OrdenDeCompra orden = rep.ordenesDeCompra[i];
        arch << right << setw(12) << orden.dniDelCliente << right << setw(8) << orden.distancia << setw(8)
                << orden.montoPorCobrar << setw(8) << orden.pagoPorEnvio << endl;
        arch << left << "    Platos Solicitados:" << endl;
        for (int k = 0; k < orden.cantidadDePlatos; k++) {
            struct PlatoSolicitado platoSol = orden.platosSolicitados[k];
            arch << "    - " << left << setw(10) << platoSol.codigo << right << setw(10) << platoSol.precio << setw(10) <<
                    platoSol.cantidad << setw(10) << platoSol.precio * platoSol.cantidad << endl;
        }
    }
    arch << endl;
}
