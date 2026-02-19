/*Calcular y mostrar la suma de los n primeros números naturales. Siendo n un número ingresado por el usuario.
*/

# include <stdio.h>

void main(){
    int numero, suma;
    do // Validamos que sea un número positivo
    {
        printf("Ingrese un numero positivo: ");
        scanf("%i", &numero);
    } while (numero<0);

    suma = (numero * (numero + 1))/2;
    printf("La suma es: %i", suma);
    
    /* uso for
    int numero, contador, suma;
    suma = 0;
    do // Validamos que sea un número positivo
    {
        printf("Ingrese un numero natural: ");
        scanf("%i", &numero);
    } while (numero<0);

    for (contador = 1; contador < (numero+1); contador++){
        suma = suma + contador;
    }
    printf("La suma es: %i", suma);
    */
    return;

}