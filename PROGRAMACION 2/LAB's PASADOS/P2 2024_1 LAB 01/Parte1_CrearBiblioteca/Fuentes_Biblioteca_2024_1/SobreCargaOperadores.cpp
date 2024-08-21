/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   SobreCargaOperadores.cpp
 * Author: Rosse
 * 
 * Created on 21 de agosto de 2024, 07:44
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "SobreCargaOperadores.h"
#include "Estructuras.h"

// LECTURA //
bool operator >> (ifstream &arch, struct Libro &lib){
    arch.getline(lib.codigo,8,',');
    if(arch.eof()) return false;
    arch.getline(lib.tiltulo,80,',');
    arch.getline(lib.autor,60,',');
    arch>>lib.stock;
    arch.get();
    arch>>lib.precio;
    arch.get();
    return true;
}
bool operator >> (ifstream &arch, struct Cliente &cli){
    arch>>cli.dni;
    if(arch.eof()) return false;
    arch.get();
    arch.getline(cli.nombre,60,'\n');
    cli.cantDeLibros =0 ;
    cli.pagoTotal=0;
    return true;
}
// OPERACIONES
bool operator >> (struct LibroSolicitado &lib, struct Libro *arreglo){
    for(int i=0;strcmp(arreglo[i].codigo,"FIN")!=0;i++){
        if(strcmp(arreglo[i].codigo,lib.codigoDelLibro)==0){
            if(arreglo[i].stock>0){
                arreglo[i].stock--;
                lib.precio = arreglo[i].precio;
                lib.atendido = true;
                return true;
            } else {
                arreglo[i].stock = 0;
                lib.atendido = false;
                return false;
            }
        }
    }
    return false;
}
bool operator << (struct Cliente &cli, const struct LibroSolicitado &lib){
    if (cli.cantDeLibros >= 30) return false;
    int i = cli.cantDeLibros;
    cli.librosSolicitados[i].atendido = lib.atendido;
    cli.librosSolicitados[i].numeroDePedido = lib.numeroDePedido;
    cli.librosSolicitados[i].precio = lib.precio;
    strcpy(cli.librosSolicitados[i].codigoDelLibro,lib.codigoDelLibro);
    cli.cantDeLibros++;
    return true;    
}
struct Cliente & operator ++(struct Cliente &cli){
    for(int i=0;i< cli.cantDeLibros;i++) cli.pagoTotal += cli.librosSolicitados[i].precio;
}

//IMPRESION
void operator <<(ofstream &arch, const struct Libro &lib){
    arch<<left<<setw(15)<<lib.codigo<<setw(40)<<lib.tiltulo<<setw(40)<<lib.autor<<setw(6)<<lib.stock
            <<lib.precio<<endl;
}
void operator <<(ofstream &arch, const struct Cliente &cli){
    arch<<left<<setw(10)<<cli.dni<<cli.nombre<<endl;
    arch<<"Libros Entregados:"<<endl;
    arch<<setw(6)<<" "<<setw(18)<<"Pedido No."<<setw(12)<<"Codigo"<<"Precio"<<endl;
    for(int i=0;i<cli.cantDeLibros;i++){
        if(cli.librosSolicitados[i].atendido == true){
            arch<<setw(8)<<" "<<setw(18)<<cli.librosSolicitados[i].numeroDePedido<<setw(12)
                    <<cli.librosSolicitados[i].codigoDelLibro<<cli.librosSolicitados[i].precio<<endl;
        }
    }
    arch<<"Total a pagar:"<<cli.pagoTotal<<endl;
    arch<<"Libros NO Entregados por falta de stock:"<<endl;
    arch<<setw(6)<<" "<<setw(18)<<"Pedido No."<<setw(12)<<"Codigo"<<endl;
    for(int i=0;i<cli.cantDeLibros;i++){
        if(cli.librosSolicitados[i].atendido == false){
            arch<<setw(8)<<" "<<setw(18)<<cli.librosSolicitados[i].numeroDePedido<<setw(12)
                    <<cli.librosSolicitados[i].codigoDelLibro<<endl;
        }
    }
    arch<<endl<<endl;
}