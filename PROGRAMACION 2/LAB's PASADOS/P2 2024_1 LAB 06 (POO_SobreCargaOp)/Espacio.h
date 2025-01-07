/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Espacio.h
 * Author: Rosse
 *
 * Created on 30 de octubre de 2024, 17:11
 */

#ifndef ESPACIO_H
#define ESPACIO_H
class Espacio{
private:
    char contenido;
    int posX;
    int posY;
public:
    Espacio();
    virtual ~Espacio();
    void SetPosY(int posY);
    int GetPosY() const;
    void SetPosX(int posX);
    int GetPosX() const;
    void SetContenido(char contenido);
    char GetContenido() const;
    
};
#endif /* ESPACIO_H */
