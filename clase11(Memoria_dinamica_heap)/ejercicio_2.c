/*
Escribir un programa el cual reserve memoria dinámica para almacenar una
cierta cantidad de números enteros (n * int), este valor n debe ser ingresado por
el usuario. Luego solicitarle que ingresé n valores enteros ingresados de a uno y
almacenarlos en la memoria previamente reservada. Mostrar luego todos los
valores ingresados. Liberar la memoria reservada al finalizar el programa.

hay que acceder a la distitnas posiciones del arreglo usando el puntero
*/

# include <stdio.h>
# include <stdlib.h>

void main() {
    int *enteros = NULL;
    int n, i;

    printf("Indique la cantidad de valores enteros a almacenar: ");
    scanf("%i", &n);

    enteros = malloc(n * sizeof(int));

    if (enteros != NULL) {
        printf("Espacio de memoria reservado exitosamente.\n");

        for (i = 0; i < n; i++){
            printf("Ingrese el numero entero: ");
            scanf("%i", &enteros[i]);
        }

        for (i = 0; i < n; i++){
            printf("El valor en la posicion %i es: %i \n", i, enteros[i]);
        }
        
        free(enteros);

        printf("Memoria liberada\n");
    }
    else
        printf("Error al reservar espacio de memoria.");
    return;
}
