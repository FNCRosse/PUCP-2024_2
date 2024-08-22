/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesAux.h
 * Author: Rosse
 *
 * Created on 22 de agosto de 2024, 08:39
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

void LeerClientes(struct Cliente *arrClientes, const char* namefile);
void LeerProductos(struct Producto *arrProduc, const char* namefile);
void AgregarPedidos(struct Cliente *arrClientes,struct Producto *arrProduc,const char* namefile);
void ImprimirReporte(const struct Cliente *arrClientes,const struct Producto *arrProduc,const char* namefile);
#endif /* FUNCIONESAUX_H */
