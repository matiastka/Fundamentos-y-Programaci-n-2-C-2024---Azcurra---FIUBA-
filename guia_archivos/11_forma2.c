/*
Una empresa que transporta carga tiene en un archivo los siguientes datos de cada viaje:
Nro de patente de del camión
Destino
Costo del viaje
Peso de la carga en KG
El archivo está ordenado por nro. de patente. Se pide:
a) Informar el nro. de patente del camión que realizó más viajes
b) Informar cuántos viajes se realizaron al destino “Córdoba”
*/

# include <stdio.h>
# include <string.h>
# define MAX 5

typedef struct{
    int numero_patente;
    char destino[35];
    float costo;
    float peso;
} Ttransporte;

void MostrarNumeroPatente(FILE *archivo){
    Ttransporte camion;
    int cantidad_viajes, patente_actual;

    cantidad_viajes = 0;

    fread(&camion, sizeof(camion), 1, archivo); // Leelo el archivo y mando al struct camion  los datos (depaso incializo el contador del archivo) 
    patente_actual = camion.numero_patente; 

    while(!feof(archivo)){ 
        if(camion.numero_patente == patente_actual){ 
            cantidad_viajes++;
        }
        else{
            cantidad_viajes = 1; 
            patente_actual = camion.numero_patente; 
        }
        fread(&camion, sizeof(camion), 1, archivo); 
    }
}

void main(){
    FILE *archivo;
    
    archivo = fopen("Ejercicio_11.dat", "rb");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        MostrarNumeroPatente(archivo);
        fclose(archivo);
    }
}