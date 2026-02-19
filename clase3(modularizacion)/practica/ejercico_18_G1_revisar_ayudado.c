/*
18) Se realiza una encuesta para estimar el grado de aceptación de los productos x e y en
el mercado. A cada encuestado se le pregunta si consume el producto x y si consume el
producto y. La respuesta puede ser sí o no.
Se pide calcular e informar el porcentaje de consumidores de:
a) del producto x
b) del producto y
c) del producto x solamente
d) del producto y solamente
e) de ambos productos
f) de ninguno de los productos
*/

# include <stdio.h>

# include <stdbool.h>

int main(){ // Revisar correción de azcurra
    char consume_x, consume_y, encuestados;
    int contador, cantidad_consume_x, cantidad_consume_y, cantidad_consume_solo_x, cantidad_consume_solo_y, cantidad_consume_ambos, cantidad_no_consume, porcentaje_solo_x, porcentaje_solo_y, porcentaje_ambos, porcentaje_ninguno, porcentaje_x, porcentaje_y;
    bool Continuar;

    Continuar = true;
    cantidad_consume_x = 0;
    cantidad_consume_y = 0;
    cantidad_consume_solo_x = 0;
    cantidad_consume_solo_y = 0;
    cantidad_consume_ambos = 0;
    cantidad_no_consume = 0;


    while (Continuar){
        printf("Consume x? (s para si, n para no): ");
        scanf(" %c", &consume_x); // Hay que ponerle un espacio antes del %c porque sino no lee correctamente el proximo input (C es una mierda) (gracias Aria)
        printf("Consume y? (s para si, n para no): ");
        scanf(" %c", &consume_y);

        if (consume_x == 's'){
            cantidad_consume_x = cantidad_consume_x + 1;
        }
        if (consume_y == 's'){
            cantidad_consume_y = cantidad_consume_y + 1;
        }

        if ((consume_x == 's') && (consume_y == 's')){
            cantidad_consume_ambos = cantidad_consume_ambos + 1;
        }
        else{
            if ((consume_x == 's') && (consume_y == 'n' )){
                cantidad_consume_solo_x = cantidad_consume_solo_x + 1;
            }
            else{
            if ((consume_x == 'n') && (consume_y == 's' )){
                cantidad_consume_solo_y = cantidad_consume_solo_y + 1;
            }
            else{
                cantidad_no_consume = cantidad_no_consume + 1;
            }
            }
        }
        
        contador = contador + 1;
        
        printf("Hay mas encuestados? (s para si, n para no): ");
        scanf(" %c", &encuestados);
        if (encuestados == 'n'){
            Continuar = false;
        }
    }
    porcentaje_x = (100 * cantidad_consume_x)/contador;
    porcentaje_y = (100 * cantidad_consume_y)/contador;
    porcentaje_ambos = (100 * cantidad_consume_ambos)/contador;
    porcentaje_solo_x = (100 * cantidad_consume_solo_x)/contador;
    porcentaje_solo_y = (100 * cantidad_consume_solo_y)/contador;
    porcentaje_ninguno = (100 * cantidad_no_consume)/contador;
    printf("El porcentaje del consumo del producto_x: %i porciento\n", porcentaje_x);
    printf("El porcentaje del consumo del producto_y: %i porciento\n", porcentaje_y);
    printf("El porcentaje del consumo de ambos productos: %i porciento\n", porcentaje_ambos);
    printf("El porcentaje del consumo de solamente el producto_x: %i porciento\n", porcentaje_solo_x);
    printf("El porcentaje del consumo de solamente el producto_y: %i porciento\n", porcentaje_solo_y);
    printf("El porcentaje de ningun consumo: %i porciento", porcentaje_solo_y);

    return 0;
}