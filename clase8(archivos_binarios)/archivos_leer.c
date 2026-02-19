# include <stdio.h>

# define MAX_NOM 50

typedef char string[MAX_NOM];

typedef struct{ 
    int DNI;
    string Nombre;
} Tregistro;

void main(){
    FILE *archivo;
    Tregistro registro;

    archivo = fopen("archivo.dat", "r");

    fread(&registro, sizeof(Tregistro),1, archivo); // Se pasa el registro al archivo (uno a la vez)

    if (!feof(archivo)){
        // Hacer lo que nos piden
    }
    fclose(archivo);
}