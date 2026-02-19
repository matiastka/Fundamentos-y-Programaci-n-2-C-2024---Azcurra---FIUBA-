/*
Escribir una función que reciba un valor n, entero, y devuelva la suma de los
valores entre 0 y n. 
*/

# include <stdio.h>

int Sumatoria(int n){
    int contador, suma;
    contador = 0;
    suma = 0; // No olvidar de inicializar la variable donde se guarda el resultado (SINO CALCULA BASURA)

    for (contador = 0; contador <= n; contador++){
        suma = suma + contador;
        printf("El contador es: %i\n", contador);
    }
    return suma;
}


void main(){
    int n, resultado;

    printf("Ingrese un valor: ");
    scanf("%i", &n);

    if (n >= 0){
        resultado = Sumatoria(n);
        printf("EL resultado de 0 a %i es: %i", n, resultado);
    }
    else{ //Falto hacer la validacion de si n es negativo. GRACIAS ARIA!
        printf("El resultado de %i a 0 es 0", n);
    }

}  