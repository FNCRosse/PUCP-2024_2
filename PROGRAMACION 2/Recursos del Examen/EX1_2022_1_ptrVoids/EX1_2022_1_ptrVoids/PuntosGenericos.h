#ifndef PUNTOSGENERICOS_H
#define PUNTOSGENERICOS_H

void cargaproductos(void *&productos);
void asignarEspacio(void *&lprod, int &numData, int &capacidad);
void *leerProd(ifstream &arch);
char *leerCad(ifstream &arch, int max, char del);
void *leerPed(ifstream &arch);
void cargapedidos(void *&pedidos);
void imprimeproductos(void *productos);
void imprimepedidos(void *pedidos);
void procesarclientes(void *&productos, void *&pedidos, void *&clientes);
void cargarClientes(void *&clientes, ifstream &arch);
void *leerClientes(ifstream &arch);
void actualizarEstado(void *&pedidos, void *&productos);
int buscarProd(void *&productos, int codigo);
void agregarPedidoACliente(void *&clientes, void *pedidos);
void *agregarPedido(int *fecha, char *desc, int *cantidad, int *codigo);
void asignarSegIncremental(void *&pedidoCliente, int &numData, int &capacidad);
void imprimerepfinal(void *&clientes);
void imprimirreporte(void *&clientes);
void convertirFecha(int fecha, int &dd, int &mm, int &aa);

#endif /* PUNTOSGENERICOS_H */
