/*
Leer una serie de números terminada en 0 y mostrar los divisores de cada número 
(termina el ejercicio cuando se ingresa 0)
*/

# include <stdio.h>

int main(){
    int numero, contador;

    printf("Ingrese un numero (finaliza en 0): ");
    scanf("%i", &numero);

    if (numero == 0){
        printf("No existe divisor de 0");
    }

    while (numero != 0){
        if (numero < 0){
            numero = numero * -1;
        }
        for (contador = 1; contador <= numero; contador++){ // contador <= numero porque sino no se incluye el mismo valor como divisor.
            if (numero % contador == 0){
                printf("Los divisores positivos de %i son: %i\n", numero , contador);
            }
        }
        for (contador = -1; contador >= -numero; contador--){ // contador >= -numero porque sino no se incluye el mismo valor como divisor.
            if (numero % contador == 0){
                printf("Los divisores negativos de -%i son: %i\n", numero , contador);
            }
        }
        printf("Ingrese un numero (finaliza en 0): ");
        scanf("%i", &numero);
    }

    return 0;
}