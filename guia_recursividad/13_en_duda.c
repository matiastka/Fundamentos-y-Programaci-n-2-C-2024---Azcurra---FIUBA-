// Desarrollar una función recursiva que compruebe si un número es binario. Un número binario está formado únicamente por ceros y unos

# include <stdio.h>
# include <stdbool.h>

bool es_binario(int numero){
    if ((numero % 10 != 0) && (numero % 10 != 1)){ // Caso Base (verifica y corta si el digito no es binariio) parte 1
        return false;
    }
    else{ 
        if (numero < 10){ // ... parte 2 corta si es binario y no tiene digitos
            return true;
        }
        else{ // Caso Recursivo
            return es_binario(numero/10);
        }
    }
}

int es_binario_2(int numero){
    if (numero >= 10){ // Caso Base (verifica y corta si el numero tiene digitos)
        if ((numero % 10 != 0) && (numero % 10 != 1)){ // ... parte 1 (verifica que no sea binario (corte super principal))
            return -1;
        }
        else{ // Caso recursivo (va sacando el ultimo digito al numero y lo vuelve analizar)
            return es_binario(numero/10);
        }
    }
    else{ // Caso base (verifica y corta si el numero no tiene digitos)
        if ((numero != 0) && (numero != 1)){ // parte 1 (verifica que no sea binario el digito (corte principal))
            return -1;
        }
        else{ // parte 2 si !(no es binario) --> es binario
            return 1;
        }
    }
}

void main(){
    int numero;

    bool resultado;

    numero = -101;

    resultado = es_binario(numero);

    if (resultado == false){
        printf("El numero %i no es binario", numero);
    }
    else{
        printf("El numero %i es binario", numero);
    }
}