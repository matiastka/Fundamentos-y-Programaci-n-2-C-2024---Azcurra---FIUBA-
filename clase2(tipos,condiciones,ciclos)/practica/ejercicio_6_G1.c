/* Ingresar tres números y hallar el mayor.*/

# include <stdio.h>

void main(){
    int numero_1, numero_2, numero_3;

    printf("Ingrese el 1er numero: ");
    scanf("%i", &numero_1);

    printf("Ingrese el 2do numero: ");
    scanf("%i", &numero_2);

    printf("Ingrese el 3er numero: ");
    scanf("%i", &numero_3);

    if (numero_1 > numero_2 && numero_1 > numero_3){
        printf("El numero %i es el mayor a todos", numero_1);
    }
    if (numero_2 > numero_1 && numero_2 > numero_3){
        printf("El numero %i es el mayor a todos", numero_2);
    }
    if (numero_3 > numero_1 && numero_3 > numero_2){
        printf("El numero %i es el mayor a todos", numero_3);
    }
    
    return;
}