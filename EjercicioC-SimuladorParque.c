
/*
Un juego de un parque de diversiones, debe realizar los siguientes controles antes de
comenzar a funcionar:
 - Sólo pueden participar quienes tengan una altura entre 1.60 m y 1.90 m
 - El peso total de los participantes no debe superar las 1.5 toneladas
 - La capacidad máxima de participantes es de 20

Debemos programar una simulación de estos controles, para ello nuestro programa
debe solicitar a medida que va a ingresar al juego un nuevo participante, su peso y
su altura.

En caso de detectar que la altura del participante no cumple con lo requerido, se
debe enviar el siguiente mensaje: “Altura del participante fuera de rango permitido”;
y se debe continuar con el siguiente participante.

A medida que se procesan los ingresos de participantes, se debe controlar que el
peso acumulado de los participantes no exceda el total permitido. Si lo excediera,
debe enviar el mensaje: “Peso total excedido, el participante no puede subir”, 
dicho participante será ignorado y se continua solicitando nuevos ingresos.

En el caso que suban personas acumulando un peso exacto de 1500 el juego puede 
comenzar automáticamente.

También a medida que se procesan los ingresos de participantes, se debe controlar
que la cantidad de participantes no exceda el máximo establecido, por ello, si se
alcanza el máximo, se debe informar: “Cantidad máxima de participantes alcanzada”
y el juego podrá comenzar automáticamente si cumple con el resto.

Por último, podría ser que suban menos personas que la capacidad máxima,
entonces, utilizar el último ingreso de los pesos como corte de ingreso de
participantes, considerando que si se ingresa 0 como peso, indica, que no hay más
participantes. 
*/
/*
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
13 - Peso [Kg]: 100 - Altura [cm]: 175 (Se ignora porque se excede el peso máximo del juego)
14 - Peso [Kg]: 0 (Inicia el juego con 12 participantes)

Prueba 4
Participantes:
Suben 20 participantes de 70 Kg y 160 cm 
(Inicia el juego automaticamente por alcanzar la cantidad máxima permitida)
*/
/*
# Supuestos para la resolucion aqui implementada:
# 1) Si se alcanza el maximo de peso permitido y no se llegó a 20 personas, arranca automatico.
# 2) Si se alcanza el maximo de personas y no se llegó al máximo permitido, arranca automatico.
# 3) En el caso de poder quedar excedido de peso se ignora dicho participante.
# 4) En caso de altura fuera de rango, se ignora dicho participante.
# 5) En el caso de ingresar peso 0, arranca automatico.
# 6) Valores ingresados de peso se consideran en unidades de kilogramos.
# 7) Valores ingresados para altura se consideran en unidades de centímetros. 
*/
#include <stdio.h>
#include <stdbool.h>

// Definicion de constantes
#define MAX_PERSONAS 20
#define MAX_PESO 1500
#define MIN_ALTURA 160
#define MAX_ALTURA 190

int main() {
  // Inicializacion de variables
  int personas_total = 0;
  int peso_acumulado = 0;
  int personas_subiendo = true;
  int nuevo_peso, nueva_altura;


  // Iteración hasta detectar condición de corte
  while (personas_subiendo && (personas_total < MAX_PERSONAS) && (peso_acumulado < MAX_PESO)) {
    printf("Nuevo Control\n");
    printf("Indique peso del participante (en Kg): ");
    scanf("%d", &nuevo_peso);

    // En el caso de ser 0 el peso ingresado, se finaliza el ciclo
    if (nuevo_peso == 0) {
      personas_subiendo = false;
    } else {
      printf("Indique altura del participante (en cm): ");
      scanf("%d", &nueva_altura);

      if ((nueva_altura < MIN_ALTURA) || (nueva_altura > MAX_ALTURA)) { // validacion de altura fuera de rango
        printf("Altura del participante fuera de rango permitido\n");
      } else if (peso_acumulado + nuevo_peso > MAX_PESO) { // validacion de peso excedido
        printf("Peso total excedido, el participante no puede subir\n");
      } else { // ingreso de persona al juego
        personas_total += 1;
        peso_acumulado += nuevo_peso;
      }
    }
  }
  
  // Presentar resultado
  if (personas_total >= MAX_PERSONAS) {
    printf("Cantidad máxima de participantes alcanzada\n");
  } else if (peso_acumulado == MAX_PESO) {
    printf("Peso acumulado igual al maximo permitido\n");
  }

  if (personas_total == 1) {
    printf("Juego iniciado con %d participante", personas_total);
  } else {
    printf("Juego iniciado con %d participantes\n", personas_total);
  }

}