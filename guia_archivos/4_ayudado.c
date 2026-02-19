/*
Dados dos archivos de números enteros de 5 dígitos ordenados en forma creciente, generar un archivo que contenga todos los números, ordenado de igual forma. 
No hay números repetidos.
*/

# include <stdio.h>

typedef struct{
    int numero;
} Tnumero;

void CargarArchivo(FILE *archivo1, FILE *archivo2, FILE *archivo_destino){
    Tnumero numero1, numero2;

    fread(&numero1, sizeof(numero1), 1, archivo1); // Leemos el archivo1 en el struct numero1 (guardando los datos 1 a 1 de los campos del Tnumero). Inicia el contador del archivo1
    fread(&numero2, sizeof(numero2), 1, archivo2); // Leemos el archivo2 en el struct numero2 (guardando los datos 1 a 1 de los campos del Tnumero). Inicia el contador del archivo2

    while (!feof(archivo1) && !feof(archivo2)){ // Mientras no se llegue al fin del archivo1 y de archivo2
        if (numero1.numero > numero2.numero){ // Si el numero en numero1 (struct referido al archivo1) es mayor que numero2 (struct referido al archivo2) entonces:
            fwrite(&numero1, sizeof(numero1), 1, archivo_destino);
            fread(&numero1, sizeof(numero1), 1, archivo1); // Avanza el contador del archivo1 y manda a numero1 su proximo valor
        }
        else{ // Si el numero en numero2 (struct referido al archivo2) es mayor que numero1 (struct referido al archivo1) entonces:
            fwrite(&numero2, sizeof(numero2), 1, archivo_destino);
            fread(&numero2, sizeof(numero2), 1, archivo2); // Avanza el contador del archivo2 y manda a numero2 su proximo valor
        }
    }
}

void main(){
    FILE *archivo1, *archivo2, *archivo_destino;

    archivo1 = fopen("archivo1_eje4.dat", "rb");
    archivo2 = fopen("archivo2_eje4.dat", "rb");
    archivo_destino = fopen("archivo3_eje4.dat", "wb");

    if (archivo1 = NULL){
        printf("No se pudo abrir el archivo archivo1_eje4.dat");
    }
    else if (archivo2 == NULL){
        printf("No se pudo abrir el archivo archivo2_eje4.dat");
    }
    else if (archivo_destino == NULL){
        printf("No se pudo abrir el archivo archivo3_eje4.dat");
    }
    else{
        CargarArchivo(archivo1, archivo2, archivo_destino);
        fclose(archivo1);
        fclose(archivo2);
        fclose(archivo_destino);
    }
}