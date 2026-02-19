/*
Reservar memoria para almacenar una palabra ingresada por el usuario, es leída en una cadena auxiliar, luego copiada a memoria dinámica, 
recordando que se requiere adicionar un carácter de fin de cadena '\n'.
Ejemplo:
"hola mundo" + '\0' -> requiere espacio para 11 caracteres.
char* cadena_aux = "hola mundo";
char* cadena = malloc(strlen(cadena_aux) * sizeof(char) + 1);
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void main(){
    char cadena_aux[100];

    printf("Ingrese algo (sin espacios): ");
    scanf("%s", cadena_aux);

    char* cadena = malloc(strlen(cadena_aux) * sizeof(char) + 1);

    if (cadena != NULL){
        strcpy(cadena, cadena_aux); // Gracias Aria
        printf("Espacio de memoria reservado exitosamente");
        free(cadena);
    }
    else{
        printf("Fallo en reservarse espacio de memoria");
    }
}