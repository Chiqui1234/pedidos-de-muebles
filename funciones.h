#include <stdio.h>
#include <stdlib.h>
#define STD_SIZE 20+1

typedef struct
{
    int id;
    char marca[STD_SIZE];
    char nombre[STD_SIZE];
    char descripcion[STD_SIZE];
    int precio;
    int cantidadDeProducto;
} ST_PRODUCTO;

typedef struct 
{
    int idProducto;
    int fechaDeCompra;
    char nombreCliente[STD_SIZE];
    int dniCliente;
    char direccionCliente[STD_SIZE];
    char emailCliente[STD_SIZE];
    char telefonoCliente[STD_SIZE];
    int cantPedido;
} ST_PEDIDO;

typedef struct nodoPedido // Cola
{
    ST_PEDIDO pedido;
    struct nodoPedido *pedido;
} ST_NODOPEDIDO;

typedef struct nodoProducto // Lista
{
    ST_PRODUCTO producto;
    struct nodoProducto *ste;
    struct nodoPedido *cola;
} ST_NODO;

/*
0) Cargar el catálogo de producto desde un .txt. Hacer un insertOrder()
1) Cliente realiza pedido y da sus datos.
2) Voy a la lista de producto.id y verifico stock
3) Si no hay stock, rechazo el pedido y agrego esa info al .txt
4) Si hay stock mando la estructura del pedido al archivo binario
5