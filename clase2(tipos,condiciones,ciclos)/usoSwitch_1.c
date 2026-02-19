/* Cuando las alternativas de decision son múltiples, en lugar de anidar if, puede ser  conveniente utilizar el condicional "switch", ya que permitirá reflejar de forma más clara, los distintos flujos del programa, en función del resultado de la  evaluación.
Ejemplo: Solicitar el ingreso de un número de mes, e informar a que mes corresponde. */
# include <stdio.h>

void main(){
    unsigned short mes;
    printf("Ingrese el nro. del mes: ");
    scanf("%i",&mes);

    printf("\nEl mes ingresado por Ud. es: ");
    
    switch (mes) {
        case 1 :
            printf("Enero");
            break;
        case 2 :
            printf("Febrero");
            break;
        case 3 :
            printf("Marzo");
            break;
        case 4 :
            printf("Abril");
            break;
        case 5 :
            printf("Mayo");
            break;
        case 6 :
            printf("Junio");
            break;
        case 7 :
            printf("Julio");
            break;
        case 8 :
            printf("Agosto");
            break;
        case 9 :
            printf("Setiembre");
            break;
        case 10 :
            printf("Octubre");
            break;
        case 11 :
            printf("Noviembre");
            break;
        case 12 :
            printf("Diciembre");
            break;
        default :
            printf("Inexistente");
    }
// la rama "default" puede no utilizarse
// El uso del break se hace necesario, para salir del switch y evitar // que se ejecuten las acciones que estén en los "case" que están por debajo// del "case" que hizo verdadera la evaluación
return;
}