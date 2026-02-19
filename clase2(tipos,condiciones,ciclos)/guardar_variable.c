/* Algoritmo que solicita el ingreso de un valor entero y la almacena en una variable.*/
#include <stdio.h>

void main()
{
    int valor;

    printf("Valor: ");
    scanf("%i", &valor);

    printf("\nValor Ingresado: %i", valor);

    return;
}