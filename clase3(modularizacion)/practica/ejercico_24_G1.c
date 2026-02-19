/*
Un juego de un parque de diversiones, debe realizar los siguientes controles antes de comenzar a funcionar:
- Sólo pueden participar quienes tengan una altura entre 1.60 m y 1.90 m
- El peso total de los participantes no debe superar las 1.5 toneladas
- La capacidad máxima de participantes es de 20
Debemos programar una simulación de estos controles, para ello nuestro programa 
debe solicitar a medida que va a ingresar al juego un nuevo participante, su peso y su altura.
En caso de detectar que la altura del participante no cumple con lo requerido, se debe
enviar el siguiente mensaje: “Altura del participante fuera de rango permitido”; y se debe
continuar con el siguiente participante.
A medida que se procesan los ingresos de participantes, se debe controlar que el peso
acumulado de los participantes no exceda el total permitido. Si lo excediera, debe enviar el
mensaje: “Peso total excedido, el participante no puede subir”, dicho participante será
ignorado y se continúa solicitando nuevos ingresos.
En el caso que suban personas acumulando un peso exacto de 1500 el juego puede comenzar automáticamente.
También a medida que se procesan los ingresos de participantes, se debe controlar que la
cantidad de participantes no exceda el máximo establecido, por ello, si se alcanza el
máximo, se debe informar: “Cantidad máxima de participantes alcanzada” y el juego podrá
comenzar automáticamente si cumple con el resto.
Por último, podría ser que suban menos personas que la capacidad máxima, entonces,
utilizar el último ingreso de los pesos como corte de ingreso de participantes, considerando
que si se ingresa 0 como peso, indica, que no hay más participantes.
Pruebas a considerar:
Prueba 1
Participantes:
1 - Peso [Kg]: 90 - Altura [cm]: 180
2 - Peso [Kg]: 110 - Altura [cm]: 170
3 - Peso [Kg]: 90 - Altura [cm]: 150 (Se ignora altura no permitida)
4 - Peso [Kg]: 0 (Inicia el juego con 2 participantes)
Prueba 2
Participantes:
1 - Peso [Kg]: 60 - Altura [cm]: 160
Luego suben 12 participantes de 120 Kg y 190 cm
(Inicia el juego automaticamente por alcanzar el peso máximo)
Prueba 3
Participantes:
1 - Peso [Kg]: 100 - Altura [cm]: 175
Luego suben 11 participantes de 120 Kg y 190 cm
13 - Peso [Kg]: 100 - Altura [cm]: 175 (Se ignora porque se excede el peso máximo del
juego)
14 - Peso [Kg]: 0 (Inicia el juego con 12 participantes)
Prueba 4
Participantes:
Suben 20 participantes de 70 Kg y 160 cm
(Inicia el juego automaticamente por alcanzar la cantidad máxima permitida)

*/

# include <stdio.h>

# include <stdbool.h>

int main(){
    int peso, capacidad_maxima, altura, peso_maximo, suma_de_pesos, participante;
    bool Continuar;

    Continuar = true;
    capacidad_maxima = 20;
    peso_maximo = 1500;
    suma_de_pesos = 0;
    participante = 0;

    while (Continuar){
        printf("Ingrese su peso (en kg) (0 para finalizar): ");
        scanf("%i", &peso);
        if (peso == 0){
            Continuar = false;
        }
        else{
            printf("Ingrese su altura (en cm): ");
            scanf("%i", &altura);
            if (altura > 190 || altura < 160){
                printf("Altura del participante fuera del rango permitido\n");
                continue; // Si esta por fuera del rango permitido ignora al participante (se usa continue para que salte este ciclo)
            }

            // Forma 1 para hacer la suma de pesos y su validacion:
            suma_de_pesos = suma_de_pesos + peso; 
            printf("suma de pesos: %i\n", suma_de_pesos);

            if (suma_de_pesos > peso_maximo){ // Otra alternativa es hacer suma_de_pesos + pesos > peso maximo y luego sumar el peso (ver Aria en "Ejercicios de C (casi toda la guia 1)")
                printf("Peso total excedido, el participante no puede subir\n");
                suma_de_pesos = suma_de_pesos - peso; // Restamos el peso que se sumo habiendo superado la capacidad máxima, para que pueda subir otro más (en duda)
                continue;
            }
            /* Forma 2:
            if (suma_de_pesos + peso > peso_maximo) {
                printf("Peso total excedido, el participante no puede subir.\n");
                continue; // Ignora al participante
            }

            // Sumar peso
            suma_de_pesos += peso;      
            */
            participante = participante + 1;
            printf("Participantes: %i\n", participante);

            if ((suma_de_pesos == peso_maximo) && (participante <= capacidad_maxima)){
                Continuar = false;
            }

            if (participante == capacidad_maxima){
                printf("Cantidad maxima de participantes alcanzada\n");
                if (suma_de_pesos <= peso_maximo){
                    Continuar = false;
                }
            }

        }

    }
    if (participante != 0){
        printf("Comienza el juego\n");
        if (suma_de_pesos == peso_maximo){
            printf("Inicia el juego por alcanzar el peso maximo");
        }
        if (participante == capacidad_maxima){
            printf("Inicia el juego automaticamente por alcanzar la cantidad maxima permitida");
        }
        if ((suma_de_pesos != peso_maximo) && (participante != capacidad_maxima)){
            printf("Inicia el juego con %i participantes", participante);
        }
    }
    else{
        printf("No subio nadie");
    }


    return 0;
}