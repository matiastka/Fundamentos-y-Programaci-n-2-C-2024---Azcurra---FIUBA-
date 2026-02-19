/*
Escribir un programa que solicite el ingreso de 2 valores enteros y luego informe
el resultado de multiplicarlos, pero mediante sumas sucesivas.
Optimizar el cálculo, realizando la menor cantidad de ciclos posibles.
Tener en cuenta que el usuario puede ingresar valores negativos.
*/

# include <stdio.h>

void ValorAbsoluto(int *valor){
    if (*valor < 0){
        *valor = *valor * -1;
    }
}

void MultiplicarPorSumasSucecivas(int a, int b, int *resultado){
    
    int contador, signo;
    signo = 1;
    contador = 0;

    if (a == 0 || b == 0){
        *resultado = 0;
    }
    else{
        if (((a < 0) && (b > 0)) || ((a > 0) && (b < 0))){ // Si alguno de los 2 es negativo, asigamos que el signo sea negativo
            signo = -1;
        }
        
        ValorAbsoluto(&a); 
        ValorAbsoluto(&b);
        // Aplicamos el modulo a ambos numeros para usarlos en el for

        for (contador = 0; contador < a; contador++){ // Hay que hacer: 4 + 4 + 4 = 4 * 3 (se suma 4 veces 3)
            *resultado = *resultado + b;
        }
        *resultado = *resultado * signo;
    }

}

void main(){
    int valor_1, valor_2, resultado;
    resultado = 0;

    printf("Ingrese valor 1: ");
    scanf("%i", &valor_1);

    printf("Ingrese valor 2: ");
    scanf("%i", &valor_2);

    MultiplicarPorSumasSucecivas(valor_1, valor_2, &resultado);
    printf("El resultado de %i * %i (en sumas sucesivas) es: %i ", valor_1, valor_2, resultado);

}