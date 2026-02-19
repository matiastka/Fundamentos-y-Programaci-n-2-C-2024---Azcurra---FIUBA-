// Mostar de a uno los digitos de un numero

# include <stdio.h>

void Mostrar_digitos(int numero){
    if (numero < 10){ // Caso base (imprime si solo tiene un digito)
        printf("%i\n", numero);
    }
    else{ // Caso recursivo (Imprime si la division entera del numero por 10 tiene un digito (= numero sin el ultimo digito), imprime el digito que se saco)
        Mostrar_digitos(numero/10);
        printf("%i\n", numero%10);
    }
}

void Mostrar_digitos_al_reves(int numero){
    if (numero < 10){ // Caso base
        printf("%i\n", numero);
    }
    else{ // Caso recursivo
        printf("%i\n", numero%10);
        Mostrar_digitos_al_reves(numero/10);
    }
}

void main(){
    Mostrar_digitos(110203);
    Mostrar_digitos_al_reves(110203);
}