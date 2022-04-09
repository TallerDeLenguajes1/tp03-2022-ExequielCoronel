#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void main(){
    char *V[MAX];

    //carga nombres
    for (int i=0; i<MAX; i++){
        V[i] = (char *)malloc(100);
        printf("Ingrese el nombre %d: ",i+1);
        gets(V[i]);
    }

    //mostrar nombres
    printf("Lista de nombres: \n");
    for (int i = 0; i < MAX; i++)
    {
        puts(V[i]);
    }

    free(V);
}