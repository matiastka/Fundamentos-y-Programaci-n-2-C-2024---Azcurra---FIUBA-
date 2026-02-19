/*
17) Generar un dibujo por pantalla con el siguiente patrón solicitando al usuario la altura.
Ejemplo: altura=5 debe dibujar por pantalla:
*
**
***
****
*****
*/

# include <stdio.h>

int main(){
    int altura, contador1, contador2;
    
    printf("Ingrese la altura: ");
    scanf("%i", &altura);

    for (contador1 = 0; contador1 < altura; contador1++){ // Este ciclo se encarga de imprimir las lineas (las debe imprimir despues de los *)
        for (contador2 = 0; contador2 <= contador1; contador2++){ // Este ciclo se encarga de imprimir los *
            printf("*");
        }
        printf("\n");
    }
}