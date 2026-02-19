// Problema: Desarrollar un programa que muestre la suma de los primeros N números naturales. El numero N lo debe ingresar el usuario.

# include <stdio.h>

int sumar_primeros_N_numeros_naturales(int N){ // Esto solo tiene que devolver o tiene que imprimir (de ser asi ni idea como imprimir la suma)?
    if (N <= 0){
        return 0;
    }
    else{
        return N + sumar_primeros_N_numeros_naturales(N-1);
    }
}

void main(){
    int N, resultado;
    printf("Ingrese un numero natural: ");
    scanf("%i", &N); // Hay que validar el ingreso, de ser asi tiene que ser recursivo?

    resultado = sumar_primeros_N_numeros_naturales(N);
    printf("La suma de los primeros %i numeros es: %i", N, resultado);
}