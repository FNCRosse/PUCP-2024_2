/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Enciclopedia.h
 * Author: Rosse
 *
 * Created on 20 de noviembre de 2024, 15:45
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H
#include "Libro.h"

class Enciclopedia : public Libro {
private:
    int sku;
    int anho;
    int vegencia;
public:
    Enciclopedia();
    ~Enciclopedia();
    Enciclopedia(const Enciclopedia &);
    void SetVegencia(int vegencia);
    int GetVegencia() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    
    void lee(ifstream  &arch);
    void imprime(ofstream &arch);
    void actualiza();
};
#endif /* ENCICLOPEDIA_H */
