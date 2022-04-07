#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Producto{
    int ProductoID, Cantidad;
    char *TipoProducto;
    float PrecioUnitario;

};
typedef struct Producto Producto;

struct Clientes{
    int ClienteID;
    char *NombreCliente;
    int CantidadDeProductos;
    Producto *Productos;
}

int main(){
    

    return 0;
}