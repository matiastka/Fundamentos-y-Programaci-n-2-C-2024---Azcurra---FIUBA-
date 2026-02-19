/*
Desarrollar un programa que solicite al usuario el ingreso de un numero entero y lo muestre el resultado de sumar sus dígitos
*/
# include <stdio.h>

int sumar_digitos(int numero){
    if (numero < 10){
        return numero;
    }
    else{
        return sumar_digitos(numero/10) + numero % 10;
    }
}

void main(){
    int numero, resultado;

    printf("Ingrese un numero entero: ");
    scanf("%i", &numero);

    resultado = sumar_digitos(numero);

    printf("El resultado de sumar los digitos de %i es: %i", numero, resultado);
}