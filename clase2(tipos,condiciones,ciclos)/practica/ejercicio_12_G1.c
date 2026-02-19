/*
Dados a y n números enteros, informar la potencia enésima de a por productos sucesivos.
*/

// Potencia enecima = a^n (ayudado por aria)

# include <stdio.h>

void main(){
    int a, n, contador, resultado;

    resultado = 1;

    printf("Ingrese el valor de a: "); // a == base
    scanf("%i", &a);

    printf("Ingrese el valor de n: "); // n = potencia
    scanf("%i", &n);

    for (contador = 1; contador <= n; contador++){
        resultado = resultado * a;
    }
    printf("El resultado es: %i", resultado);

    return;
}
