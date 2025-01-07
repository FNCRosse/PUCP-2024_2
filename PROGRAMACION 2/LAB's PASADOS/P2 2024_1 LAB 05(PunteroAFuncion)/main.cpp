/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 22 de octubre de 2024, 08:18
 */

#include <iostream>
using namespace std;
#include "BibliotecaGenerica.h"
#include "FuncionesEnteras.h"
#include "FuncionesRegistro.h"

int main(int argc, char** argv) {
    void *pedido1,*pedido2,*pedidoFinal;
    
    crearLista(pedido1,leenum,"RegistroNum1.txt");
    imprimeLista(pedido1,imprimenum,"Repnum1.txt");
    
    crearLista(pedido2,leenum,"RegistroNum2.txt");
    imprimeLista(pedido2,imprimenum,"Repnum2.txt");
    
    CombinaLista(pedido1,pedido2,pedidoFinal,cmpnum);
    imprimeLista(pedidoFinal,imprimenum,"RepnumFinal.txt");
    
    crearLista(pedido1,leerRegistro,"Pedidos31.csv");
    imprimeLista(pedido1,imprimeRegistro,"Repreg1.txt");
    
    crearLista(pedido2,leerRegistro,"Pedidos32.csv");
    imprimeLista(pedido2,imprimeRegistro,"Repreg2.txt");
    
    CombinaLista(pedido1,pedido2,pedidoFinal,cmpRegistro);
    imprimeLista(pedidoFinal,imprimeRegistro,"RepregFinal.txt");
    
    return 0;
}

