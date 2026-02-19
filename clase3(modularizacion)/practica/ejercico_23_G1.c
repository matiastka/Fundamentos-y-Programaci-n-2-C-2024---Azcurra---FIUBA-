/*
Escribir un programa que simule el proceso de control de peso y cantidad de personas que puede transportar un ascensor.
Vamos a suponer que nuestro ascensor puede soportar un máximo de 400 kg y hasta 6 personas
Nuestra simulación debe proceder del siguiente modo:
- A medida que las personas ingresan al ascensor de a una a la vez, se registra el peso de la persona.
- Supondremos que el ingreso de 0 kg, indica que no hay más personas por subir al ascensor.
- Si en un determinado momento del ingreso de las personas, se supera el peso máximo, el ascensor, advertirá mediante un mensaje, 
que indique que se ha excedido el peso máximo y nuestra simulación terminará.
- De igual modo, si el ascensor detecta que ha subido una séptima persona al ascensor, deberá advertir de esto, y nuestra simulación terminará.
Por último, si habiéndose indicado que todas las personas están a bordo del ascensor y las condiciones establecidas se cumplen, 
el ascensor anunciará "ascensor en movimiento".
*/

# include <stdio.h>

# include <stdbool.h>

int main(){
    int peso, suma, peso_maximo, personas, personas_maximas;
    bool Continuar;

    Continuar = true;
    personas = 0;
    suma = 0;
    peso_maximo = 400;
    personas_maximas = 6;

    while (Continuar){
        printf("Ingrese su peso (en kg) (0 para terminar): ");
        scanf("%i", &peso);

        if (peso == 0){
            Continuar = false;
        }
        else{
            personas = personas + 1;

            if (personas > personas_maximas){
                printf("Se ha excedido la maxima cantidad de personas!\n");
                Continuar = false;
            }

            suma = suma + peso; // La validacion de la suma va despues de verificar la cantidad de personas (gracias Aria)
            
            if (suma > peso_maximo){
                printf("Se ha excedido el peso maximo!\n");
                Continuar = false;
            }
        }
    }
    if ((personas != 0) && (personas <= personas_maximas) && (suma <= peso_maximo)){
        printf("Ascensor en movimiento\n");
        printf("Han subido %i personas con un peso total de: %i", personas, suma);
    }
    else{
        printf("No subio nadie por el ascensor.\n");
    }

    return 0;
}