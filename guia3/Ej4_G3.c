/*
 Escribir un programa que solicite el ingreso de dos números, y luego informe los
números primos que hay entre esos dos números.
Se debe validar que los números ingresados sean enteros y además que el primer
número sea menor o igual que el segundo.
*/

# include <stdio.h>
# include <stdbool.h>

ValidarIngreso(int *valor){
    while (*valor < 0){
        printf("Ingrese un valor: ");
        scanf("%i", valor);
    }
}

void ValidarMayor(int *valor_1, int *valor_2){

    ValidarIngreso(valor_1); // Si tengo un mismo parametro que ya se paso por referencia no va el & (a pesar de que tambien vaya a ser un parametro por referencia de otra funcion)
    ValidarIngreso(valor_2);
    
    while (*valor_1 > *valor_2){
        printf("el 1er valor debe ser menor igual al 2do\n");
        printf("Ingrese nuevamente el 1er valor: ");
        scanf("%i", valor_1);
    }
}  

bool EsPrimo(int numero){ // Copiado del ejercicio EJ4 G2
    int contador;
    bool resultado;

    resultado = true; 
    contador = 2;

    if (numero <= 1){
        resultado = false;
    }

    if (numero == 2){
        resultado = true;
    }

    if ((numero > 2) && (numero % 2 == 0)){
        resultado = false;
    }
    
    if ((numero > 2) && (numero % 2 != 0)){
        while ((resultado) && (contador <= numero / 2)){ // es contador <= numero / 2 por teorema matematico
            if (numero % contador == 0){
                resultado = false;
            }
            else{
                contador++;
            }
        }
    }
    return resultado;
}

void VerPrimos(int valor_1, int valor_2){
    int contador;

    for (contador = valor_1; contador <= valor_2; contador++){
        if (EsPrimo(contador))
            printf("El %i es primo\n", contador);
    }

}

void main(){
    int valor_1, valor_2;
    
    valor_1 = -1;
    valor_2 = -1;

    ValidarMayor(&valor_1, &valor_2);
    VerPrimos(valor_1, valor_2);
}