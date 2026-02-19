#include <stdio.h>

void main()
{
    int valor1, valor2;

    printf("Valor 1: ");
    scanf("%i", &valor1);

    printf("Valor 2: ");
    scanf("%i", &valor2);

    printf("\nValor1: %i y Valor2: %i \n\n", valor1, valor2);

    printf("Suma: %i \n", valor1 + valor2);

    printf("Resta: %i \n", valor1 - valor2);

    printf("Producto: %i \n", valor1 * valor2);

    printf("Division Entera: %i \n", valor1 / valor2);

    printf("Division Real: %f \n", (float)valor1 / valor2);

    return;
}