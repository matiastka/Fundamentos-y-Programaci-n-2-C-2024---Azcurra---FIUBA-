/* Calcular el sueldo de un operario ingresando por teclado la cantidad de horas que
trabajó en el mes y el valor de la hora. Mostrarle el resultado al usuario con un
mensaje adecuado.
*/

# include <stdio.h>

void main(){
    int sueldo, cant_horas, valor_hora;

    printf("Ingrese la cantidad de horas trabajadas: ");
    scanf("%i", &cant_horas);

    printf("Ingrese el valor por hora: ");
    scanf("%i", &valor_hora);

    sueldo = cant_horas * valor_hora;

    printf("Su sueldo es: %i. Dado que trabaja %i horas a un valor por hora de %i", sueldo, cant_horas, valor_hora);

    return;
}
