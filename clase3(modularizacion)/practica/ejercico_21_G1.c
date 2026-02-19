/*
21) Se dan como datos de entrada las fechas de nacimiento (día, mes, año) y los números
de DNI de cada integrante de un grupo.
Se indica fin de datos de entrada cuando día = 0.
Muestre por pantalla el número de DNI del integrante más joven del grupo.
*/

# include <stdio.h>

# include <stdbool.h>

int main(){
    int dia, mes, anio, dni, mayor_dia, mayor_mes, mayor_anio, dni_mas_joven;
    bool Continuar;
    
    Continuar = true;
    mayor_dia = -1;
    mayor_mes = -1;
    mayor_anio = -1;
    dni_mas_joven = -1;

    while (Continuar){
        printf("Ingrese su dia de nacimiento (0 para terminar): ");
        scanf("%i", &dia);

        if (dia != 0){
            printf("Ingrese su mes de nacimiento: ");
            scanf("%i", &mes);

            printf("Ingrese su anio de nacimiento: ");
            scanf("%i", &anio);
            
            printf("Ingrese su DNI: ");
            scanf("%i", &dni);
    
            if ((anio > mayor_anio) || ((anio == mayor_anio) && (mes > mayor_mes)) || ((anio == mayor_anio) && (mes == mayor_mes) && (dia > mayor_dia))){
                mayor_anio = anio;
                mayor_mes = mes;
                mayor_dia = dia;
                dni_mas_joven = dni;
            }
        }
        else{
            Continuar = false;
        }
    }
    if (dni_mas_joven < 0){
        printf("No ingresaron datos validos.");
    }
    else{
        printf("El DNI del integrante mas joven es: %i ", dni_mas_joven);
    }

    return 0;

}