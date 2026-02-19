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
    int numero_camion;
    char destino[35];
    float costo;
    float peso;
} Ttransporte;

typedef Ttransporte TvecTrasnsporte[MAX];

void MostrarPatenteMasViajes_y_DestinoCordoba(FILE *archivo){
    Ttransporte transportista;

    int mayor_viajes, numero_camion_viaje, cant_viajes, camion_con_mas_viajes, cant_viajes_cordoba;

    mayor_viajes = -1;
    numero_camion_viaje = -1;
    camion_con_mas_viajes = -1;
    cant_viajes_cordoba = 0;

    fread(&transportista, sizeof(transportista), 1, archivo);
    numero_camion_viaje = transportista.numero_camion;
    cant_viajes = 1;

    while (!feof(archivo)){
        if (transportista.numero_camion == numero_camion_viaje){
            cant_viajes = cant_viajes + 1; // esto es cant_viajes++
        }
        else{
            if(cant_viajes > mayor_viajes){ // Antes de reiniciar cant_viajes vemos si es el mayor
                mayor_viajes = cant_viajes;
                camion_con_mas_viajes = numero_camion_viaje;
            }
            cant_viajes = 1; // Reinciamos la cant_viajes que tiene ese camion
            numero_camion_viaje = transportista.numero_camion; // Reasignamos el nro de camion al nuevo camion
        }

        if (strcmp(transportista.destino, "Córdoba") == 0){ // Si el campo destino es Córdoba entonces:
            cant_viajes_cordoba = cant_viajes_cordoba + 1;
        }
        
        fread(&transportista, sizeof(transportista), 1, archivo);
    }
    printf("El Nro de camion que realizo mas viajes fue: %i\n", camion_con_mas_viajes);
    printf("La cantidad de viajes realizados a Córdoba fueron: %i\n", cant_viajes_cordoba);
}

void main(){
    FILE *archivo;

    archivo = fopen("archivo_eje11.dat", "rb");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        MostrarPatenteMasViajes_y_DestinoCordoba(archivo);
        fclose(archivo);
    }
}