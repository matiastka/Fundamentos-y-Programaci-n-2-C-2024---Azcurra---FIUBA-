/*
Dado un archivo de números enteros mayores o iguales que 0, generar otro
archivo que almacene los factoriales de cada número del registro correspondiente del archivo de entrada. 
*/

# include <stdio.h>

typedef struct{
    int numeros;
} Tnumeros;

void calcular_factorial(int *valor){
    int contador, resultado;
    if (*valor < 2){
        *valor = 1;
    }
    else{
        resultado = 1;
        for (contador = resultado; contador > 0; contador--){
            resultado = resultado * contador;
        }
        *valor = resultado;
    }
}

void cargar_factoriales_archivo(FILE *archivo_entrada, FILE *archivo_salida){
    Tnumeros numero;
    
    fread(&numero, sizeof(numero), 1, archivo_entrada);

    while (!feof(archivo_entrada)){
        calcular_factorial(&numero.numeros);
        
        fwrite(&numero, sizeof(numero), 1, archivo_salida);

        fread(&numero, sizeof(numero), 1, archivo_entrada);
    }
}

void main(){
    FILE *archivo_entrada, *archivo_salida;

    archivo_entrada = fopen("archivo_eje1_numeros_enteros.dat", "rb");
    archivo_salida = fopen("archivo_eje1_numeros_factoriales.dat", "wb");

    if (archivo_entrada == NULL){
        printf("El archivo de los numeros enteros no se pudo abrir");
    }
    else if(archivo_salida == NULL){
        printf("El archivo de los numeros factoriales no se pudo abrir");
    }
    else{
        cargar_factoriales_archivo(archivo_entrada, archivo_salida);
        fclose(archivo_entrada);
        fclose(archivo_salida);
    }
}