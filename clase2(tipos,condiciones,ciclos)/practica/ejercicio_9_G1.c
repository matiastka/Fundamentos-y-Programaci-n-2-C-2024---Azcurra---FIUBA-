/*Solicitar al usuario el ingreso de una temperatura (puede tener decimales por
ejemplo 24.5) y la unidad en la que se encuentra (siendo solo un carácter F ó C).
Luego el programa debe mostrar la temperatura ingresada, convertida en la otra
unidad.
La relación entre temperaturas Celsius y Fahrenheit está dada por la fórmula:
C=5.0 / 9.0 * (F − 32)
*/

# include <stdio.h>

void main(){
    char unidad;
    float temperatura, pasaje_temperatura;

    do {   // Validamos que la unidad sea C o F (variando por sus minusculas)
        printf("Ingrese la unidad (C o F): "); // Primero ingresamos el char porque sino no lo saltea por lo que sea números (¿bug de C?)
        scanf("%c", &unidad);
    } while ( unidad != 'C' && unidad != 'c' && unidad != 'F' && unidad != 'f'); // Tiene ser falso las 4 condiciones a la vez
    
    printf("Ingrese una temperatura: ");
    scanf("%f", &temperatura);

    if (unidad == 'C' || unidad == 'c'){
        pasaje_temperatura = ((9 * temperatura)/5) + 32;
        printf("La temperatura en Celsius (%f) a Fahrenheit es: %f", temperatura, pasaje_temperatura);
    }
    if (unidad == 'F' || unidad == 'f'){
        pasaje_temperatura = (5 * (temperatura - 32))/9;
        printf("La temperatura en Fahrenheit (%f) a Celsius es: %f", temperatura, pasaje_temperatura);
    }

    return;
}