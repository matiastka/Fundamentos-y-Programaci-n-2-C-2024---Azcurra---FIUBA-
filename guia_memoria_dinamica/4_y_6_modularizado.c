/*
Escribir un programa el cual reserve memoria dinámica para almacenar un struct del tipo t_alumno. 
Luego solicitar al usuario que ingrese los datos del alumno y almacenarlos en la memoria previamente reservada.
Mostrar luego todos los datos del alumno. Liberar la memoria reservada al finalizar el programa.
Ademas, implementar una función que retorna un puntero a un struct del tipo t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica, respetando la siguiente declaración. 
En caso de no poder reservar la memoria, retornar NULL.
Modularizar el problema.
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
 
    puntero = (t_alumno*) malloc(sizeof(t_alumno)); // casteamos el malloc a t_alumno y obtenemos su # bytes para mandarle una direccion de mememoria a puntero

    if (puntero != NULL){
        return puntero;
    }
    else{
        return NULL;
    }
}

void cargar_alumno(t_alumno *puntero){
    printf("Ingrese el padron del alumno: ");
    scanf("%i", &(*puntero).padron);
    fflush(stdin); // No olvidarse de fflush(stdin)

    printf("Ingrese el nombre del alumno: ");
    scanf("%s", (*puntero).nombre);
    fflush(stdin);

    printf("Ingrese el apellido del alumno: ");
    scanf("%s", (*puntero).apellido);
    fflush(stdin);
}

void mostrar_alumno(t_alumno *puntero){ // Para los punteros de un solo struct, hay que acceder a ellos como si fueran un  (haciendo *puntero.campo)
    printf("El padron del alumno es: %i\nEl nombre del alumno es: %s\nEl apellido del alumno es: %s\n", (*puntero).padron, (*puntero).nombre, (*puntero).apellido);
}

void main(){
    t_alumno *puntero = crear_alumno();

    if (puntero != NULL){
        cargar_alumno(puntero);

        mostrar_alumno(puntero);

        free(puntero);
    }   
    else{
        printf("Fallo al intentar reservar espacio de memoria");
    }
}