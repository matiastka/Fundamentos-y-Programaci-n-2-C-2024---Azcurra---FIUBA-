/*
Desarrollar un programa que muestre la suma de los primeros N números naturales. El numero N lo debe ingresar el usuario.
*/
# include <stdio.h>

int MostrarSumaHastaN(int n){
    if (n < 1){
        return n;
    }
    else{
        return MostrarSumaHastaN(n-1) + n;
    }
}

void main(){
    int numero, resultado;

    printf("Ingrese un numero natural: ");
    scanf("%i", &numero);

    resultado = MostrarSumaHastaN(numero);

    printf("El resultado es: %i", resultado);
}