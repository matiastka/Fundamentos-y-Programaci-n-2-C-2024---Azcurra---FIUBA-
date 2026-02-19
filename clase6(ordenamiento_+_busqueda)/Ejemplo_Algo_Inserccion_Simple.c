#include<stdio.h>
#include<stdlib.h>

#define MF 5

typedef int tvector[MF];

void mostrar(tvector vector, int n)
{
  int k;    
  for(k=0; k<n; k++)
    printf("%d ",vector[k]);
}


void ordenar(tvector vector, int n)
{
  int k, i, aux;
  // método inserción
   for (k=1; k<n; k++) {
      aux = vector[k];
      i = k-1;
      // mientras no haya llegado al final
      // y aux este fuera de lugar
      while ((i>=0) && (aux < vector[i])) {                      
        vector[i+1] = vector[i];      // desplazo vector[i]
         i=i-1;                       // desplazo indice
      }
      vector[i+1] = aux;  //coloco aux en su lugar
   }
}

void ordenar_con_seguimiento(tvector vector, int n)
{
   int k, i, aux;

   for (k=1; k<n; k++) {
      aux = vector[k];
      printf("\nElemento a insertar k= %d aux= %d  \n",k,aux);
     
      i=k-1;
      printf("El valor de i es: %i\n",i);
      // mientras no haya llegado al final
      // y aux este fuera de lugar
      while  ((i>=0) && (aux < vector[i])) {              
        vector[i+1] = vector[i];      // desplazo vector[i]
         i=i-1;                       // desplazo indice

         mostrar(vector, MF);
         printf("   DESPLAZAMIENTO\n");
      }
      vector[i+1] = aux;    //coloco aux en su lugar

      mostrar(vector, MF);
      printf("   INSERTO\n");
   /*
    for (k=1; k < ML; k++){ // k empieza en la posicion siguiente a i (como k = 1, siempre empieza en la 2da posicion)
        aux = vector[k]; // Guardo en aux, el valor de la proxima posicion (k)
        i = k - 1; // Defino a i como la anterior posicion a k (como k = 1 --> i = 1-1 = 0 entonces siempre empieza en la 1ra posicion)
        while ((i>=0) && (aux < vector[i])){ // Mientras el valor de la proxima posicion (aux) sea menor al valor del vector en la posicion anterior (i) y la anterior posicion sea mayor/igual a a la 1ra
            vector[i+1] = vector[i]; // Guardamos el valor del vector en la proxima posicion (k), el valor del vector en la posicion anterior (i)
            i = i-1; // Restamos una posicion a la posicion anterior (i)
        }
        vector[i+1] = aux; //Guardamos el valor del vector en la proxima posicion, el valor de aux
    }
   */
   }
}

void main(){
  tvector vec={4,3,5,2,1};

  printf("VECTOR ORIGINAL\n");
  mostrar(vec, MF);

  printf("\n\nMETODO DE INSERCION\n");
  ordenar_con_seguimiento(vec, MF);
       
  printf("\nVECTOR FINAL\n");
  mostrar(vec, MF);
  printf("\n");
       
  system("PAUSE");
}