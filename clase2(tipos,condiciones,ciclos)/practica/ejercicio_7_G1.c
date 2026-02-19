/*Ingresar un número (del 1 al 7) que representa un día de la semana, escribir el
nombre del día correspondiente. En el caso de haber ingresado un número fuera de
rango indicarle del error al usuario*/

# include <stdio.h>

void main(){
    int dia;

    printf("Ingrese un dia de la semana: ");
    scanf("%i", &dia);

    // Forma switch:

    switch (dia){
        case 1:
            printf("El dia es Lunes");
            break;
        case 2:
            printf("El dia es Martes");
            break;
        case 3:
            printf("El dia es Miercoles");
            break;
        case 4:
            printf("El dia es Jueves");
            break;
        case 5:
            printf("El dia es Viernes");
            break;
        case 6:
            printf("El dia es Sabado");
            break;
        case 7:
            printf("El dia es Domingo");
            break;
        default:
            printf("Inexistente");
        }
    /* Forma if y while
    while (dia < 1 || dia > 7){
        printf("Ingreso incorrectamente el dia, vuelva a hacerlo: ");
        scanf("%i", &dia);
    }

    if (dia == 1){
        printf("El dia es Lunes");
    }

    if (dia == 2){
        printf("El dia es Martes");
    }

    if (dia == 3){
        printf("El dia es Miercoles");
    }

    if (dia == 4){
        printf("El dia es Jueves");
    }

    if (dia == 5){
        printf("El dia es Viernes");
    }

    if (dia == 6){
        printf("El dia es Sabado");
    }

    if (dia == 7){
        printf("El dia es Domingo");
    }
    */
    return;
}