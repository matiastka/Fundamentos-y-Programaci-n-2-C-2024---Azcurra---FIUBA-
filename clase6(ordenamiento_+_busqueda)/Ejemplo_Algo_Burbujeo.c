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
  // método burbujeo
  for(i=1; i<n; i++){ //ciclo de n-1 iteraciones
    for(j=0; j<n-i; j++){ // "burbujeo" del mayor valor
      if(vector[j] > vector[j+1]){  //si corresponde intercambio
         aux=vector[j];
         vector[j]=vector[j+1];
         vector[j+1]=aux;
       }
    }
  }
} 


void ordenar_con_seguimiento(tvector vector, int n) // n es la # de elementos que quiero ordenar
{
  int i, j, aux;    
     
  for(i=1; i<n; i++){ //ciclo de n-1 iteraciones (i es la #iteraciones)
    for(j=0; j<n-i; j++){ // "burbujeo" del mayor valor ()
      if(vector[j] > vector[j+1]){  //si corresponde intercambio
         aux=vector[j];
         vector[j]=vector[j+1];
         vector[j+1]=aux;
      }
      mostrar(vector, n);
      printf("   i= %d   j= %d   j+1= %d \n",i,j,j+1);
    }
    printf("\n");
  }
}


void main(){
  tvector vec={4,3,5,2,1};

  printf("VECTOR ORIGINAL\n");
  mostrar(vec, MF);

  printf("\n\nMETODO DE BURBUJEO\n\n");
  ordenar_con_seguimiento(vec, MF);
       
  printf("\nVECTOR FINAL\n");
  mostrar(vec, MF);
  printf("\n");
       
  system("PAUSE");
}