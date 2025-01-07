/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Controles.h
 * Author: Rosse
 *
 * Created on 3 de septiembre de 2024, 10:38
 */

#ifndef CONTROLES_H
#define CONTROLES_H
#include <vector>
using namespace std; 
class Controles{
public:
    int id;
    int inversion;
    vector<int> Requisitos;
    int Beneficio;
public:
    Controles();
    void SetBeneficio(int Beneficio);
    int GetBeneficio() const;
    void SetInversion(int inversion);
    int GetInversion() const;
    void SetId(int id);
    int GetId() const;
    void SetRequisitos(vector<int> Requisitos);
    vector<int> GetRequisitos() const;
};
#endif /* CONTROLES_H */
