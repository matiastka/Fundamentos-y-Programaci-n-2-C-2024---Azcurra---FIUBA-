/*
Se pide un programa permita publicar productos a la venta por los alumnos de algoritmos 1. 
Se debe ingresar Código de producto nombre del producto, Descripción y precio.
1-Realizar una función que permita la carga de Productos.
2-Informar un listado de productos ordenados por Nombre del producto
3-Ingresar una palabra y realizar una búsqueda de productos que tengan dicha palabra en el nombre o descripción. 
4-Realizar un listado de los 10 productos mas caros
5-Mostrar un listado ordenado por Código de producto
6-Ingresar un código y mostrar todos los datos del producto.
NOTA:
- Los listados se deben mostrar:
Nombre          Descripción           Grupo     Código
XXXXXXXXXXXX    YYYYYYYYYYYYYY          1       1231
- Los string tienen un máximo de 30 caracteres

No es un ejercicio de final pero si aparece algun modulo de esto (ordenar, listar, etc)
*/

# include <stdio.h>
# include <String.h>
# include <stdbool.h>

# define MAX 100
# define MAX_CHAR 30

typedef char TString[MAX_CHAR];

typedef struct{
    int Codigo;
    TString Nombre;
    TString Descripcion;
    float Precio;
} TProducto;

typedef TProducto TVecProductos[MAX];

void Cargar(TVecProductos productos, int *ML){ // Hecho con while
    int i;

    i = 0;

    printf("Ingrese el codigo del producto (0 o negativo para finalizar): ");
    scanf("%i", &productos[i].Codigo);

    while ((i < MAX) && (productos[i].Codigo > 0)){

        printf("Ingresar nombre del producto: ");
        scanf("%s", productos[i].Nombre);

        printf("Ingrese la descripcion del producto: ");
        scanf("%s", productos[i].Descripcion);

        printf("Ingrese el precio del producto: ");
        scanf("%f", &productos[i].Precio);
        
        i++;
        // De esta forma se evita usar un if para validar si el codigo es 0 o no
        printf("Ingrese el codigo del producto (0 o negativo para finalizar): ");
        scanf("%i", &productos[i].Codigo);
    }
    *ML = i;
}

void OrdenarNombre(TVecProductos productos, int ML){ // Usamos ordenamiento burbujeo pero para tablas y de tipos strings 
    int i, j;
    TProducto aux;

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML-i; j++){
            if (strcmp(productos[j].Nombre, productos[j+1].Nombre) > 0){ // recordar que strcmp devuelve positivo si el 1ro es mayor al 2do, 0 si ambos son iguales y negativo si el 2do es mayor al 1ro
                aux = productos[j]; // Con esta linea hasta el final del if, ordena todo el registro
                productos[j] = productos[j + 1];
                productos[j + 1] = aux;
            }
        }
    }
}

void MostrarProducto(TProducto productos){ // Es una función que muestra un struct solamente
    // Se hace de esta forma en particular para que lo imprima en forma de tabla
    printf(" %i", productos.Codigo);
    printf(" %s", productos.Nombre);
    printf(" %s", productos.Descripcion);
    printf(" %f\n", productos.Precio);
}

void Listar(TVecProductos productos, int ML){
    int i;

    // Piden que lo mostremos en columnado, para eso se escriben los nomres de las columnas fuera del for y dentro se pone cada campo de la tabla (que es la funcion MostrarProducto)

    printf(" Codigo");
    printf(" Nombre");
    printf(" Descripción");
    printf(" Precio\n");

    for(i = 0; i < ML; i++){
        MostrarProducto(productos[i]); 
        printf("\n");
    } 
}

// Para hacer BuscarPalabra no se puede usar busqueda binaria porque pide que la palabra este contenida en el nombre o descipcion (son 2 motivos: 2 campos distintos y pide palabra contenida (no es algo definido)) 
void BuscarPalabra(TVecProductos productos, int ML){ // Usamos Busqueda simple para strings, usamos la funcion strstre que se fija si un string esta dentro de otro (devuelve NULL = false sino lo esta)
    int i;
    TString producto_buscado;
    bool encontrado;

    i = 0;
    encontrado = false;

    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%s", producto_buscado);

    while ((i < ML) && (encontrado == false)){
        if (strstr(productos[i].Nombre, producto_buscado) || strstr(productos[i].Descripcion, producto_buscado)){ // Se fija si la palabra buscada esta dentro del campo Nombre o Descripcion
            MostrarProducto(productos[i]);
            encontrado = true;
        }
        i++;
    }
    if (encontrado == false){
        printf("No se encontro el producto\n");
    }
}

void OrdenarPrecio(TVecProductos productos, int ML){ // Usamos ordenamiento por burbujeo para tablas (ya ni aclaro)
    int i, j;
    TProducto aux;

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            if (productos[j].Precio < productos[j+1].Precio){ //Ordenamos de forma descendente
                aux = productos[j]; //Con esto ordena todo el vector (es igual a como si fuera un arreglo)
                productos[j] = productos[j + 1];
                productos[j + 1] = aux;
            }
        }
    }
}

void OrdenarCodigo(TVecProductos productos, int ML){ // Usamos ordenamiento por burbujeo
    int i, j;
    TProducto aux;

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            if (productos[j].Codigo > productos[j+1].Codigo){ 
                aux = productos[j]; //Con esto ordena todo el vector (es igual a como si fuera un arreglo)
                productos[j] = productos[j + 1];
                productos[j + 1] = aux;
            }
        }
    }
}

int BusquedaBinariaCodigo(TVecProductos productos, int ML, int codigo_buscado){
    int primera_posicion, posicion_del_medio, ultima_posicion, posicion_buscada;
    bool encontrado; 

    primera_posicion = 0;
    ultima_posicion = ML;
    encontrado = false;
    posicion_buscada = -1;

    while (encontrado == false){
        if (codigo_buscado < productos[primera_posicion].Codigo || codigo_buscado > productos[ultima_posicion].Codigo){
            encontrado = true;
            posicion_buscada = -1;
        }
        else{
            posicion_del_medio = (primera_posicion + ultima_posicion)/2;
            if(codigo_buscado == productos[posicion_del_medio].Codigo){
                encontrado = true;
                posicion_buscada = posicion_del_medio;
            }
            else{
                if(codigo_buscado > productos[posicion_del_medio].Codigo){
                    primera_posicion = posicion_del_medio + 1;
                }
                else{
                    ultima_posicion = posicion_del_medio - 1;
                }
            }
        }
    }
    return posicion_buscada;
}

// Como Busqueda Binaria es tan largo lo modularizamos para que sea mas corta (hacemos la funcion BuscaCod)
void BuscarCodigo(TVecProductos productos, int ML){ // Como Los codigos estan ordenados (por OrdenarCodigos) entonces hacemos busqueda binaria
    int i, codigo_buscado;

    printf("Ingrese el codigo a buscar: ");
    scanf("%i", &codigo_buscado);

    i = BusquedaBinariaCodigo(productos, ML, codigo_buscado);
    if (i >= 0){
        MostrarProducto(productos[i]);
    }
    else{
        printf("No se encontro");
    }
}

void main(){
    TVecProductos Vec;
    int ML;

    Cargar(Vec, &ML);

    OrdenarNombre(Vec, ML);

    Listar(Vec, ML); // Es Mostrar(Vec, ML)

    BuscarPalabra(Vec, ML);

    OrdenarPrecio(Vec, ML);

    if (ML > 10){
        Listar(Vec, 10); 
    }
    else{
        Listar(Vec, ML);
    }

    OrdenarCodigo(Vec, ML);

    Listar(Vec, ML); 

    BuscarCodigo(Vec, ML);
}   