/*
Desarrollar una funcion recursiva en lenguaje C que reciba un entero y devuelva la sumatoria de ese numero. 
Ejemplo: Sumatoria(6) tiene que devolver 21 puesto que 1+2+3+4+5+6 = 21
Ademas si se tiene un numero negativo o 0, tiene que devolver 0
*/

# include <stdio.h>

int sumatoria(int numero){
    if (numero <= 0){
        return 0;
    }
    else{
        return numero + sumatoria(numero-1);
    }
}

void main(){
    int numero, resultado;

    numero = 6;

    resultado = sumatoria(numero);

    printf("La sumatoria de %i es: %i", numero, resultado);
}