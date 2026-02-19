
/*
Ingresar cantidad de Ml3 que llovió en la semana de lunes a domingo de 0 a 23 Hs.
1. Calcular el promedio llovido por cada día.
2. Calcular el promedio llovido por cada hora.
3. Mostrar el dia y hora en que mas llovió.
*/

#include <stdio.h>
#define MAX_DIA 7

#define MAX_HORA 24
typedef int TMat[MAX_DIA][MAX_HORA]  ; // se hizo pensando las columnas y despues las filas
TMat Mat;

void CargarDatos(TMat Mat){
  int i, j, num;
  printf("Ingrese los datos:\n");

  for (i=0;i<MAX_DIA;i++){ //recorrido columnas por filas
    printf("Del dia %i\n",i);
    for (j=0; j<MAX_HORA; j++){
      printf("De la hora %i\n",j);
      scanf("%4i", &num);
      Mat[i][j]=num;
    }
  } 
}

void PromedioDia(TMat mat){
  int i, j;
  float promedio;

  for (i = 0; i < MAX_DIA; i++){
    promedio = 0; // Hay que incializarlo por cada dia (no fuera del for del dia) y en 0. Esto es cuando el 1er uso es para consultar el valor o para calcular algo. Entonces va a dentro del for
    for (j = 0; j < MAX_HORA; j++){
      promedio += mat[i][j];
    }
    promedio /= MAX_DIA; // Cuando termina el dia se lo calcula
    printf("El promedio del dia %i es: %f", i, promedio);
  }
}

void PromedioHora(TMat mat){
  int i,j;
  float suma, promedio;
  for (j = 0; j < MAX_HORA; j++){ // Se hizo al reves la iteracion se hace por hora y por dia
    suma = 0;
    for (i = 0; i < MAX_DIA; i++){
      suma += mat[i][j];
    }
  promedio = suma/MAX_DIA;
  printf("El proemdio de la hora %i es: %f\n", j, promedio);
  }
}

void DiaHoraMasLlovio(TMat mat){
  int i, j, max, dia, hora;
  dia = 0;
  hora = 0;
  max = mat[0][0];

  for (i = 0; i <MAX_DIA; i++){
    for(j = 0; j < MAX_HORA; j++){
      if (mat[i][j] > max){
        max = mat[i][j];
        dia = i;
        hora = j;
      }
    }
  }
  printf("Dia: %i, Hora: %i, Max: %i", dia, hora, max);
}

void MostrarDiayHora(TMat Mat){
  int cant_mililitros, i, j, dia, hora;
  cant_mililitros = 0;
  dia = 0;
  hora = 0;
  
  for (i = 0; i < MAX_DIA; i++){
    for (j = 0; j < MAX_HORA; j++){
      if (Mat[i][j] > cant_mililitros){
        cant_mililitros = Mat[i][j];
        dia = i;
        hora = j;
      }
    }
  }
  printf("El dia es: %i\nLa hora es: %i", dia, hora);
}

void main(){
  TMat Mat;
  CargarDatos(Mat);
  PromedioHora(Mat);
  PromedioDia(Mat);
  DiaHoraMasLlovio(Mat);
  MostrarDiayHora(Mat);
}