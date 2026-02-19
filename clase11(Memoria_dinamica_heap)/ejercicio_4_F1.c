/*
Escribir un programa el cual reserve memoria dinámica para almacenar un struct del tipo t_alumno (ver anexo). Luego solicitar al usuario que ingrese los datos del alumno y almacenarlos en la memoria previamente reservada. 
Mostrar luego todos los datos del alumno. Liberar la memoria reservada al finalizar el programa.
Forma 1
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} t_alumno;

void main() {
    t_alumno *p = NULL; // p es el puntero (se puede evitar incializar con NULL si se quiere) (es una buena practica inicializarlo con NULL)

    p = (t_alumno*) malloc(sizeof(t_alumno)); // Forma para tener un puntero de struct

    if (p != NULL) {
        printf("Espacio de memoria reservado exitosamente.\n");
        // Forma 1 para guardar datos en los structs (haciendo: (*p).nombre_campo)
        printf("Indique el padron: ");
        scanf("%i", &(*p).padron);

        printf("Indique el nombre: ");
        scanf("%s", (*p).nombre);

        printf("Indique el apellido: ");
        scanf("%s", (*p).apellido);

        printf("El padron del alumno es: %i\nEl nombre es: %s\nEl apellido es: %s\n", (*p).padron, (*p).nombre, (*p).apellido);
        
        free(p);
        printf("\nMemoria liberada\n");
    }
    else
        printf("Error al reservar espacio de memoria.");
    return;
}
