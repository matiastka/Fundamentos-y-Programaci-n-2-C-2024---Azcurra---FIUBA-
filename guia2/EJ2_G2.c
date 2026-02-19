/*
Escribir una función que reciba un valor y calcule el factorial del mismo. Si no se
puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo
contrario deberá devolver el valor calculado. 
*/

# include <stdio.h>

int CalcularFactorial(int valor){
    int factorial, contador;
    contador = 1;
    factorial = 1; // No olvidar de inicializar el resultado, sino calcula BASURA

    if (valor < 0){
        factorial = 0;
    }

    if (valor == 0 || valor == 1){
        factorial = 1;
    }

    if (valor > 1){
        for (contador = valor; contador > 0; contador--){ // El contador se inicia en 1 porque el factorial empieza en 0 y el factorial es 5! = 5 * 4 * 3 * 2 * 1
            factorial = factorial * contador;
        }
    }
    return factorial;
}


void main(){
    int valor, factorial;
    printf("Ingrese un valor: ");
    scanf("%i", &valor);

    factorial = CalcularFactorial(valor);
    printf("El factorial de %i es %i", valor, factorial);
}