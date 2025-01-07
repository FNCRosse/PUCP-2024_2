#ifndef MEMORIAPORINCREMENTOS_HPP
#define MEMORIAPORINCREMENTOS_HPP

void cargar_estructuras(char ***&repartidores, int ***&clientes, double ***&subtotales, char ***cadenas, int **enteros, double **reales);

void reporte_de_repartidores(const char*nombre_archivo, char ***repartidores, int ***clientes, double ***subtotales);

void reporte_por_repartidor(char ***repartidores, int ***clientes, double ***subtotales);

void inicializarEstructuras(char ***&repartidores, int ***&clientes, double ***&subtotales, int &capacidad,
        int *&capDatosCli,int *&capDatosSub);
void IncrementarCapacidadEstructura(char ***&repartidores, int ***&clientes, double ***&subtotales, int &capacidad,
        int *&capDatosCli,int *&capDatosSub);
int BuscarRepartidor(char ***&repartidores,char * codigo);
void incluirRepartidor(char ***&repartidores,int posicion,char *codigo);
void incluirCliente(int ***&clientes,int posicion,int dni, int &cap);
void incluirSubTotales(double ***&subtotales,int posicion,double subtotal, int &cap);
void InicializarDatoCliente(int &cap,int **&Buff_Cliente);
void IncrementarEspacioDatoCliente(int &cap,int **&Buff_Cliente);
void InicializarDatoSubtotales(int &capacidad,double **&Dato_Subtotales);
void IncrementarEspacioDatoSubtotales(int &cap,double **&Dato_Subtotales);

#endif /* MEMORIAPORINCREMENTOS_HPP */

