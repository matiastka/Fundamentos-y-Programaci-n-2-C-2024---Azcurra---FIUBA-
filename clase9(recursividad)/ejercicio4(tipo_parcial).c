// Sumar los digitos de un numero

# include <stdio.h>

int Sumar(int numero){
    if (numero < 10){
        return numero;
    }
    return Sumar(numero / 10) + numero % 10; // Sumamos la division entera de numero/10 con el resto del numero (devuelve la suma del numero sin el ultimo digito + el ultimo digito)
}

void main(){
    int resultado, numero;

    numero = 1213;
    resultado = Sumar(numero);

    printf("El resultado de sumar los digitos de %i: %i", numero , resultado); 
}

/*
Entra a Sumar(1213):
Si 1213 < 10 no! Devuelve: Sumar(121) + 3 
Vuelve a entrar a Sumar(121) Si: 121 < 10 no! Devuelve: Sumar(12) + 1 + 3 = Sumar(12) + 4
Vuelve a entrar a Sumar(12) Si 12 < 10 no! Devuelve: Sumar(1) + 2 + 1 + 3 = Sumar(1) + 6
Vuelve a entrar a Sumar(1) Si 1 < 10 oK Devuelve: que Sumar(1) = 1 --> 1 + 6 = 7
Entonces tenemos que 1 + 2 + 1 + 3 = 7
*/