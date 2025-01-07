/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Espacio.cpp
 * Author: Rosse
 * 
 * Created on 30 de octubre de 2024, 17:11
 */

#include "Espacio.h"

Espacio::Espacio(){
    contenido = ' ';
    posX =0;
    posY =0;
}
Espacio::~Espacio(){
    
}

void Espacio::SetPosY(int posY) {
    this->posY = posY;
}

int Espacio::GetPosY() const {
    return posY;
}

void Espacio::SetPosX(int posX) {
    this->posX = posX;
}

int Espacio::GetPosX() const {
    return posX;
}

void Espacio::SetContenido(char contenido) {
    this->contenido = contenido;
}

char Espacio::GetContenido() const {
    return contenido;
}