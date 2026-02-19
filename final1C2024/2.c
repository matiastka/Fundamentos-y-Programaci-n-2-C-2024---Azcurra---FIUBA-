/*
Escribir una funcion llamada "crear_estructura_dinamica" que recibe un arreglo unidimensional de elementos enteros ya cargado y su respectivo maximo logico. 
La funcion debe devolver un puntero a la estructura dinamica que contenga los elementos del arreglo recibido y utilice solo el espacio de memeoria necesario.
Escribir un main que:
a) invoque a la funcion utilizando como arreglo la siguiente declaracion:
int vector[100] = {48, 23, 2, 5, 18};

b) Haga una llamada a la funcion mostrar_estrucutra_dinamica a la que se le debe pasar la estrucutra y la correspondiente cantidad de elementos a mostrar. 
No tene que desarrollar esta funcion, solo utilizarla adecuadamente. Solo se puede invocrar esta funcion si el puntero no es nulo.
*/

# include <stdio.h>
# include <stdlib.h>

int* crear_estructura_dinamica(int vector[], int ML){
    int *puntero = NULL;
    int i;

    puntero = malloc(ML * sizeof(int));

    if (puntero != NULL){
        for (i = 0; i < ML; i++){
            puntero[i] = vector[i];
        }
        return puntero;
    }
    else{
        return NULL;
    }
}

void main(){
    int vector[100] = {48,23,2,5,18};
    int cant_elementos;
    cant_elementos = 5;
    int *puntero = crear_estructura_dinamica(vector, cant_elementos);

    if (puntero != NULL){
        mostrar_estrucutra_dinamica(puntero, cant_elementos);
        free(puntero);
    }
    else{
        printf("No se pudo reservar espacio de memeoria");
    }
}