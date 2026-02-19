# include <stdio.h>

void main(){
    int x,y;

    printf("Valor de X: ");
    scanf("%i", &x);
    printf("valor de Y: ");
    scanf("%i", &y);

    if (x < y)
        {
            printf("x: %i       y: %i", x, y);
            printf("x es menor a Y\n");
        }
        
    else
        if (x > y)
            printf("X es mayor a Y\n");
        else
            printf("X es igual a Y\n");
    return;
}