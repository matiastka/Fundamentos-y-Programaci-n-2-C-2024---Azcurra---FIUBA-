/*
Dado un número n, informar los n primeros términos de la sucesión geométrica de
razón 3 (1, 3, 9, 27, etc.).
*/

# include <stdio.h>

void main(){
    int numero, contador, resultado;
    
    resultado = 1;

    printf("Ingrese un numero: ");
    scanf("%i", &numero);

    for(contador = 1; contador <= numero; contador++){
        printf("%i\n", resultado); // Primero hay que imprimir el resultado porque sino no responde correctamente  (empieza multiplicando por 3, cuando tiene que empezar siendo 1)
        resultado = resultado * 3; // Sucesion geometrica de razon 3: ayudado por aria (ver en Problemas con ingreso en C)
    }
    return;
}