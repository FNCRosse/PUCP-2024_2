/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Controles.cpp
 * Author: Rosse
 * 
 * Created on 3 de septiembre de 2024, 10:38
 */
#include <iostream>
using namespace std;
#include "Controles.h"

Controles::Controles(){
    
}

void Controles::SetBeneficio(int Beneficio) {
    this->Beneficio = Beneficio;
}

int Controles::GetBeneficio() const {
    return Beneficio;
}

void Controles::SetInversion(int inversion) {
    this->inversion = inversion;
}

int Controles::GetInversion() const {
    return inversion;
}

void Controles::SetId(int id) {
    this->id = id;
}

int Controles::GetId() const {
    return id;
}

void Controles::SetRequisitos(vector<int> Requisitos) {
    this->Requisitos = Requisitos;
}

vector<int> Controles::GetRequisitos() const {
    return Requisitos;
}