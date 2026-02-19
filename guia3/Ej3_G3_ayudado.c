/*
Escribir un programa que solicite el ingreso de valores, que representarán una
cantidad de segundos. El programa deberá informar al usuario, el equivalente en
días, horas, minutos y segundos.
Se debe validar que el valor ingresado sea entero y positivo, de lo contrario,
deberá mostrarse el mensaje: “Valor ingresado inválido”.
El ingreso de valores finaliza cuando el usuario ingrese como valor, 0.
*/

# include <stdio.h>
# include <stdbool.h>

void ValidarIngreso(int *valor){
    bool continuar;
    continuar = true;
    while (continuar){ 
        printf("Ingrese una cantidad en segundos (entero y positivo) (0 para terminar): ");
        scanf("%i", valor);
        if (*valor >= 0){
            continuar = false;
        }
        else{
            printf("Valor Ingresado invalido\n");
        }
    }
}

void CantidadSegundos(int valor){
    int dias, horas, minutos, segundos;
    
    ValidarIngreso(&valor); // Validamos antes de ingresar un valor
    while (valor != 0){
        dias = valor / 86400; // 1 día = 86400 segundos
        horas = (valor / 3600); // 1 hora = 3600 segundos
        minutos = (valor / 60); // 1 minuto = 60 segundos
        segundos = valor; // Resto de segundos
        printf("Esa cantidad de segundos tiene:\n%i dias\n%i horas\n%i minutos\n%i segundos\n", dias, horas, minutos, segundos);
        ValidarIngreso(&valor); // Validamos antes de volver a empezar
    }
}

void main(){
    int valor;
    valor = -1;

    CantidadSegundos(valor);
}