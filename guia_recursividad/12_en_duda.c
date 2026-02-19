// Desarrollar un programa que muestre los primeros N números naturales. El numero N lo debe ingresar el usuario.

# include <stdio.h>

void mostrar_N_numeros_descendente(int N){
    printf("%i\n", N);
    if (N > 1){
        mostrar_N_numeros_descendente(N-1);
    }
}

void mostrar_N_numeros_ascendente(int N){
    if (N > 1){
        mostrar_N_numeros_ascendente(N-1);
    }
    printf("%i\n", N);
}

void main(){
    int N;

    printf("Ingrese un numero natural: "); // Hay que validar con recursividad?
    scanf("%i", &N);
    
    mostrar_N_numeros_descendente(N);
    mostrar_N_numeros_ascendente(N);
}