// Uso de strcmp: Comparar 2 cadenas. Esta funcion ya esta incluida como base de C (Aunque mi vsc me sugiere que este)

# include <stdio.h>

void main(){
    char cadena1[10] = "Hola";
    char cadena2[] = "Mundo";

    // Comparo dos cadenas usando strcmp(cadena1, cadena2)
    // strcmp devuelve positivo cuando cadena1 es mayor a cadena2, 0 cuando son iguales y negativo cuando cadena1 es menor a cadena2 (por orden alfabetico)
    if (strcmp(cadena1, cadena2) == 0){
        printf("Las cadenas 1 y 2 son iguales\n\n");
    }
    else{
        if(strcmp(cadena1, cadena2) > 0){
            printf("La cadena 1 es mayor que la cadena2\n\n");
        }
        else{
            printf("La cadena 1 es menor que la cadena2\n\n");
        }
    }
    
    return;
}