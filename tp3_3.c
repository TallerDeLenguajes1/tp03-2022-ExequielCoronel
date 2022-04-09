#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct Producto{
    int ProductoID, Cantidad;
    char *TipoProducto;
    float PrecioUnitario;

};
typedef struct Producto Producto;

struct Cliente{
    int ClienteID;
    char *NombreCliente;
    int CantidadDeProductos;
    Producto *Productos;
};
typedef struct Cliente Cliente;

float precioProducto(Producto P);
int main(){
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int random,cantidad;
    srand(time(NULL));
    Cliente *Clientes;
    float *totales, TotalPorCliente=0, precioPorProducto;
    printf("Cargar la cantidad de clientes: ");
    scanf("%d",&cantidad);
    fflush(stdin);
    Clientes = (Cliente *)malloc(cantidad * sizeof(Cliente));
    totales = (float *)malloc(cantidad * sizeof(float));

    
    //Cargado de Clientes 
    for(int i=0;i<cantidad;i++){
        TotalPorCliente=0;
        Clientes[i].NombreCliente = (char *)malloc(30);
        Clientes[i].ClienteID = i+1;
        printf("Ingrese el nombre del cliente %d: ",i+1);
        gets(Clientes[i].NombreCliente);
        Clientes[i].CantidadDeProductos = rand () % 5 + 1;
        Clientes[i].Productos=(Producto *)malloc(Clientes[i].CantidadDeProductos * sizeof(Producto));
        for(int j=0;j<Clientes[i].CantidadDeProductos;j++){
            precioPorProducto=0;
            Clientes[i].Productos[j].TipoProducto=(char *)malloc(15);
            random = rand () % 5;
            Clientes[i].Productos[j].ProductoID=j+1;
            Clientes[i].Productos[j].PrecioUnitario=rand () % 91 + 10;
            Clientes[i].Productos[j].Cantidad=rand () % 10 + 1;
            strcpy(Clientes[i].Productos[j].TipoProducto,TiposProductos[random]);
            precioPorProducto=precioProducto(Clientes[i].Productos[j]);
            TotalPorCliente=TotalPorCliente+precioPorProducto;
        }
        totales[i]=TotalPorCliente;
    }

    //Mostrar datos
    for(int i=0;i<cantidad;i++){
        printf("\nID cliente: %d\n Nombre: ", Clientes[i].ClienteID);
        puts(Clientes[i].NombreCliente);
        printf("\nCantidad de Productos: %d\n",Clientes[i].CantidadDeProductos);
        printf("\nProductos solicitados: \n");
        for(int j=0;j<Clientes[i].CantidadDeProductos;j++){
            printf("\t");
            puts(Clientes[i].Productos[j].TipoProducto);
            printf("Precio Unitario: %.2f\nCantidad: %d\nSubtotal: %.2f\n", Clientes[i].Productos[j].PrecioUnitario, Clientes[i].Productos[j].Cantidad, precioProducto(Clientes[i].Productos[j]));
        }
        printf("Total a Pagar: %.2f\n\n\n",totales[i]);
    }

    //Libero Memoria 
    for(int i=0;i<cantidad;i++){
        for(int j=0;j<Clientes[i].CantidadDeProductos;j++){
            free(Clientes[i].Productos[j].TipoProducto);
        }
        free(Clientes[i].Productos);
        free(Clientes[i].NombreCliente);
    }
    free(Clientes);
    return 0;
}

float precioProducto(Producto produ){
    return((produ.PrecioUnitario)*(produ.Cantidad));
}