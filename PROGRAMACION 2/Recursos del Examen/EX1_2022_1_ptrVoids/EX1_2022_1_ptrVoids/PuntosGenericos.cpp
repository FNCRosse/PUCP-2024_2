#include <cstring>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

#include "PuntosGenericos.h"


void cargaproductos(void *&productos){
    ifstream arch("Productos2.csv", ios::in);
     if(!arch){
         cout<<"No se puede leer el archivo productos";
         exit(1);
     }
    int numData=0, capacidad=0;
    productos=nullptr;
    while(1){
        if(numData==capacidad)
            asignarEspacio(productos, numData, capacidad);
        void **lprod=(void**)productos;
        lprod[numData-1]=leerProd(arch);
        if(arch.eof())break;
        lprod[numData]=nullptr;
        productos=lprod;
        numData++;
    }
    imprimeproductos(productos);
}

void imprimeproductos(void *productos){
    ofstream arch("reporteProductos.txt", ios::out);
    if(!arch){
        cout<<"No se puede leer el archivo productos";
        exit(1);
    }
    void **lprod=(void**)productos;
    int *codigo, *cant;
    char *desc;
    double *precio;
    for(int i=0; lprod[i]!=nullptr; i++){
        void **reg=(void**)lprod[i];
        codigo=(int*)reg[0];
        desc=(char*)reg[1];
        precio=(double*)reg[2];
        cant=(int*)reg[3];
        arch<<setw(10)<<*codigo<<setw(100)<<desc<<setw(10)<<*precio<<setw(10)<<*cant<<endl;
    }
}

void *leerProd(ifstream &arch){
    void **reg;
    int *codigo, *cant;
    char *desc, c;
    double *precio;
    codigo=new int;
    cant= new int;
    precio=new double;
    reg=new void*[4];
    arch>>*codigo;
    if(arch.eof())return nullptr;
    arch>>c;
    desc=leerCad(arch, 200, ',');
    arch>>*precio>>c>>*cant;
    reg[0]=codigo;
    reg[1]=desc;
    reg[2]=precio;
    reg[3]=cant;
    return reg;
}

char *leerCad(ifstream &arch, int max, char del){
    char cad[max], *ptr;
    arch.getline(cad, max, del);
    if(arch.eof()) return nullptr;
    ptr=new char[strlen(cad)+1];
    strcpy(ptr, cad);
    return ptr;
}

void asignarEspacio(void *&arr, int &numData, int &capacidad){
    void **reg=(void**)arr, **aux;
    capacidad+=5;
    if(arr==nullptr){
        reg=new void *[capacidad];
        reg[0]=nullptr;
        arr=reg;
        numData=1;
    }else{
        aux=new void *[capacidad];
        for(int i=0; i<capacidad; i++)
            aux[i]=reg[i];
        delete reg;
        arr=aux;
    }
    
}

//422763,GALLETAS SUAVICREMAS FRESA 158GR,2,17913944,23/09/2019
//675770,JARABE DE MAMEY 1.25KG,5,17913944,20/10/2019
//696000,MEDIA CREMA NESTLE 1LT,1,17913944,28/12/2019

void cargapedidos(void *&pedidos){
     ifstream arch("pedidos2.csv", ios::in);
     if(!arch){
         cout<<"No se puede leer el archivo pedidos";
         exit(1);
     }
     void *buffer[200], **lpedidos;
     int i=0;
     while(1){
         buffer[i]=leerPed(arch);
         if(arch.eof())break;
         i++;
     }
     lpedidos=new void *[i+1];
     lpedidos[i]=nullptr;
     for(int j=0; j<i; j++)
         lpedidos[j]=buffer[j];
     pedidos=lpedidos;
     imprimepedidos(pedidos);
}

void imprimepedidos(void *pedidos){
    ofstream arch("reportePedidos.txt", ios::out);
    if(!arch){
        cout<<"No se puede leer el archivo productos";
        exit(1);
    }
    void **lped=(void**)pedidos;
    int *codigo, *cant, *dni, *fecha;
    char *desc, *est;
    //double *precio;
    for(int i=0; lped[i]!=nullptr; i++){
        void **reg=(void**)lped[i];
        codigo=(int*)reg[0];
        desc=(char*)reg[1];
        cant=(int*)reg[2];
        dni=(int*)reg[3];
        fecha=(int*)reg[4];
        est=(char*)reg[5];
        arch<<setw(10)<<*codigo<<setw(80)<<desc<<setw(5)<<*cant<<setw(10)<<*dni<<setw(10)<<*fecha<<setw(5)<<*est<<endl;
    }
}

void *leerPed(ifstream &arch){
    int *codigo, *cant, *dni, *fecha, dd, mm, aa;
    char c, *est, *desc;
    void **seis;
    codigo=new int;
    fecha=new int;
    dni=new int;
    cant=new int;
    est=new char;
    seis=new void *[6];
    arch>>*codigo; 
    if(arch.eof())nullptr;
    arch>>c;
    desc=leerCad(arch, 200, ',');
    arch>>*cant>>c>>*dni>>c>>dd>>c>>mm>>c>>aa;
    *fecha=aa*10000+mm*100+dd;
    *est='N';
    seis[0]=codigo;
    seis[1]=desc;
    seis[2]=cant;
    seis[3]=dni;
    seis[4]=fecha;
    seis[5]=est;
    return seis;
}

//71984468,IPARRAGUIRRE VILLEGAS NICOLAS EDILBERTO
//29847168,ALDAVE ZEVALLOS ROSARIO
//79475585,RETTO ARCA ANNIE MAGDA

void procesarclientes(void *&productos, void *&pedidos, void *&clientes){
    ifstream arch("clientes2.csv", ios::in);
     if(!arch){
         cout<<"No se puede leer el archivo pedidos";
         exit(1);
     }
    actualizarEstado(pedidos, productos);
    imprimepedidos(pedidos);
    imprimeproductos(productos);//Ver si se actualizo todo bien
    cargarClientes(clientes, arch);
    agregarPedidoACliente(clientes, pedidos);
    imprimerepfinal(clientes);
}

void imprimerepfinal(void *&clientes){
    ofstream arch("reporteClientes.txt", ios::out);
    if(!arch){
        cout<<"No se puede leer el archivo clientes";
        exit(1);
    }
    void **lclientes=(void**)clientes;
    int *dni, *fecha, *codigo, *cant;
    char *nombre, *desc;
    for(int i=0; lclientes[i]!=nullptr; i++){
        void**regCli=(void**)lclientes[i];
        dni=(int *)regCli[0];
        nombre=(char *)regCli[1];
        void**regPed=(void**)regCli[2];
        arch<<setw(10)<<*dni<<setw(80)<<nombre<<endl;
        if(regCli[2]!=nullptr){
            for(int j=0; regPed[j]!=nullptr; j++){
                void **ped=(void**)regPed[j];
                codigo=(int *)ped[1];
                fecha=(int *)ped[0];
                desc=(char *)ped[2];
                cant=(int *)ped[3];
                arch<<setw(15)<<*fecha<<setw(10)<<*codigo<<setw(60)<<desc<<setw(5)<<*cant<<endl;
            }
        }else{
            arch<<setw(20)<<" "<<"ESTE CLIENTE NO TIENE NiNGUN PEDIDO"<<endl;
        }
    }
}

void imprimirreporte(void *&clientes){
    ofstream arch("ReporteDePedidos.txt", ios::out);
    if(!arch){
        cout<<"No se puede leer el archivo clientes";
        exit(1);
    }
    void **lclientes=(void**)clientes;
    int *dni, *fecha, *codigo, *cant, aa, dd, mm;
    char *nombre, *desc;
    arch<<setw(100)<<setfill('=')<<" "<<setfill(' ')<<endl;
    arch<<"PEDIDOS ATENDIDOS POR CLIENTE"<<endl;
    for(int i=0; lclientes[i]!=nullptr; i++){
        void**regCli=(void**)lclientes[i];
        dni=(int *)regCli[0];
        nombre=(char *)regCli[1];
        void**regPed=(void**)regCli[2];
        arch<<setw(100)<<setfill('=')<<" "<<setfill(' ')<<endl;
        arch<<"DNI"<<setw(15)<<" "<<left<<"NOMBRE"<<right<<endl;
        arch<<setw(8)<<*dni<<setw(10)<<" "<<setw(80)<<left<<nombre<<right<<endl;
        arch<<setw(100)<<setfill('-')<<" "<<setfill(' ')<<endl;
        arch<<"Pedidos atendidos: "<<endl;
        arch<<setw(100)<<setfill('-')<<" "<<setfill(' ')<<endl;
        arch<<"Fecha"<<setw(9)<<" "<<"Codigo"<<setw(5)<<" "<<setw(60)<<left<<"Descripcion del Producto"<<right<<setw(10)<<"Cantidad"<<endl;
        arch<<setw(100)<<setfill('-')<<" "<<setfill(' ')<<endl;
        if(regCli[2]!=nullptr){
            for(int j=0; regPed[j]!=nullptr; j++){
                void **ped=(void**)regPed[j];
                codigo=(int *)ped[1];
                fecha=(int *)ped[0];
                desc=(char *)ped[2];
                cant=(int *)ped[3];
                convertirFecha(*fecha, dd, mm, aa);
                arch<<setw(2)<<setfill('0')<<dd<<'/'<<setw(2)<<mm<<"/"<<setw(4)<<aa<<setfill(' ')<<setw(10)<<*codigo<<setw(5)<<" "<<setw(60)<<left<<desc<<right<<setw(6)<<*cant<<endl;
            }
        }else{
            arch<<endl;
            arch<<setw(20)<<" "<<"ESTE CLIENTE NO TIENE NINGUN PEDIDO"<<endl;
        }
        arch<<endl;
    }
}

void convertirFecha(int fecha, int &dd, int &mm, int &aa){
    aa=fecha/10000;
    fecha=fecha%10000;
    mm=fecha/100;
    dd=fecha%100;
}

void agregarPedidoACliente(void *&clientes, void *pedidos){
    void **lclientes=(void**)clientes;
    void **lpedidos=(void**)pedidos;
    int *dni, *dniPed, *codigo, *cantidad, *fecha, numData[50]{}, capacidad[50]{};
    char *est, *desc;
    for(int i=0; lclientes[i]!=nullptr; i++){
        void**regCli=(void**)lclientes[i];
        dni=(int *)regCli[0];
        for(int j=0; lpedidos[j]!=nullptr; j++){
            void**regPed=(void**)lpedidos[j];
            dniPed=(int *)regPed[3];
            fecha=(int *)regPed[4];
            cantidad=(int *)regPed[2];
            desc=(char *)regPed[1];
            est=(char *)regPed[5];
            codigo=(int *)regPed[0];
            if(*dni==*dniPed && *est=='A'){
                if(numData[i]==capacidad[i])
                    asignarEspacio(regCli[2], numData[i], capacidad[i]);
                void**auxCli=(void**)regCli[2];
                auxCli[numData[i]-1]=agregarPedido(fecha, desc, cantidad, codigo);
                auxCli[numData[i]]=nullptr;
                numData[i]++;
            }
        }
    }
}

void *agregarPedido(int *fecha, char *desc, int *cantidad, int *codigo){
    void **cuarteto;
    cuarteto= new void *[4];
    cuarteto[0]=fecha;
    cuarteto[1]=codigo;
    cuarteto[2]=desc;
    cuarteto[3]=cantidad;
    return cuarteto;
}

//void asignarSegIncremental(void *&pedidoCliente, int &numData, int &capacidad){
//    void **lpedCli=(void**)pedidoCliente, **aux;
//    capacidad+=5;
//    if(pedidoCliente==nullptr){
//        lpedCli=new void *[capacidad];
//        lpedCli[0]=nullptr;
//        pedidoCliente=lpedCli;
//        numData=1;
//    }else{
//        aux=new void *[capacidad];
//        for(int i=0; i<capacidad; i++)
//            aux[i]=lpedCli[i];
//        delete lpedCli;
//        pedidoCliente=aux;
//    }
//}

void actualizarEstado(void *&pedidos, void *&productos){
    void **lped=(void**)pedidos;
    void **lprod=(void**)productos;
    int *codigo, *cantPed, pos, *nuevoStock, *stock;
    char *est;
    double *precio;
    nuevoStock=new int;
    est=new char;
    for(int i=0; lped[i]!=nullptr; i++){
        void **regPed=(void**)lped[i];
        codigo=(int*)regPed[0];
        pos=buscarProd(productos, *codigo);
        if(pos!=-1){
            void **regProd=(void**)lprod[pos];
            cantPed=(int*)regPed[2];
            stock=(int*)regProd[3];
            //*nuevoStock=*stock-*cantPed;
            if(*stock>=*cantPed){
                *est='A';
                *stock-=*cantPed;
                regProd[3]=stock;
                regPed[5]=est;
            }            
        }
    }
}

int buscarProd(void *&productos, int codigo){
    void **lprod=(void**)productos;
    int *cod;
    for(int i=0; lprod[i]!=nullptr; i++){
        void **reg=(void**)lprod[i];
        cod=(int*)reg[0];
        if(*cod==codigo){
            return i;
        }
    }
    return -1;
}

void cargarClientes(void *&clientes, ifstream &arch){
    void *buffer[50], **lclientes;
    int i=0;
    while(1){
        buffer[i]=leerClientes(arch);
        if(arch.eof())break;
        i++;
    }
    lclientes=new void *[i+1];
    lclientes[i]=nullptr;
    for(int j=0; j<i; j++)
        lclientes[j]=buffer[j];
    clientes=lclientes;
}

void *leerClientes(ifstream &arch){
    void **trio;
    int *dni;
    char *desc, c;
    dni= new int;
    trio=new void*[3];
    arch>>*dni;
    if(arch.eof())return nullptr;
    arch>>c;
    desc=leerCad(arch, 200, '\n');
    trio[0]=dni;
    trio[1]=desc;
    trio[2]=nullptr;
    return trio;
}
