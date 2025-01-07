/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ColaDoblementeEnlazada.cpp
 * Author: Rosse
 * 
 * Created on 24 de octubre de 2024, 15:07
 */

#include "ColaDoblementeEnlazada.h"

enum Ranking {
    CAB, COLA, TOTAL
};

enum Nodo {
    DATO, DIREC
};

enum Direccion {
    SIG, ANT
};

enum registro {CODI,TITULO,AUTOR,RANKING,ARR};

void GenerarCola(void *&cola) {
    void **Estructura = new void * [3];
    int *num = new int;
    *num = 0;
    Estructura[CAB] = nullptr;
    Estructura[COLA] = nullptr;
    Estructura[TOTAL] = num;
    cola = Estructura;
}

void Encolar(void *&Cola, void *Registro) {
    void **DTCola = (void **) Cola;
    void **DTRegistro = (void **) Registro;
    int rk = *(int*) DTRegistro[RANKING];
    if (EsColaVacia(DTCola[CAB]) or *(int*) DTRegistro[RANKING] == 3) {
        InsertarInicio(Cola, Registro);
    } else {
        InsertarEnPosicion(Cola, Registro);
    }
    int *TotalLib = (int *) DTCola[TOTAL];
    *TotalLib = *TotalLib + 1;
    DTCola[TOTAL] = TotalLib;
}

void * Desencolar(void *&Cola) {
    void **DTCola = (void **) Cola;
    void **Eliminar = (void**) DTCola[COLA];
    void **DatosEliminar = (void **) Eliminar[DATO];
    void **Anterior = (void **) DatosEliminar[ANT];
    DTCola[COLA] = Anterior;
    return Eliminar;
}

bool EsColaVacia(void *Cola) {
    if (Cola == nullptr) return true;
    return false;
}

void InicializarNodo(void *&Nodo, void *Registro) {
    void **ArrNodo = new void *[2];
    void **Direcciones = new void*[2];
    Direcciones[SIG] = nullptr;
    Direcciones[ANT] = nullptr;
    ArrNodo[DATO] = Registro;
    ArrNodo[DIREC] = Direcciones;
    Nodo = ArrNodo;
}

void InsertarInicio(void *&Cola, void *Registro) {
    void **DTCola = (void **) Cola;
    void *PtrNodo;
    InicializarNodo(PtrNodo, Registro);
    void ** Nodo = (void **) PtrNodo;
    if (*(int*) DTCola[TOTAL] == 0) {
        DTCola[CAB] = Nodo;
        DTCola[COLA] = Nodo;
    } else {
        void **Actual = (void **) DTCola[CAB];
        void **DirecNodo = (void **) Nodo[DIREC];
        void **DirecNodoAct = (void **) Actual[DIREC];
        DirecNodo[SIG] = Actual;
        DirecNodoAct[ANT] = Nodo;
        DTCola[CAB] = Nodo;
    }
}

void InsertarEnPosicion(void *&Cola, void *Registro) {
    void **DTCola = (void **) Cola;
    void *PtrNodo;
    InicializarNodo(PtrNodo, Registro); // Inicializar el nodo nuevo
    void ** Nodo = (void **) PtrNodo;
    void **DTRegistro = (void **) Registro;

    // Caso 1: Si es un ranking de nivel 1, va al final de la cola
    if (*(int*) DTRegistro[RANKING] == 0) {
        void **Ultimo = (void **) DTCola[COLA];
        void **DirUltimo = (void **) Ultimo[DIREC];
        void **DirecNodo = (void **) Nodo[DIREC];

        DirUltimo[SIG] = Nodo; // Conectar el último nodo al nuevo
        DirecNodo[ANT] = Ultimo; // Conectar el nuevo nodo al último

        DTCola[COLA] = Nodo; // Actualizar la cola
    }
        // Caso 2: Insertar en el medio según el criterio del ranking
    else {
        void ** Recorrer = (void **) DTCola[CAB];
        void **DT = (void **) Recorrer[DATO];
        void **Direccion = (void **) Recorrer[DIREC];

        // Recorrer la lista hasta encontrar la posición adecuada
        while (Direccion[SIG] != nullptr) {
            if (*(int*) DT[RANKING] == 1 or *(int*) DT[RANKING] == 0) break; // Encontrar la posición del primer elemento con ranking 1
            Recorrer = (void **) Direccion[SIG];
            DT = (void **) Recorrer[DATO];
            Direccion = (void **) Recorrer[DIREC];
        }

        // Si encontramos un nodo con ranking 1 o llegamos al final, insertar antes del nodo encontrado
        void **NodoAnterior = (void **) Direccion[ANT];
        void **DirecNodo = (void **) Nodo[DIREC];

        // Caso especial: si estamos al principio (anterior es nullptr)
        if (NodoAnterior == nullptr) {
            DTCola[CAB] = Nodo; // El nuevo nodo se convierte en el primero
        } else {
            // Conectar el nuevo nodo con el anterior
            void **DirecNodoAnt = (void **) NodoAnterior[DIREC];
            DirecNodo[ANT] = NodoAnterior;
            DirecNodoAnt[SIG] = Nodo;
        }

        // Conectar el nuevo nodo con el siguiente
        DirecNodo[SIG] = Recorrer;
        Direccion[ANT] = Nodo;

        // Si estamos al final de la cola, actualizamos el puntero COLA
        if (Direccion[SIG] == nullptr) {
            DTCola[COLA] = Nodo;
        }
    }
}