/*
Desarrollar en lenguaje C una función recursiva que compruebe si un número es binario.
Nota: un número binario está formado únicamente por ceros y unos.
*/

# include <stdio.h>

int es_binario(int numero){
    if ((numero % 10 != 0) && (numero % 10 != 1)){
        return -1;
    }
    else{ 
        if (numero < 10){
            return 1;
        }
        else{
            return es_binario(numero/10);
        }
    }
}