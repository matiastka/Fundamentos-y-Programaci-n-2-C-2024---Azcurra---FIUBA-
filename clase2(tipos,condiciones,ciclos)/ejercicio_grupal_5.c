/* 5
    Solicitar un número entero positivo al usuario y calcular su factorial. En el caso de    ingresar un número negativo mostrar un mensaje que diga:
    “no se puede calcular el factorial del número ingresado”.
    Recordar que por definición factorial(0)=1 y factorial(1)=1
*/
# include <stdio.h>

void main(){
    int numero, contador, factorial;
    
    printf("Ingrese un numero: ");
    scanf("%i", &numero);

    factorial = 1; // Como factorial afecta tanto el if de numero == 1 o  numero == 0 como tambien al for, entonces se define afuera de las condiciones

    if (numero<0 || numero > 12) // Limito hasta (incluido) 12 porque se rompe el calculo
        printf("No se puede calcular el factorial del numero ingresado");
    else{ 
        if (numero == 1 || numero == 0){ 
            printf("El factorial de %i es: %i ", numero, factorial);
        }
        else{
            for (contador = numero; contador > 0; contador--){ // Traducción: contador = numero, mientras contador sea mayor a 0 hace factorial. Contador se va restando 1 hasta ser 0
                factorial = factorial * contador;
            }
            printf("El factorial de %i es: %i ", numero, factorial);            
        }
    }
    
    return;
}