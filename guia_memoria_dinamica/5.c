/*
Escribir un programa el cual reserve memoria dinámica para almacenar una cantidad n de struct del tipo t_alumno (ver anexo).
El usuario debe ingresar la cantidad n. Luego solicitar al usuario que ingrese los datos de los n alumnos y almacenarlos en la memoria previamente reservada.
Mostrar luego todos los datos de todos los alumnos. Liberar la memoria reservada al finalizar el programa.

Para acceder a los campos de la tabla/vector de structs del puntero, pensarlo igual que si fuera un arreglo (nombre_puntero[i].nombre_campo)
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} t_alumno;

void main(){ 
    t_alumno *puntero = NULL;
    int cantidad_alumnos, contador;

    printf("Ingrese la cantidad de alumnos que va a ingresar: ");
    scanf("%i", &cantidad_alumnos);

    puntero = (t_alumno*) malloc(cantidad_alumnos * sizeof(t_alumno));

    if (puntero != NULL){
        printf("Espacio de memoria reservado exitosamente\n");

        for (contador = 0; contador < cantidad_alumnos; contador++){ // Asignamos valores a los campos del struct reservado, recorriendolo como si fuera una tabla (puntero[i].campo)
            printf("Ingrese el padron del alumno: ");
            scanf("%i", &puntero[contador].padron);

            printf("Ingrese el nombre del alumno: ");
            scanf("%s", puntero[contador].nombre);

            printf("Ingrese el apellido del alumno: ");
            scanf("%s", puntero[contador].apellido);
        }

        printf("\nPadron\tNombre\tApellido\n"); // Imprimos el encabezado
        for (contador = 0; contador < cantidad_alumnos; contador++){ // Imprimos los valores de los campos del struct reservado, recorriendolo como si fuera una tabla (puntero[i].campo)
            printf("%i\t", puntero[contador].padron);
            printf("%s\t", puntero[contador].nombre);
            printf("%s\n", puntero[contador].apellido);
            printf("\n");
        }

        free(puntero);
        printf("Memoria Liberada");
    }
    else{
        printf("Nose pudo reservar espacio de memoria");
    }

}