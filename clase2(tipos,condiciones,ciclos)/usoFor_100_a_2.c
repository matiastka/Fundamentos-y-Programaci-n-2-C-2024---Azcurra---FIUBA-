/*
Ejemplo que usa for.
Imprime los numeros pares del 100 al 2
El for necesita:
1. Una variable contador con su valor inciial
2. Condición que de be cumplir la variable contador
3. incremento o decrmento que se le aplicará en cada ciclo a la variable contador
*/

# include <stdio.h>

void main(){
    int contador;

    for (contador = 100; contador > 0; contador-=2){
        printf("%i ", contador); // despues del %i va un espacio para que devuelva bien los numeros (sino poner: "%i\")
    }
    return;
}