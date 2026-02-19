/* 3
Ingresar un número entero y decir si:
a) es par o impar.
b) es mayor, menor o igual a cero
*/
# include <stdio.h>

void main(){
    int numero;
    printf("Ingrese un numero: ");
    scanf("%i", &numero);

    // a) 
    if (numero%2 == 0 && numero >= 0)
        printf("El numero %i es par\n", numero);
    else
        printf("El numero %i es impar\n", numero);
    
    // b)
    if (numero > 0)
        printf("El numero %i es mayor a 0", numero);
    else{ // Las llaves estan demas pero las pongo por prolijidad mia
        if (numero < 0)
            printf("El numero %i es menor a 0", numero);
        else 
            printf("El numero %i es igual a 0", numero);
    }

    return;
}


