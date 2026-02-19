/*
Escribir una función que reciba un mes y un año; y devuelva la cantidad de días
del mes, considerando los años bisiestos.
Tenga en cuenta que un año bisiesto es aquel divisible por 4, salvo que sea
divisible por 100, en cuyo caso también debe ser divisible por 400. 
*/

# include <stdio.h>

void ValidarMes(int *mes){
    while (*mes < 1 || *mes > 12){ // El 1 y el 12 estan incluidos dentro del valido. Quiere decir que desde -inf hasta 1 (sin incluir) o desde 12 (sin incluir) hasta +inf entra al while
        printf("Ingrese un mes: ");
        scanf("%i", mes);
    }
}

void ValidarAnio(int *anio){
    while (*anio < 0){
        printf("Ingrese un anio (D.C): ");
        scanf("%i", anio);
    }
}

int DiasporMes_sin_switch(int mes, int anio){
    int cant_dias;
    if (mes == 1){
        cant_dias = 31;
    }
    if ((mes == 2)){
        if (((anio % 4 == 0) && (anio % 100 != 0 )) || ((anio % 100 == 0) && ( anio % 400 == 0)))
            cant_dias = 29;
        else{
            cant_dias = 28;
        }
    }
    if (mes == 3){
        cant_dias = 31;
    }
    if (mes == 4){
        cant_dias = 30;
    }
    if (mes == 5){
        cant_dias = 31;
    }
    if (mes == 6){
        cant_dias = 30;
    }
    if (mes == 7){
        cant_dias = 31;
    }
    if (mes == 8){
        cant_dias = 31;
    }
    if (mes == 9){
        cant_dias = 30;
    }
    if (mes == 10){
        cant_dias = 31;
    }
    if (mes == 11){
        cant_dias = 30;
    }
    if (mes == 12){
        cant_dias = 31;
    }
    return cant_dias;
}

int DiasporMes_con_switch(int mes, int anio){ // Cortesia de aria
    int cant_dias;
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            cant_dias = 31;
            break;
        case 4: case 6: case 9: case 11:
            cant_dias = 30;
            break;
        case 2:
            if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
                cant_dias = 29;
            } else {
                cant_dias = 28;
            }
            break;
        default:
            cant_dias = 0; // Para manejar un caso no válido
            break;
    }
    return cant_dias;
}

void main(){
    int mes, anio, cantidad_dias;

    mes = -1; // Inciamos el mes fuera del rango permitido para que vaya a la funcion ValidarMes
    anio = -1; // Inciamos el anio fuera del rango permitido para que vaya a la funcion ValidarAnio

    ValidarMes(&mes);

    ValidarAnio(&anio);

    //cantidad_dias = DiasporMes_sin_switch(mes,anio);
    //printf("La cantidad de dias que tiene el mes %i, del anio %i son %i", mes, anio, cantidad_dias);

    cantidad_dias = DiasporMes_con_switch(mes, anio);
    printf("La cantidad de dias que tiene el mes %i, del anio %i son %i", mes, anio, cantidad_dias);
}