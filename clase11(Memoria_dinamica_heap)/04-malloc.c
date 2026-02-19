/*
Ejemplo de uso de malloc() y free() para reservar espacio de memoria para almacenar N valores enteros en función de lo que ingrese el usuario.
Asignación de valores al espacio reservado usando posicionamiento como si fuese un arreglo/vector (nombre_puntero[contador])
*/
#include <stdio.h>
#include <stdlib.h>

void main() {
    // 1. Declaramos un puntero para almacenar la dirección de inicio del espacio que vamos a reservar
    int *enteros = NULL, posicion;

    // 2. Solicitamos el ingreso de un numero para indicar la cantidad de valores a almacenar
    int cantidad_enteros;
    printf("Indique la cantidad de valores enteros a almacenar: ");
    scanf("%i", &cantidad_enteros);

    // 3. Reservamos espacio usando la función malloc que nos devuelve la dirección de inicio
    enteros = malloc(cantidad_enteros * sizeof(int));

    if (enteros != NULL) {
        printf("Espacio de memoria reservado exitosamente.\n");

        // 4. Asignamos valores al espacio reservado, recorriendolo como si fuera un arreglo (nombre_puntero[i] = valor)
        for (posicion = 0; posicion < cantidad_enteros; posicion++)
            enteros[posicion] = 2 * posicion;

        // 5. Mostramos los valores almacenados en cada uno de los espacios y su dirección
        for (posicion = 0; posicion < cantidad_enteros; posicion++)
            printf("Direccion: H:%x Valor en posicion %d: %d \n", enteros + posicion, posicion, enteros[posicion]);

        fflush(stdin);
        getchar();

        free(enteros);
        printf("Memoria liberada\n");

        fflush(stdin);
        getchar();
    }
    else
        printf("Error al reservar espacio de memoria.");
    return;
}