/*
Una agencia de autos posee un archivo denominado Autos.dat, cuyos registros contienen el código de auto (entero),
descripción del auto (string de 1000), precio (float), no “entra” en memoria en su totalidad.
Se pide desarrollar un programa en lenguaje C que permita ingresar al usuario un precio  y que permita: 
Generar una tabla llamada MasCaros que contenga toda la información (código, precio) de aquellos autos que superen el precio ingresado.
Asumir que esta tabla tendrá como máximo 100
*/

#include <stdio.h>
#define MAX_STRING 1000
#define MAX 100

typedef char Tstring[MAX_STRING];

typedef struct{
    int codigo_auto;
    Tstring descripcion;
    float precio;
} Tauto;

typedef struct{
    int codigo_auto;
    float precio;
} TRegMasCaros;

typedef TRegMasCaros TVecMasCaros[MAX];

void generar_tabla(FILE *archivo , TVecMasCaros autos, int *ml , float precio) {
    Tauto auto;

    *ml = 0;
    
    fread(&auto, sizeof(auto), 1, archivo);

    while (!feof(archivo) && (*ml < MAX)) {
        if(auto.precio > precio) {
            autos[*ml].codigo_auto = auto.codigo_auto;
            autos[*ml].precio = auto.precio;
            (*ml)++;
        }
        fread(&auto, sizeof(auto), 1, archivo);
    }
}

int main(){
    TVecMasCaros MasCaros;
    FILE *archivo;
    float precio;
    int ML;

    printf("Ingrese un precio.");
    scanf("%f", &precio);

    archivo = fopen("Autos.dat", "rb");
    if(archivo == NULL)
        printf("El archivo no pudo ser abierto");
    else{    
        generar_tabla(archivo, MasCaros, &ML, precio);
        fclose(archivo);
    }
    return 0;
}