# include <stdio.h>

void main(){
    int edad;

    printf("Edad: ");
    scanf("%i", &edad);

    if (edad < 18)
        printf("Ud. es menro a 18");
    else
        printf("Ud. es mayor a 18");

    return; 
}