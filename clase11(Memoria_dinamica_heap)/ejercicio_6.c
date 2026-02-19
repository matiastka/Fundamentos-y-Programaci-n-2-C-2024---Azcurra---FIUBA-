/*
Implementar una función que retorna un puntero a un struct del tipo
t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica,
respetando la siguiente declaración. En caso de no poder reservar la memoria,
retornar NULL.
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} t_alumno;

t_alumno* crear_alumno(){
    t_alumno *p = NULL;

    p = (t_alumno*) malloc(sizeof(t_alumno)); 

    if (p != NULL){
        return p;
    }
    else{
        return NULL;
    }
}

void cargar_alumno(t_alumno *puntero){
        printf("Indique el padron: ");
        scanf("%i", &(*puntero).padron);

        printf("Indique el nombre: ");
        scanf("%s", (*puntero).nombre);

        printf("Indique el apellido: ");
        scanf("%s", (*puntero).apellido);
}

void mostrar_alumno(t_alumno *puntero){
    printf("El padron del alumno es: %i\nEl nombre es: %s\nEl apellido es: %s\n", (*puntero).padron, (*puntero).nombre, (*puntero).apellido);
}

void main() {
    t_alumno *p = crear_alumno(); // crear_alumno se encarga de darle una direccion de memoria casteado a t_alumno al puntero.
    
    if (p != NULL){
        printf("Espacio de memoria reservado exitosamente.\n");
        cargar_alumno(p);
        
        mostrar_alumno(p);
        
        free(p); // La liberacion de memoria se hace en el main
        printf("\nMemoria liberada\n");
    }
    else{
        printf("Error al reservar la memoria\n");
    }
    return;
}
