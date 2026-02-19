// Desarrollar un programa que solicite al usuario el ingreso de 2 números A y B y calcule la potencia de A elevado a la B de forma recursiva.

# include <stdio.h>

float potencia(float A, float B){
    if (B <= 1){
        return A;
    }
    else{
        return potencia(A, B-1) * A;
    }
}

void main(){
    float A, B, resultado;

    printf("Ingrese el numero A: ");
    scanf("%f", &A);

    printf("Ingrese el numero B: ");
    scanf("%f", &B);

    resultado = potencia(A,B);

    printf("La potencia de %f^%f es: %f", A, B, resultado);
}
