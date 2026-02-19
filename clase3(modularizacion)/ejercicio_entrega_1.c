/*
Escribir una función que reciba un valor y calcule el factorial del mismo.
No debe imprimir el valor, debe solamente devolverlo.
Si no se puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo contrario deberá devolver el valor calculado. 

Invocarla para los valores -8, 0, 1, 5; mostrando en cada caso lo que devuelve.

Definición: El factorial de un entero positivo n,  se define como el producto de todos los números enteros positivos desde 1 hasta n.  El factorial de 0 es 1.

Para la construcción del programa, podés utilizar el editor del intérprete o el ide que prefieras.
Luego copia y pega lo que hayas hecho en la caja de texto de esta actividad y efectuá la entrega de la misma.
*/

# include <stdio.h>

long calcular_factorial(long valor){
    long contador, factorial;
    factorial = 1;
    if ( valor<0){
        factorial = 0;
    }
    else{
        for (contador = valor; contador > 0; contador--){
            factorial = factorial * contador;
        }
    }
    return factorial; // Solo tiene que haber un return por función (no puede tener más)    
}

void main(){
    long fact_de_menos_8, fact_de_0, fact_de_1, fact_de_5;
    fact_de_menos_8 = calcular_factorial(-8);
    fact_de_0 = calcular_factorial(0);
    fact_de_1 = calcular_factorial(1);
    fact_de_5 = calcular_factorial(5);
    printf("El factorial de -8 es: %lu\n", fact_de_menos_8);
    printf("El factorial de 0 es: %lu\n", fact_de_0);
    printf("El factorial de 1 es: %lu\n", fact_de_1);
    printf("El factorial de 5 es: %lu\n", fact_de_5);
    return;
}