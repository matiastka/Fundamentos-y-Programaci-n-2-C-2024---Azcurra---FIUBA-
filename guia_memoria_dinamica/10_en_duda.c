/*
Utilizar memoria dinámica para almacenar una cierta cantidad de n palabras
ingresadas por el usuario. Crear una estructura de datos dinámica de dos
dimensiones que permita almacenar esta información. Mostrar toda la
información de la estructura luego de haber sido cargada. Liberar toda la
memoria al finalizar el programa.
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

typedef char* t_palabra; // por enunciado
typedef t_palabra* t_vec;

void main(){
    t_vec puntero = NULL;
    int cant_palabras, contador;
    char palabras_usuario[100];
    bool error;

    error = false;

    printf("Ingrese la cantidad de palabras que va a ingresar: ");
    scanf("%i", &cant_palabras);

    puntero = (t_vec) malloc(cant_palabras * sizeof(t_palabra)); // gracias aria (asi se trabaja con 2 dimensiones, castear al vector y castear a la cadena)

    if (puntero != NULL){
        printf("Espacio de memoria reservado exitosamente");

        for (contador = 0; contador < cant_palabras; contador++){
            printf("Ingrese la palabra %i (max 100 caracteres)", contador + 1); // contador + 1 para que sea leible para el usuario
            scanf("%s", palabras_usuario);
            
            puntero[contador] = malloc(strlen(palabras_usuario) * sizeof(char) + 1); // Forma de hacer un malloc de un string

            if (puntero[contador] != NULL){
                strcpy(puntero[contador], palabras_usuario); // Copia la palabra del usuario a puntero[contador] (es la forma correcta de hacerlo)
            }
            else{
                error = true;
                printf("Fallo al asignarse espacio de memoria a la palabra %i\n", contador);
                printf("Memoria Liberada");
                free(puntero);
            }
        }

        if (error == false){
            for (contador = 0; contador < cant_palabras; contador++){
                printf("La palabra %i es: %s", contador, puntero[contador]);
            }
        }
        free(puntero);
        printf("Memoria Liberada");
    }
    else{
        printf("No se pudo reservar espacio de memoria");
    }
}