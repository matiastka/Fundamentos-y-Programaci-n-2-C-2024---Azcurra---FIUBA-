# include <stdio.h>

void main(){
    int valor;
    printf("Ingrese valor a comparar: ");
    scanf("%i" , &valor);

    if (valor == 51)
        printf("Bingo! Numero correcto \n");
    printf("\aAdios!\n");

    return;
}