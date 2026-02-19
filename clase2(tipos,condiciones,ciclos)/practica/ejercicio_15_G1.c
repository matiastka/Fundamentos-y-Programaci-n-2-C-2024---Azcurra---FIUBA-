/*Dada una serie de números ingresados de a uno.
Indicar mayor, menor y promedio de la serie.
El ingreso de números finaliza cuando el usuario ingresa 0.
*/

# include <stdio.h>

void main(){
    int numero, mayor, menor, suma, cantidad_total;
    float promedio;

    promedio = 0;
    suma = 0;
    cantidad_total = 0;

    printf("Ingrese una serie de numeros (0 para finalizar): ");
    scanf("%i", &numero);
    mayor = numero;
    menor = numero;

    while (numero != 0){
        if (numero >= mayor){
            mayor = numero;
        }
        if (numero <= menor){
            menor = numero;
        }
        suma = numero + suma;
        cantidad_total = cantidad_total + 1;

        printf("Ingrese una serie de numeros (0 para finalizar): ");
        scanf("%i", &numero);
    }
    promedio = (float)suma/cantidad_total; // Hay que castear a float suma o cantidad_total sino se rompe en algunas ocaciones (gracias Aria!)
    printf("El numero mayor fue %i\nEl numero menor fue %i\nEl promedio es: %f",mayor, menor, promedio);

    return;
}