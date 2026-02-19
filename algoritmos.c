/*Practicando algoritmos conocidos: */

// ¿Es primo?

# include <stdio.h>
# include <stdbool.h>

void Esprimo(int numero){
    int i;
    bool esprimo;

    i = 2; // i tiene que ser 2 porque de 2 para atras los numeros no son primos
    esprimo = true;

    if (numero < 2){
        esprimo = false;
    }
    else{
        while ((esprimo) && (i < numero)){
            if (numero % i == 0){
                esprimo = false;
            }
            i++;
        }
    }
    if (esprimo == true){
        printf("El %i es primo", numero);
    }
    else{
        printf("El %i no es primo", numero);
    }
}

void main(){
    int numero;

    numero = 9;

    Esprimo(numero);

}