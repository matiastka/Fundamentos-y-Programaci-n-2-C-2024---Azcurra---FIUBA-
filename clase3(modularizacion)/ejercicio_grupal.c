/*1. Se tiene una lista de casos confirmados de coronavirus por cada país se pide:
Indicar cual es el promedio mundial
Cantidad de Casos mundiales
Que cantidad de casos tiene el país con menos casos
Que cantidad de casos tiene el país con más casos

EL usuario ingresa la cantidad de casos para cada pais
*/

int main(){
    // Forma con for
    /*
    int casos, cant_paises, mayor_casos, contador, suma;
    long long menor_casos;
    float promedio;
    contador = 0;
    menor_casos = 7951000000; // Con esto todos los casos ingresados van a ser menor entonces permite que se guarden
    mayor_casos = 0;
    promedio = 0;
    suma = 0;

    printf("Ingrese la cantidad de paises con casos confirmados: ");
    scanf("%i", &cant_paises);

    if (cant_paises <= 0){
        printf("El promedio de casos mundiales es: %f\n", promedio);
        printf("La cantidad de casos mundiales es: %i\n", 0);
        printf("La cantidad de casos tiene el pais con menos casos es: %i\n", 0);
        printf("La cantidad de casos tiene el pais con mas casos es: %i\n", mayor_casos);
    }
    else{
    for (contador = 0; contador < cant_paises; contador++){
        printf("Ingrese los casos: ");
        scanf("%i", &casos);

        if (casos >= mayor_casos) {
            mayor_casos = casos;
        }
        if (casos <= menor_casos){
            menor_casos = casos;
        }
        suma = suma + casos;
    }
    promedio = (float)suma / cant_paises; // Por las dudas casteamos suma a float
    printf("El promedio de casos mundiales es: %f\n", promedio);
    printf("La cantidad de casos mundiales es: %i\n", cant_paises);
    printf("La cantidad de casos tiene el pais con menos casos es: %i\n", menor_casos);
    printf("La cantidad de casos tiene el pais con mas casos es: %i\n", mayor_casos);
    }
    */
    
    // forma while
    
    int casos, suma, menor_casos, mayor_casos, cant_casos;
    float promedio;

    promedio = 0;
    suma = 0;
    cant_casos = 0;
    printf("Ingrese casos por pais (-1 para terminar): ");
    scanf("%i", &casos);
    menor_casos = casos;
    mayor_casos = casos;

    if (casos < 0){
        printf("El promedio de casos mundiales es: %f\n", promedio);
        printf("La cantidad de casos mundiales es: %i\n", cant_casos);
        printf("La cantidad de casos tiene el pais con menos casos es: %i\n", 0);
        printf("La cantidad de casos tiene el pais con mas casos es: %i\n", 0);
    }

    while (casos >= 0){
        suma = suma + casos;
        if (casos > 0){
            cant_casos = cant_casos + 1;
        }
        if (casos >= mayor_casos){
            mayor_casos = casos;
        }
        if (casos <= menor_casos && casos > 0){
            menor_casos = casos;
        }
        printf("Ingrese casos por pais (-1 para terminar): ");
        scanf("%i", &casos);
    }
    promedio = (float) suma / cant_casos;
    printf("El promedio de casos mundiales es: %f\n", promedio);
    printf("La cantidad de casos mundiales es: %i\n", cant_casos);
    printf("La cantidad de casos tiene el pais con menos casos es: %i\n", menor_casos);
    printf("La cantidad de casos tiene el pais con mas casos es: %i\n", mayor_casos);

    return 0;
}