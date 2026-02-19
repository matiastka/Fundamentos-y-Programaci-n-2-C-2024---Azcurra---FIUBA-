/*
Implementar una funcion que permita dividir 2 numeros enteros por restas sucesivas
*/

# include <stdio.h>

int dividir_por_restas_sucesivas(int dividendo, int divisor){
    if (divisor > dividendo){
        return 0;
    }
    else{
        return 1 + dividir_por_restas_sucesivas(dividendo - divisor , divisor); // rever la clase
    }
}

void main(){
    int resultado;
    resultado = dividir_por_restas_sucesivas(11,2);
    printf("El resultado que permite dividir 2 numeros enteros por restas sucesivas es: %i", resultado);
}
