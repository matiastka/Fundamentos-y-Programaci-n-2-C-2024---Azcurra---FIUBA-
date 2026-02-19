/*
Escribir un programa en C, que:
- declare una cadena para almacenar como máximo 40 caracteres y como valor inicial le asigne tu nombre y apellido
- recorra la cadena e imprima sólo las consonantes, una debajo de la otra
- indique cuantas consonantes hay en tu nombre y apellido
*/

# include <stdio.h>
# include <string.h>

# define MF 40

void main(){
    char cadena[MF] = "Matias Tkaczyk"; // Declaro una cadena de longitud 40 y le asigno mi nombre y apellido

    int i, cant_consonantes;
    
    cant_consonantes = 0;

    for (i = 0; i < strlen(cadena); i++){
        if (cadena[i] != ' ' && ((cadena[i] >= 'A' && cadena[i] <= 'Z' && (cadena[i] != 'A' && cadena[i] != 'E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U')) || (cadena[i] >= 'a' && cadena[i] <= 'z' && (cadena[i] != 'a' && cadena[i] != 'e' && cadena[i] != 'i' && cadena[i] != 'o' && cadena[i] != 'u')))) { // Validacion de que sea consonante
            printf("%c\n", cadena[i]);
            cant_consonantes++;
        }
    }
    printf("La cantidad de consonantes que tiene mi nombre es: %i", cant_consonantes);
}