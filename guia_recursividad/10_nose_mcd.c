// Desarrollar un programa que solicite al usuario el ingreso de un numero entero y calcule el máximo común divisor de forma recursiva.

# include <stdio.h>

int MCD(int numero1, int numero2){ // Se uso el algoritmo de Euclides (Gracias Aria)
    if (numero2 == 0){ // Caso Base
        return numero1;
    }
    else{ // Caso Recursivo
        return MCD(numero2, numero1 % numero2);
    }
}

void main(){
    int numero1, numero2, resultado;

    printf("Ingrese el 1er numero entero: ");
    scanf("%i", &numero1);

    printf("Ingrese el 2do numero entero: ");
    scanf("%i", &numero2);

    resultado = MCD(numero1, numero2);

    printf("El Maximo Comun Divisor de %i y de %i es: %i", numero1, numero2, resultado);
}