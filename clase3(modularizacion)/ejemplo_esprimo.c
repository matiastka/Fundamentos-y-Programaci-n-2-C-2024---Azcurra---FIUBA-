// Ingresar/leer un numero e indiciar si es primo (el objetivo del ciclo es saber si hay divisores, si tiene no es primo, sino tiene es primo)
# include <stdio.h>
# include <stdbool.h>

int main(){
    int numero, contador;
    bool Esprimo; // Definimos como un booleano a Esprimo
    
    printf("Ingrese un numero: ");
    scanf("%i", &numero);
    
    Esprimo = true;

    contador = 2; // Empieza en 2 porque los numeros primos son desde 2 hasta infinito

    while ((Esprimo) && contador < numero){ // Forma mejorada: contador <= numero /2
        if (numero % contador == 0){
            Esprimo = false;
        }
        else{
            contador++;
        }
    }
    if (Esprimo){
        printf("Es primo");
    }
    else{
        printf("No es primo");
    }
    
    return 0;
    
}