/*
Escribir un programa que solicite el ingreso de una serie de números.
Por cada número ingresado se deberá informar si el mismo es ó no, un número
capicúa.
Se debe evaluar que lo ingresado, sea un número entero positivo; de lo contrario,
se debe enviar el mensaje “Número Inválido”, y solicitar el siguiente.
El ingreso de números, termina cuando en lugar de un número, el usuario ingresa
“FIN”.
*/

# include <stdio.h>

# include <stdbool.h>

bool ValidarCapicua(int numero){ // Ayudado por lo de la clase
    int Aux, Invertido;
    bool resultado; 
    
    resultado = false;

    Aux = numero;

    Invertido = (Aux % 10);

    while (Aux > 9){
        Aux = Aux / 10;
        Invertido = (Invertido * 10) + (Aux %10);     
    }
    if (numero == Invertido){
        resultado = true;
    }
    return resultado;
}

void main(){
    int numero;
    bool continuar;

    continuar = true;

    while (continuar){
        printf("Ingrese un numero (0 para finalizar): ");
        scanf("%i",&numero);

        if (numero == 0){ //0 va a representar el "fin"
            continuar = false;
        }
        else{
            if (numero < 0){
                printf("Numero invalido.\n");
                continue;
            }

            ValidarCapicua(numero);

            if (ValidarCapicua(numero)){
                printf("El numero %i es capicua\n", numero);
            }
            else{
                printf("El numero %i no es capicua\n", numero);
            }
        }
    }
}