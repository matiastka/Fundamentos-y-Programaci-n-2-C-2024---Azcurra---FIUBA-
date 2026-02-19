/*
Leer un número N Positivo y luego leer una serie de N números positivos. 
Para los números que sean primos mostrar el Factorial y los que no lo sean mostrar divisores
*/

# include <stdio.h>

# include <stdbool.h>

// Las funciones Es_primo y Factorial son Con Tipo y con parametros por valor.
// Las funcion Validar_Positivo es void y con parametro por referencia.
// La funcion Mostrar_Divisores es Con Tipo y con parametro por valor.

void Validar_Positivo(int *valor){
    while (*valor <= 0){
        printf("Ingrese un numero positivo");
        scanf("%i", valor); //Cuando el parametro es por referencia no necesita de & en el scanf
    }
}

bool Es_primo(int valor){
    int contador;
    bool es_primo;
    es_primo = true;

    for (contador = 2; contador <= valor; contador++){
        if (valor % contador == 0){
            es_primo = false;
        }
    }
    return es_primo;
}

int Factorial(int valor){ // Las funciones Con tipo solo devuelven un valor y no interactuan con el usuario
    int contador, resultado;
    
    resultado = 1;

    for (contador = valor; contador > 0; valor--){
        resultado = resultado * contador;
    }
    return resultado;
}

void Mostrar_Divisores(int valor){ //Las funciones void pueden devolver mas de un valor (o nada)
    int contador;

    for (contador = 1; contador <= valor; contador++){
        if (valor % contador == 0){
            printf("Los divisores de %i son: %i\n", valor, contador);
        }
    }
}

int main(){
    int Maximo_valor, numero, contador;
    
    Validar_Positivo(&Maximo_valor);
    for (contador = 0; contador <= Maximo_valor; contador++){
        Validar_Positivo(&numero);
        if (Es_primo(numero)){
            printf("El factorial de %i es %i", numero, Factorial(numero));
        }
        else{
            Mostrar_Divisores(numero);
        }
    }
}