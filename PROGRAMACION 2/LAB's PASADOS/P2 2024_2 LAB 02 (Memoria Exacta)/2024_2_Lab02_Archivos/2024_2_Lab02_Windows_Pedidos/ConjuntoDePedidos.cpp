/* 
 * Archivo: ConjuntoDePedidos.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 09:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ConjuntoDePedidos.hpp"
#include "Pedido.hpp"
#include "Comunes.hpp"
#include "ConjuntoDePlatos.hpp"
#include "AperturaDeArchivos.h"

using namespace std;
#define IGV 0.18

void cargar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, const char *nombre_de_archivo) {
    ifstream archivo_de_pedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_pedidos, nombre_de_archivo);
    archivo_de_pedidos >> conjuntoDePedidos;
    archivo_de_pedidos.close();
}

void operator>>(istream &archivo_de_pedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    struct ConjuntoDePedidos Buffer;
    inicializar_buffer_de_conjunto_de_pedidos(Buffer, 200);
    struct Pedido ped;
    while (archivo_de_pedidos >> ped) {
        Buffer << ped;
    }
    Buffer>>conjuntoDePedidos;
}

void inicializar_buffer_de_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, int cantidad) {
    conjuntoDePedidos.enteros = new int*[cantidad];
    conjuntoDePedidos.cadenas = new char**[cantidad];
    conjuntoDePedidos.reales = nullptr;
    for (int i = 0; i < cantidad; i++) {
        conjuntoDePedidos.enteros[i] = nullptr;
        conjuntoDePedidos.cadenas[i] = nullptr;
    }
}

void operator<<(ConjuntoDePedidos &buffer_de_conjuntoDePedidos, const Pedido &pedido) {
    int posCliente = buscar_cliente(buffer_de_conjuntoDePedidos, pedido.dni_cliente);
    if (posCliente == -1) {//Es cliente nuevo
        int cant = obtener_cantidad_cliente(buffer_de_conjuntoDePedidos);
        int *DatosCliente = new int [3] {
        };
        DatosCliente[0] = pedido.dni_cliente;
        DatosCliente[1] = 1;
        DatosCliente[2] = pedido.cantidad_platos;
        buffer_de_conjuntoDePedidos.enteros[cant] = DatosCliente;
        char ** DatosCadenas = new char *[2] {
        };
        DatosCadenas[0] = mi_strdup(pedido.codigo_repartidor);
        DatosCadenas[1] = mi_strdup(pedido.codigo_plato);
        buffer_de_conjuntoDePedidos.cadenas[cant] = DatosCadenas;
    } else {
        int *DatosCliente = buffer_de_conjuntoDePedidos.enteros[posCliente];
        int CantNuevosCliente = 2 + DatosCliente[1];
        int *DatosNuevosCliente = new int [CantNuevosCliente + 1];
        for (int i = 0; i < CantNuevosCliente; i++) {
            DatosNuevosCliente[i] = DatosCliente[i];
        }
        DatosNuevosCliente[1]++;
        DatosNuevosCliente[CantNuevosCliente] = pedido.cantidad_platos;
        buffer_de_conjuntoDePedidos.enteros[posCliente] = DatosNuevosCliente;

        char ** DatosCadenas = buffer_de_conjuntoDePedidos.cadenas[posCliente];
        int CantNuevasCadenas = DatosCliente[1] + 1;
        char **DatosNuevosCadenas = new char*[CantNuevasCadenas + 1] {
        };
        for (int i = 0; i < CantNuevasCadenas; i++) {
            DatosNuevosCadenas[i] = DatosCadenas[i];
        }
        DatosNuevosCadenas[CantNuevasCadenas] = mi_strdup(pedido.codigo_plato);
        buffer_de_conjuntoDePedidos.cadenas[posCliente] = DatosNuevosCadenas;
    }
}

void operator>>(const ConjuntoDePedidos &buffer_de_conjuntoDePedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    int cant = obtener_cantidad_cliente(buffer_de_conjuntoDePedidos);
    inicializar_buffer_de_conjunto_de_pedidos(conjuntoDePedidos, cant + 1);
    for (int i = 0; i < cant; i++) {
        conjuntoDePedidos.enteros[i] = buffer_de_conjuntoDePedidos.enteros[i];
        conjuntoDePedidos.cadenas[i] = buffer_de_conjuntoDePedidos.cadenas[i];
    }
}

int buscar_cliente(const ConjuntoDePedidos &conjuntoDePedidos, int dni) {
    int i = 0;
    while (conjuntoDePedidos.enteros[i] != nullptr) {
        int *bloque_de_enteros = conjuntoDePedidos.enteros[i];
        int dni_del_bloque = bloque_de_enteros[0];
        if (dni_del_bloque == dni)
            return i;
        i++;
    }
    return CLIENTE_NO_ENCONTRADO;
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos) {
    ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos, "platos.csv");
    int cant = obtener_cantidad_cliente(conjuntoDePedidos);
    conjuntoDePedidos.reales = new double *[cant] {
    };
    for (int i = 0; i < cant; i++) {
        int * DatoCliente = conjuntoDePedidos.enteros[i];
        char** DatosPlatos = conjuntoDePedidos.cadenas[i];
        int cantidad_precio = DatoCliente[1] + 1;
        double *DatosPrecio = new double [cantidad_precio + 1] {
        };
        DatosPrecio[0] = 0;
        double buff[10];
        for (int j = 0; j < cantidad_precio; j++) {
            buff[j] = DatosPrecio[j];
        }
        for (int k = 1; k < cantidad_precio; k++) {
            double precio = conjuntoDePlatos += DatosPlatos[k];
            double totalPorPlato = precio * DatoCliente[k + 1];
            DatosPrecio[0] += totalPorPlato;
            DatosPrecio[k] = precio;
        }
        for (int j = 0; j < cantidad_precio; j++) {
            buff[j] = DatosPrecio[j];
        }
        conjuntoDePedidos.reales[i] = DatosPrecio;
    }
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos, int) {
    ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos, "platos.csv");
    int cant = obtener_cantidad_cliente(conjuntoDePedidos);
    conjuntoDePedidos.reales = new double *[cant] {};
    for (int i = 0; i < cant; i++) {
        int * DatoCliente = conjuntoDePedidos.enteros[i];
        char** DatosPlatos = conjuntoDePedidos.cadenas[i];
        int cantidad_precio = DatoCliente[1] + 1;
        double *DatosPrecio = new double [cantidad_precio + 1] {};
        DatosPrecio[0] = 0;

        for (int k = 1; k < cantidad_precio; k++) {
            double precio = conjuntoDePlatos += DatosPlatos[k];
            double totalPorPlato = precio * DatoCliente[k + 1];
            DatosPrecio[0] += totalPorPlato;
            DatosPrecio[k] = totalPorPlato;
        }
        conjuntoDePedidos.reales[i] = DatosPrecio;
    }
}

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos) {

}

void operator!(ConjuntoDePedidos &conjuntoDePedidos) {
    ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos, "platos.csv");
    int cant = obtener_cantidad_cliente(conjuntoDePedidos);
    for (int i = 0; i < cant; i++) {
        int * DatoCliente = conjuntoDePedidos.enteros[i];
        char** DatosPlatos = conjuntoDePedidos.cadenas[i];
        int cantidad_platos= DatoCliente[1] + 1;

        for (int k = 1; k < cantidad_platos; k++) {
            char* nomb_Plato = conjuntoDePlatos == DatosPlatos[k];
            DatosPlatos[k] = mi_strdup(nomb_Plato);
        }
        conjuntoDePedidos.cadenas[i] = DatosPlatos;
    }
}

void operator*(const ConjuntoDePedidos &conjuntoDePedidos) {
    int cant = obtener_cantidad_cliente(conjuntoDePedidos);
    for (int i = 0; i < cant; i++) {
        ofstream arch;
        char nomb_archivo[100];
        int *DatosEnteros = conjuntoDePedidos.enteros[i];
        char **DatosCadena = conjuntoDePedidos.cadenas[i];
        double *DatosReales = conjuntoDePedidos.reales[i];
        obtener_nombre_archivo(nomb_archivo,DatosEnteros[0]);
        AperturaDeUnArchivoDeTextosParaEscribir(arch,nomb_archivo);
        arch<<setprecision(2)<<fixed;
        imprimir_linea(arch,'=');
        arch<<right<<setw(18)<<"D.N.I. CLIENTE: "<<DatosEnteros[0]<<endl;
        arch<<right<<setw(18)<<"CODIGO REPARTIDOR: "<<DatosCadena[0]<<endl;
        imprimir_linea(arch,'=');
        arch<<left<<setw(27)<<"ITEM PLATO"<<setw(5)<<"CANT"<<"SUBTOTAL"<<endl;
        imprimir_linea(arch,'-');
        for (int k = 1; k < DatosEnteros[1] + 1; k++) {
            arch<<right<<"  "<<setw(2)<<setfill('0')<<k<<left<<" "<<setw(24)<<setfill('.')<<DatosCadena[k]<<setw(3)
                    <<setfill(' ')<<DatosEnteros[k+1]<<right<<setw(6)<<DatosEnteros[k+1]*DatosReales[k]<<endl;
        }
        imprimir_linea(arch,'-');
        arch<<right<<setw(31)<<"SUBTOTAL:"<<setw(7)<<DatosReales[0]<<endl;
        arch<<right<<setw(31)<<"I.G.V:"<<setw(7)<<DatosReales[0]*IGV<<endl;
        arch<<right<<setw(31)<<"TOTAL:"<<setw(7)<<DatosReales[0]+DatosReales[0]*IGV<<endl;
        imprimir_linea(arch,'=');
        arch.close();
    }
}

void obtener_nombre_archivo(char *nombre_archivo, int dni_numero) {
    char dni_cadena[9];
    mi_itoa(dni_numero, dni_cadena);
    strcpy(nombre_archivo, "comprobante/");
    strcat(nombre_archivo, dni_cadena);
    strcat(nombre_archivo, ".txt");
}

void imprimir_linea(ofstream &archDeReporte, char c) {
    for (int i = 0; i < MAXIMO_POR_LINEA; i++)
        archDeReporte << c;
    archDeReporte << endl;
}

int obtener_cantidad_cliente(const ConjuntoDePedidos &conjuntoDePedidos) {
    int i = 0;
    while (conjuntoDePedidos.enteros[i] != nullptr)
        i++;
    return i;
}