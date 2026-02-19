/*
Implementar una función que retorna un puntero a un struct del tipo t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica, respetando la siguiente declaración. 
En caso de no poder reservar la memoria, retornar NULL
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} t_alumno;

t_alumno* crear_alumno(){
    t_alumno *puntero = NULL;

    puntero = (t_alumno*) malloc(sizeof(t_alumno));

    if (puntero != NULL){
        return puntero;
    }
    else{
        return NULL;
    }
}

void main(){
    t_alumno *puntero = crear_alumno();

    if (puntero != NULL){
        printf("Memoria Reservada Exitosamente");
        free(puntero);
    }
    else{
        printf("Fallo para reservar memoria al puntero");
    }
}