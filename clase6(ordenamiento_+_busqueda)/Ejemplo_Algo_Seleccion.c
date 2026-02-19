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
  int i, j, aux;    
  // método selección
  for(i=0; i<n-1; i++){  //ciclo de n-1 iteraciones
    for(j=i+1; j<n; j++){ // comparo con los restantes
        if(vector[i] > vector[j]){ //si corresponde intercambio  
          aux=vector[i];                  
          vector[i]=vector[j];
          vector[j]=aux;
        }
      }
  }
}

void ordenar_con_seguimiento(tvector vector, int n)
{
  int i, j, aux;    
     
   for(i=0; i<n-1; i++){ //ciclo de n-1 iteraciones (puede ser tambien i < n)
      for(j=i+1; j<n; j++){ // comparo con los restantes (puede ser tambien j<=n)
        if(vector[i]>vector[j]){ //si corresponde intercambio  
          aux=vector[i];                  
          vector[i]=vector[j];
          vector[j]=aux;
        }
        mostrar(vector, n);
        printf("   i= %d   j= %d  \n",i,j);
     }
    printf("\n");
   }
}

void main(){
  tvector vec={4,3,5,2,1};

  printf("VECTOR ORIGINAL\n");
  mostrar(vec, MF);

  printf("\n\nMETODO DE SELECCION\n\n");
  ordenar_con_seguimiento(vec, MF);

  printf("\nVECTOR FINAL\n");
  mostrar(vec, MF);
  printf("\n");
     
  system("PAUSE");
}