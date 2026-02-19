// Desarrollar un programa que calcule y muestre por pantalla los primeros N términos de la sucesión de Fibonacci en forma recursiva.

# include <stdio.h>

int fibonacci_recursivo(int numero){
    if (numero == 0){ // Caso base parte 1
        return 0;
    }
    else{
        if (numero == 1){ // ... parte 2
            return 1;
        }
        else{ // Caso Recursivo
            return fibonacci_recursivo(numero - 2) + fibonacci_recursivo(numero - 1);
        }
    }
}

void main(){
    int numero, resultado;
    numero = 2;
    resultado = fibonacci_recursivo(numero);
    printf("El fibonacci de %i es: %i", numero, resultado);
}