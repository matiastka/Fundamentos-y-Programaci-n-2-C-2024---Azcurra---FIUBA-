#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MF 20
#define NO_ENCONTRADO -1

typedef int tvector[MF];

int busqueda_secuencial(tvector valores, int tamanio, int buscado) { // Sirve para arreglos no ordenados
  int i = 0, posicion = -1;
  bool encontrado = false; 
  
  // mientras no se encontro y restan elementos por comparar
  while (encontrado == false && i<tamanio) {
    if (valores[i] == buscado) {
        encontrado = true;
        posicion = i;
    }
    i++; 
  }
  
  return posicion;
}

int busqueda_binaria(tvector valores, int tamanio, int buscado) { // Sirve para arreglos ordenados
  int primer_posicion, ultima_posicion, posicion_del_medio, posicion;
  bool terminado; 
  
  // inicializaciones
  primer_posicion = 0;
  ultima_posicion = tamanio-1; 
  terminado = false;

  while (terminado == false) {
      if ((buscado < valores[primer_posicion]) || (buscado > valores[ultima_posicion])) { // Se fija si esta dentro del rango del vector
          terminado = true; // NO ESTA => FIN DE LA BUSQUEDA
          posicion = -1;
      } else {
          posicion_del_medio = (primer_posicion + ultima_posicion)/2;

          if (valores[posicion_del_medio] == buscado) {
            terminado = true; // ENCONTRADO => FIN DE LA BUSQUEDA
            posicion = posicion_del_medio;
          } else if(buscado > valores[posicion_del_medio]) {
            primer_posicion = posicion_del_medio + 1;
          } else {
            ultima_posicion = posicion_del_medio - 1;
          }
      }
  }

  return posicion;
}

void mostrar_resultado(char *tipo, int dato, int pos) {
  if (pos == -1) {
    printf("Valor %d buscado x BUSQUEDA %s no encontrado \n", dato, tipo);
  } else {
    printf("Valor %d buscado x BUSQUEDA %s encontrado en posicion %d \n", dato, tipo ,pos);
  }
}

int main() {
  tvector vector = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190};
  int dato, n = MF;
  int pos; 

  printf("Ingrese dato a buscar:");
  scanf("%d", &dato);

  /* BUSQUEDA SECUENCIAL */
  pos = busqueda_secuencial(vector, n, dato);
  mostrar_resultado("SECUENCIAL", dato, pos);

  /* BUSQUEDA BINARIA */
  pos = busqueda_binaria(vector, n, dato);
  mostrar_resultado("BINARIA", dato, pos);

  system("PAUSE");
  return 0;
}