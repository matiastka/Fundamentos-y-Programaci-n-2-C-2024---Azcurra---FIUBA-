/* Dada una fecha con año, mes y día, informar si es correcta o no. Solicitarle los
datos al usuario de forma independiente. Considerar años bisiestos.
*/

# include <stdio.h>

void main(){
    int anio, mes, dia, validacion_basica, validar_año_biciesto, validar_mes_con_30, validar_mes_con_31, validar_febrero_con_29, validar_febrero_con_28;

    printf("Ingrese un anio: ");
    scanf("%i", &anio);
    
    printf("Ingrese un mes: ");
    scanf("%i", &mes);
    
    printf("Ingrese un dia: ");
    scanf("%i", &dia);
    
    validacion_basica = anio < 0 || dia <= 0 || mes <= 0 || mes > 12 || dia > 31;

    validar_mes_con_30 = ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia <= 30));

    validar_mes_con_31 = ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia <= 31));

    validar_febrero_con_29 = ((mes == 2 && dia <= 29 && ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)))); // Valida si el año es biciesto, --> febrero debe tener 29 dias 

    validar_febrero_con_28 = (((anio % 4 != 0) || (anio % 100 == 0 && anio % 400 != 0)) && (mes == 2 && dia <= 28)); // Valida si el año no es biciesto --> febrero debe tener 28 dias 


    if (validacion_basica){
        printf("La fecha ingresada es incorrecta");
    }
    else{
        if (validar_mes_con_30){
            printf("La fecha es correcta");
        }
        else{
            if (validar_mes_con_31){
                printf("La fecha es correcta");
            }
            else{
                if (validar_febrero_con_29 || validar_febrero_con_28){ // Para considerar si febrero debe tener 29 o 28 dias, se usa la validación de si es biciesto o no (al mismo tiempo)
                    printf("La fecha es correcta");
                }
                else{
                    printf("La fecha es incorrecta");
                }
            }
        }
    }
    return;
}