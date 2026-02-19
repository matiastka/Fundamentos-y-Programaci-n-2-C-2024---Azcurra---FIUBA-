/*
Desarrollar un programa que calcule la factorial de un número en forma recursiva.
*/

# include <stdio.h>

int factorial_recursivo(int numero){
    if(numero <= 1){ // Caso base
        return numero;
    }
    else{ // Caso recursivo
        return numero * factorial_recursivo(numero-1);
    }
}

void main(){
    int numero, resultado;
    
    numero = 3;
    
    resultado = factorial_recursivo(numero);

    printf("El factorial de %i es: %i", numero, resultado);
}