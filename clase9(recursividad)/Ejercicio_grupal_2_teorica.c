/*
Implemntar la sucesion de Fibonacci (ver codigo de la practica)
*/

# include <stdio.h>

int fibonacci_por_iteracion(int numero){
    int i, aux, aux2, resultado;
    aux = 0;
    aux2 = 1;
    resultado = 0;
    
    for (i = 2; i <= numero; i++){
        resultado = aux + aux2;
        aux = aux2;
        aux2 = resultado;
    }
    return resultado;
}

void main(){
    int resultado;

    resultado = fibonacci_por_iteracion(6);
    printf("El fibonacchi es: %i", resultado);
}