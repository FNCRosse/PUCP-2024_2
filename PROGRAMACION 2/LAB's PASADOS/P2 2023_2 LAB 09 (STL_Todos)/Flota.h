/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Flota.h
 * Author: Rosse
 *
 * Created on 28 de noviembre de 2024, 15:15
 */

#ifndef FLOTA_H
#define FLOTA_H
#include "NVehiculo.h"
#include <vector>
#include <algorithm>
using namespace std;
class Flota{
private:
    vector<class NVehiculo> vflota;
public:
    Flota();
    void CargaFlota();
    void CargaPedido();
    void MuestraCarga();
    static bool compara(class NVehiculo &a,class NVehiculo &b);
    int BuscarCliente(int dniCliente);
};
#endif /* FLOTA_H */
