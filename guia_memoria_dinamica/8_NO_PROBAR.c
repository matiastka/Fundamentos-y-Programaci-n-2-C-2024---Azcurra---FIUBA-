/*
Implementar una función que retorna un puntero a un vector de n valores de tipo int, todos inicializados en cero, 
el cual apunta a un bloque de memoria dinámica, respetando la siguiente declaración. En caso de no poder reservar la memoria, retornar NULL.
*/

# include <stdio.h>
# include <stdlib.h>

int* crear_vector_inicializado(int n){
    int *puntero = NULL;

    puntero = calloc(n, sizeof(int)); // gracias aria por enseñarme calloc

    if (puntero != NULL){
        return puntero;
    }
    else{
        return NULL;
    }
}
void main(){
    int n;
    printf("Ingrese la cantidad de valores que va a tener el vector: ");
    scanf("%i", &n);

    int *puntero = crear_vector_incializado(n);

    if (puntero != NULL){
        printf("Espacio de memoria reservado exitosamente");
        free(puntero);
    }
    else{
        printf("No se pudo reservar espacio de memoria");
    }
}