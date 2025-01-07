/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunteroVoid.h
 * Author: Rosse
 *
 * Created on 2 de octubre de 2024, 21:14
 */

#ifndef PUNTEROVOID_H
#define PUNTEROVOID_H
void cargarVentas(char ***Libro,void *& ventas);
void actualizarVentas(int **ventasDniFechaPuntaje, char **VentasLibroCodigo, void *&ventas);

void * AgregarDatosLibro(char **DatosLibro);
void AgregarDatos(int puntaje,void *&Venta);
int BuscarVenta(void *Ventas,char *LibroCodigo);
#endif /* PUNTEROVOID_H */
