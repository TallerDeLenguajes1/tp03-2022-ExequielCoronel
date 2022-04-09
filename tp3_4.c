#include <stdio.h>
#include <stdlib.h>

int main () {
    int cantidad;
    char **V;
    printf("Ingrese la cantidad de nombres a ingresar: ");
    scanf("%d",&cantidad);
    fflush(stdin);
    V = (char **) malloc (cantidad*sizeof(char *));
    //Carga de datos
    for(int i=0;i<cantidad;i++){
        V[i]=(char *) malloc(100);
        printf("Ingrese el nombre %d: ",i+1);
        gets(V[i]); 
    }

    //Mostrar lista de nombres 
    printf("Listado de nombres: ");
    for(int i=0;i<cantidad;i++){
        puts(V[i]);
    }

    //Libero Memoria
    for(int i=0;i<cantidad;i++){
        free(V[i]);
    }
    free(V);

    return 0;
}