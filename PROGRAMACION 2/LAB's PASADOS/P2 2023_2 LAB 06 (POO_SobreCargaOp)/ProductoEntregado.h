/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ProductoEntregado.h
 * Author: Rosse
 *
 * Created on 28 de octubre de 2024, 19:12
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H
class ProductoEntregado{
private:
    char* codigo;
    double precio;
public:
    ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char* cod) const;
};
#endif /* PRODUCTOENTREGADO_H */
