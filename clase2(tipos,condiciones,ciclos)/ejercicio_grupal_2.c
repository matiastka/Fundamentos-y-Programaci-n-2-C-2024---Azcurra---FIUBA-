/* 2
Ingresar el radio de una esfera y calcular el volumen.
*/
# include <stdio.h>
# define PI 3.1415

void main(){
    int radio, radio_al_cubo;
    float volumen; 

    printf("Ingrese el radio: ");
    scanf("%i", &radio);

    radio_al_cubo = radio * radio * radio;

    volumen = (4 * PI * (radio_al_cubo))/3; // Lenguaje de mierda no toma (4/3) xddddd

    printf("El volumen es: %f", volumen);

    return;
}
