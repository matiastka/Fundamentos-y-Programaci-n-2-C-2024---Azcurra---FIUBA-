/*
Mostrar tablas de multiplicar para los numeros del 1 al 100
*/

// Completamente ayudado por la gente y aria. Este ejercicio tiene 2 valores 'dinámicos' que son el numero de la tabla y el multiplo

# include <stdio.h>

void main(){
    int contador1, contador2, resultado;

    resultado = 1;

    for (contador1 = 1; contador1 <= 10; contador1++){ // Tabla de 'x' numero (del 1 al 100)
        for (contador2 = 1; contador2 <= 10; contador2++){ // Multiplo de 'x' numero (del 1 al 10)
            resultado = contador1 * contador2; // Hacer numero * multiplo
            printf("El resultado de: %i x %i = %i\n", contador1, contador2, resultado);
        }
    }
    return;
}