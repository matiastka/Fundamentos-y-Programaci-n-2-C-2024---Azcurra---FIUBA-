/* Escribir un programa en C, que muestre por pantalla una primer línea que diga:
"Hola Juan Perez", reemplazando Juan Perez por tu nombre y tu apellido; y una segunda línea que diga:
"Tu padrón/legajo fiuba es: 111324", en este caso previamente declara una variable de tipo entero para almacenar el valor que corresponda a tu padrón/legajo, y utilízala dentro de la instrucción que te permite mostrar el mensaje.
stdio.h>
Para la construcción del programa, podés utilizar el ide que prefieras.
Luego, ejecuta el programa y recortá la salida de este, junto con el código, para generar un archivo del tipo jpg, y subilo como resultado de la actividad.*/

#include <stdio.h>

void main()
{
    char s[] = "Matias Tkaczyk";
    int padron = 111517;
    printf("Hola Matias Tkaczyk");
    printf("Tu padron/legajo es:  %i", padron);

    return;
    

}