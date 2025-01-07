/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Comunes.cpp
 * Author: Rosse
 * 
 * Created on 21 de noviembre de 2024, 11:04
 */

#include "Comunes.h"

void ImprimeFecha(int fecha, ofstream &arch){
    int aa,mm,dd;
    aa = fecha /10000;
    fecha = fecha%10000;
    mm = fecha /100;
    dd=fecha%100;
    arch<<aa<<"/"<<mm<<"/"<<dd;
}