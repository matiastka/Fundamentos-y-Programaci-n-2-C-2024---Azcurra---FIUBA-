/*
Se tiene un listado de alumnos que consiste en número de padrón y 4 notas por
alumno. Informar el mayor y el menor promedio registrado junto con el número de
padrón del alumno, suponiendo que ambos son únicos.
*/

// Se podria haber hecho con un doble for (uno para recorrer la cantidad de alumnos y otro para recorrer las notas)

# include <stdio.h>

# include <stdbool.h>

void validar_nota(int *nota){ //Cortesia de Aria
    while (*nota < 0 || *nota >= 11){
        printf("Ingreso incorrecto de la nota\nIngrese su nota: ");
        scanf("%i", nota); // El scanf de funciones por referencia no necesita ampersand (&)
    }
}

int main(){
    int padron, nota_1, nota_2, nota_3, nota_4, mayor_padron, menor_padron, suma;
    float promedio, mayor_promedio, menor_promedio;
    bool Continuar;

    Continuar = true;
    mayor_padron = 0;
    menor_padron = 0;
    mayor_promedio = -1; // Menor valor posible que no puede ser
    menor_promedio = 11; // Mayor valor posible que no puede ser
    suma = 0;
    promedio = 0;

    while (Continuar) {
        printf("Ingrese su padron (0 para terminar): ");
        scanf("%i", &padron);
        
        if (padron == 0){
            Continuar = false;
        }
        else{
            printf("Ingrese la 1er nota: ");
            scanf("%i", &nota_1);
            validar_nota(&nota_1);

            printf("Ingrese la 2da nota: ");
            scanf("%i", &nota_2);
            validar_nota(&nota_2);

            printf("Ingrese la 3ra nota: ");
            scanf("%i", &nota_3);
            validar_nota(&nota_3);

            printf("Ingrese la 4ta nota: ");
            scanf("%i", &nota_4);
            validar_nota(&nota_4);
            
            suma = (nota_1 + nota_2 + nota_3 + nota_4);

            promedio = ((float)suma)/4.0; //el 4.0 lo castea a float tambien

            if (promedio > mayor_promedio){ // Los promedios_mayores son mayores su comparacion sino es confuso (gracias aria)
                mayor_promedio = promedio;
                mayor_padron = padron;
            }
            if (promedio < menor_promedio){ // Los promedios_menores son menores su comparacion sino es confuso (gracias aria)
                menor_promedio = promedio;
                menor_padron = padron;
            }
        }
    }
    
    if (Continuar == true){
        printf("No se ingresaron datos validos.");
    }
    else{    
        printf("El mayor promedio fue %f del padron: %i\n", mayor_promedio, mayor_padron);
        printf("El menor promedio fue %f del padron: %i", menor_promedio, menor_padron);
    }

    return 0;
}