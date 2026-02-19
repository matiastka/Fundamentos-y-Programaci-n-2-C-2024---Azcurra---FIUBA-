/*
Se tiene un registro de la temperatura por hora (0 a 23) por día (1 a n) de un mes, ordenada cronológicamente. 
Se pide: 
a) Ingresar el número de mes para conocer la cantidad de días registrados. 
b) Cargar el listado en una matriz e informarla en forma bidimensional. 
c) Informar además la máxima y la mínima temperatura por día, la máxima y la mínima temperatura del mes.
*/

# include <stdio.h>

# define MAX_HORA 24

# define MAX_DIA 31

void ValidarMes(int *mes){
    while ((*mes < 1) || (*mes > 12)){
        printf("Ingrese el numero del mes: ");
        scanf("%i", mes);
    }
}

void DiasporMes(int mes, int *cant_dias){
    if (mes == 2){
        *cant_dias = 28;
    }
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12 ){
        *cant_dias = 31;
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
        *cant_dias = 30;
    }
}  

void CargarDatos(float matriz[MAX_HORA][MAX_DIA], int cant_dias){
    int contador_1, contador_2;

    for (contador_2 = 0; contador_2 < cant_dias; contador_2++){ // Para que sea logico 1ro se recorren los dias (columnas) y despues las horas (filas). Va hasta #dias porque quiero solamente hasta los dias que tiene el mes (ML)
        for (contador_1 = 0; contador_1 < MAX_HORA; contador_1++){
            printf("Ingrese el valor de la temperatura en la hora %i y el dia %i: ", contador_1, contador_2+1);
            scanf("%f", &matriz[contador_1][contador_2]);
        }
    }
}

void MostrarDatos(float matriz[MAX_HORA][MAX_DIA], int cant_dias){
    int contador_1, contador_2;

    for (contador_2 = 0; contador_2 < cant_dias; contador_2++){ // Para que sea logico 1ro se recorren los dias y despues las horas (empezamos por las columnas y desp por filas)
        printf("\n|");
        for (contador_1 = 0; contador_1 < MAX_HORA; contador_1++){
            printf("%f ", matriz[contador_1][contador_2]);
        }
        printf("|");
    }
}

void MostrarTemperaturaMaximayMinimaPorDia(float matriz[MAX_HORA][MAX_DIA], int cant_dias){
    int contador_1, contador_2;
    float maxima, minima;

    for (contador_2 = 0; contador_2 < cant_dias; contador_2++){
        maxima = matriz[0][0]; // Incializamos ambos valores en la 1er posicion de la matriz (reinicia el valor cada vez que empieza un dia)
        minima = matriz[0][0];
        for (contador_1 = 0; contador_1 < MAX_HORA; contador_1++){
            if (matriz[contador_1][contador_2] < minima){
                minima = matriz[contador_1][contador_2];
            }
            if (matriz[contador_1][contador_2] > maxima){
                maxima = matriz[contador_1][contador_2];
            }
        }
        printf("En el dia %i: \nHizo una temperatura minima de %f y maxima de %f ", contador_2+1, minima, maxima);
    }
}

void MostrarTemperaturaMaximayMinimaPorMes(float matriz[MAX_HORA][MAX_DIA], int cant_dias){
    int contador_1, contador_2;
    float maxima, minima;

    // Incializamos las variables max y min fuera del ciclo porque no queremos que se reincie su valor sino que se verifique hasta el final
    maxima = matriz[0][0];
    minima = matriz[0][0];

    for (contador_2 = 0; contador_2 < cant_dias; contador_2++){
        for(contador_1 = 0; contador_1 < MAX_HORA; contador_1++){
            if (matriz[contador_1][contador_2] < minima){
                minima = matriz[contador_1][contador_2];
            }
            if (matriz[contador_1][contador_2] > maxima){
                maxima = matriz[contador_1][contador_2];
            }
        }
    }
    printf("\nEn el mes, la temperatura minima fue %f y la maxima fue %f ", minima, maxima);
}

void main(){
    // a)
    int numero_mes, cant_dias;

    numero_mes = -1; // Incializamos el mes fuera del rango permitido

    ValidarMes(&numero_mes);

    DiasporMes(numero_mes, &cant_dias);

    // b)

    float matriz[MAX_HORA][MAX_DIA];
    
    CargarDatos(matriz, cant_dias);

    MostrarDatos(matriz, cant_dias);


    // c)
    MostrarTemperaturaMaximayMinimaPorDia(matriz, cant_dias);
    
    MostrarTemperaturaMaximayMinimadelMes(matriz, cant_dias);

}