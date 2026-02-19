/*
Desarrollar un programa que solicite al usuario el ingreso de un numero entero y lo muestre invertido. No se puede utilizar vectores.
*/

# include <stdio.h>

void mostrar_numero_invertido(int numero){
    if (numero < 10){
        printf("%i", numero);
    }
    else{
        printf("%i", numero%10);
        mostrar_numero_invertido(numero/10);
    }
}

void main(){
    int numero;

    printf("Ingrese un numero entero: ");
    scanf("%i", &numero);

    mostrar_numero_invertido(numero);
}