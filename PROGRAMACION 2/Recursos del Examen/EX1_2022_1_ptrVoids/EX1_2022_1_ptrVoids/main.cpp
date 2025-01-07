
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "PuntosGenericos.h"

int main(int argc, char** argv) {
    
    void *productos, *pedidos, *clientes;
    
    cargaproductos(productos);
    cargapedidos(pedidos);
    procesarclientes(productos, pedidos, clientes);
    imprimirreporte(clientes);
    
    return 0;
}

