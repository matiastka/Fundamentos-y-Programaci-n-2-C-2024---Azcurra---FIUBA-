/*
Escribir un programa el cual reserve memoria dinámica para almacenar un
número entero (int), le solicite al usuario el ingreso de un número y se asigna
dicho valor en la memoria reservada, luego mostrar dicho valor por pantalla
Liberar la memoria reservada al finalizar el programa.
*/

# include <stdio.h>
# include <stdlib.h>

void main(){
    // Forma 1 (lo hacemos igual que en la teorica)
    int *puntero = NULL, valor;

    puntero = malloc(sizeof(int)); // Queremos asignar al puntero la direccion de memoria de un valor entero (solo de 1, entonces no se multiplica por MF)

    if (puntero != NULL) {
        printf("Espacio de memoria reservado exitosamente\n");

        printf("Ingrese un numero para almacenar en un espacio de memoria reservado: ");
        scanf("%i", &valor);

        *puntero = valor; 

        printf("El valor reservado a la memoria dinamica es: %i\n", *puntero);

        free(puntero);
        printf("Memoria liberada");
    }
    else{
        printf("No se pudo reservar memoria");
    }

    // Forma 2
    int *puntero = NULL;

    puntero = malloc(sizeof(int)); // Queremos asignar al puntero la direccion de memoria de un valor entero (solo de 1, entonces no se multiplica por MF)

    if (puntero != NULL) {
        printf("Espacio de memoria reservado exitosamente\n");

        printf("Ingrese un numero para almacenar en un espacio de memoria reservado: ");
        scanf("%i", &(*puntero));

        printf("El valor reservado a la memoria dinamica es: %i\n", *puntero);

        free(puntero);
        printf("Memoria liberada");
    }
    else{
        printf("No se pudo reservar memoria");
    }
}
