// Desarrollar un programa que calcule la factorial de un número en forma recursiva.

# include <stdio.h>

int factorial_recursivo(int numero){
    if (numero == 0){ // Caso Base
        return 1;
    }
    else{ // Caso Recursivo
        return numero * factorial_recursivo(numero-1); 
    }
}

void main(){
    int numero, resultado;
    numero = 5;
    resultado = factorial_recursivo(numero);
    printf("El factorial de %i es: %i", numero, resultado);
}