/*
16) Dado un número entero positivo ingresado por el usuario, procesarlo e indicar:
(realizar un programa diferente para cada caso)
a) La cantidad de dígitos pares e impares que lo componen.
b) El menor y el mayor dígito del número.
Recordar uso de división y módulo:
Ejemplo:
111 / 10 = 11
111 % 10 = 1
*/

void cantidad_digitos_pares_e_impares(int numero, int *cant_pares, int *cant_impares ){ // Usamos punteros para obtener los valores pares e impares (Gracias Aria)
    int divisor, resto;

    *cant_impares = 0;
    *cant_pares = 0;
    divisor = numero;
    resto = 0; 

    while(divisor > 0){ // Hasta que el divisor (entero) sea menor/igual a 0 
        resto = divisor % 10;

        if (resto % 2 == 0){ // Verifica que sea par
            *cant_pares = *cant_pares + 1;
        }
        else{
            *cant_impares = *cant_impares + 1;
        }

        divisor = divisor / 10; // El cociente se convierte en el nuevo divisor

    }
}

void menor_y_mayor_digito(int numero, int *menor_digito, int *mayor_digito){
    int divisor, resto;

    *menor_digito = numero; // Se podría inicializar con el máximo valor que toma un digito (como 9) [gracias Aria]
    *mayor_digito = 0; // Se podría inicializar con un valor que no se verá en los dígitos (como -1) [gracias Aria]
    divisor = numero;
    resto = 0;

    while (divisor > 0){
        resto = divisor % 10;
        
        if (resto >= *mayor_digito){
            *mayor_digito = resto;
        }
        if (resto <= *menor_digito){
            *menor_digito = resto;
        }
        divisor = divisor / 10;
    }

}

int main(){
    int numero, cant_pares, cant_impares, menor_digito, mayor_digito;

    numero = 0;
    
    while (numero <= 0){
        printf("Ingrese un numero entero positivo: ");
        scanf("%i", &numero);
    }

    cantidad_digitos_pares_e_impares(numero, &cant_pares, &cant_impares); // Uso punteros para obtener mas de un valor de una funcion externa (gracias Aria)
    
    menor_y_mayor_digito(numero, &menor_digito, &mayor_digito);

    printf("La cantidad de digitos pares de %i es: %i\n", numero , cant_pares);
    printf("La cantidad de digitos impares de %i es: %i\n", numero , cant_impares);
    printf("El mayor digito de %i es : %i\n", numero, mayor_digito);
    printf("El menor digito de %i es : %i", numero, menor_digito);

    return 0;
}