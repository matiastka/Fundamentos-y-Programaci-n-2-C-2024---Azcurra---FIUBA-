/*
Implementar una función que retorna un puntero a un vector de n struct del tipo t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica, respetando la siguiente declaración. 
En caso de no poder reservar la memoria, retornar NULL.
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} t_alumno;

t_alumno* crear_alumnos(int n){
    t_alumno *puntero = NULL;

    puntero = (t_alumno*) malloc(n * sizeof(t_alumno));

    if (puntero != NULL){
        return puntero;
    }
    else{
        return NULL;
    }
}

void main(){
    int n;

    printf("Ingrese la cantidad de alumnos que quiere ingresar: ");
    scanf("%i", &n);

    t_alumno *puntero = crear_alumnos(n);

    if (puntero != NULL){
        printf("Espacio de memoria reservada exitosamente");
        free(puntero);
    }
    else{
        printf("Fallo al intentar reservarse espacio de memoria");
    }
}
