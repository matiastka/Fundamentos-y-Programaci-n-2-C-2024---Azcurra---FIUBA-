/*
Escribir un programa el cual reserve memoria dinámica para almacenar un struct del tipo t_alumno. 
Luego solicitar al usuario que ingrese los datos del alumno y almacenarlos en la memoria previamente reservada.
Mostrar luego todos los datos del alumno. Liberar la memoria reservada al finalizar el programa.

                                                                       (& va si es un tipo no cadena)
Para acceder a los campos de un struct pensarlo como si fuera un valor (&*nombre_puntero.nombre_campo)
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} t_alumno;

void main(){ // Queremos reservar memoria dinamica para un struct (entonces se hace tipo_struct *nombre_puntero)
    t_alumno *puntero = NULL; // 

    puntero = (t_alumno*) malloc(sizeof(t_alumno)); // Como queremos pasarle una direccion de memoria al puntero, lo casteamos a struct y usamos malloc de ese tipo de sturct

    if (puntero != NULL){ // Cargamos e imprimimos los campos del registro como si puntero fuera un struct
        printf("Se reservó espacio de memoria exitosamente\n");

        printf("Ingrese el padron del alumno: ");
        scanf("%i", &(*puntero).padron);
        fflush(stdin);

        printf("Ingrese el nombre del alumno: ");
        scanf("%s", (*puntero).nombre);
        fflush(stdin);

        printf("Ingrese el padron del alumno: ");
        scanf("%s", (*puntero).apellido);
        fflush(stdin);

        printf("El padron del alumno es: %i\nEl nombre del alumno es %s\nEl apellido es: %s\n", (*puntero).padron, (*puntero).nombre, (*puntero).apellido);

        free(puntero);
        printf("Memoria Liberada");
    }
    else{
        printf("No se pudo reservar espacio de memoria");
    }
}