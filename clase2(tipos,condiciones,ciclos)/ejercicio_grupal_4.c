/* 4
Ingresar un número (del 1 al 12) que representa un mes, indicar la cantidad de días de dicho mes. (hay que validar que ingrese bien el número)
*/
# include <stdio.h>

void main(){
    int mes;
    do // Mientras mes sea mayor a 12 o menor a 1 va a seguir preguntando
    {
        printf("Ingrese un numero: ");
        scanf("%i", &mes);
    } while (mes < 1 || mes > 12);

    if (mes == 2)
        printf("Febrero tiene 28 dias. Si el anio es biciesto tiene 29");
    else{
        if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
            printf("El mes electo tiene 30 dias");
        else
            printf("El mes electo tiene 31 dias");
    }
    
    return;

}
