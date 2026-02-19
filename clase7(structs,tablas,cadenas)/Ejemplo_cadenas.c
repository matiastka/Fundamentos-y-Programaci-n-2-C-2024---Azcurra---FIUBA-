# include <stdio.h>
# include <string.h>

int main(){
    // 2 Formas para definir una variable de tipo cadena
    char cadena_hola[] = "Hola"; // Forma 2: Declarativa (ya se le da un valor, donde su Maximo de bytes es el tamaño del string)
    char nombre[15]; // Forma 1

    printf("Muestra Cadena: %s\n", cadena_hola);
    printf("Muestra Cadena: %s\n", nombre);

    // Ingresar cadenas (forma con scanf) [Como las cadenas son un arreglo van sin &]:
    printf("\nIngreso de Cadenas\nIngrese un nombre: ");
    scanf("%s", nombre);
    printf("Lo que usted ingreso es: %s\n", nombre);


    // Asignar una cadena a otra ya definida (strcpy):
    printf("\nAsignacion de Cadenas\n");
    strcpy(nombre, cadena_hola); // Asigna a la cadena nombre el valor de la cadena cadena_hola (no importa que ingresa el usario, terminará siendo "Hola")
    printf("El resultado de asignar a la cadena nombre el valor de la cadena cadena_hola es: %s\n", nombre);

    // Comparar 2 cadenas (strcmp) [Si las 2 son iguales devuelve 0; si la 1ra es mayor devuelve un valor positivo; si la 1ra es menor devuelve un valor negativo]
    printf("\nComparacion de Cadenas\n");
    if (strcmp(nombre, cadena_hola) == 0){
        printf("Las cadenas 1 y 2 son iguales\n\n");
    }
    else{
        if(strcmp(nombre, cadena_hola) > 0){
            printf("La cadena 1 es mayor que la cadena2\n\n");
        }
        else{
            printf("La cadena 1 es menor que la cadena2\n\n");
        }
    }

}