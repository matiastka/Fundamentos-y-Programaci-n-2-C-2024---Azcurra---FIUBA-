// Desarrollar un programa que solicite al usuario el ingreso de un numero entero y lo muestre invertido. No se puede utilizar vectores

# include <stdio.h>

void invertir_numero(int numero){
    if (numero < 10){ // Caso Base
        printf("%i", numero);
    }
    else{ // Caso Recursivo
        printf("%i", numero%10); // Imprimimos el digito que sacamos
        invertir_numero(numero/10); // Nos quedamos con todo el numero sin el ultimo digito
    }
}

void main(){
    int numero;

    printf("Ingrese un numero entero: ");
    scanf("%i", &numero);

    invertir_numero(numero);
}