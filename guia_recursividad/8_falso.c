/*
Desarrollar una función recursiva que comprube si un numero pasado como parámetro es capicúa (no resuelve el problema)
*/


# include <stdio.h>

int invertir_numero(int numero, int invertido){
    if (numero < 10){
        return (invertido * 10) + numero;
    }
    else{
        invertido = (invertido * 10) + (numero%10);
        return invertir_numero((numero/10), invertido);  
    }
}

void main(){
    int numero, invertido;
    numero = 12321;
    invertido = 0;
    
    invertido = invertir_numero(numero, invertido);

    printf("invertido = %i\n", invertido);

    if (invertido == numero){
        printf("El numero es capicua.");
    }
    else{
        printf("EL numero no es capicua.");
    }
}