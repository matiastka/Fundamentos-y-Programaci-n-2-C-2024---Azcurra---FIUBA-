/*
Una empresa de venta de productos alimenticios posee los siguientes listados:
Listado de Stock: Código de producto (entero de 4 cifras), Cantidad en stock (real mayor que cero).

Listado de Productos: Código de producto (entero de 4 cifras), Descripción, Precio unitario.

Listado de Ventas: Código de producto (entero de 4 cifras), Cantidad vendida en una venta.

Los listados de Stock y Productos están ordenados por código y no necesariamente todos los registros de uno están en el otro. 
El listado de ventas corresponde a un día y no está ordenado. 

Se pide: 
a) Listar por pantalla la cantidad total vendida por producto.

b) Listar por pantalla el monto de venta por producto y el monto total.

c) Listar por pantalla el stock actualizado por producto, eliminando de la misma aquellos productos sin existencia
 y generando una lista aparte de faltantes.
*/

# include <stdio.h>
# include <string.h>
# include <stdbool.h> // Por aria para no repetir el total vendido cuando imprimimos
# define MAX 100

typedef struct {
    int codigo;
    float cant_stock;
} Tstock;

typedef struct{
    int codigo;
    char descripcion[100];
    float precio_unitario;
} Tproducto;

typedef struct{
    int codigo;
    float cant_ventas;
} Tventa;

typedef Tstock TvecStocks[MAX];
typedef Tproducto TvecProductos[MAX];
typedef Tventa TvecVentas[MAX];

void ValidarCodigo(int *codigo){
    printf("Ingrese el codigo del producto (con 4 cifras, 0 para finalizar): ");
    scanf("%i", codigo);

    while ((*codigo < 1000) && (*codigo != 0)){
        printf("Ingrese el codigo del producto (con 4 cifras, 0 para finalizar): ");
        scanf("%i", codigo);
    }
}

void ValidarCantStock(float *cant_stock){
    printf("Ingrese la cantidad en stock (real mayor a 0): ");
    scanf("%f", cant_stock);

    while (*cant_stock <= 0){
        printf("Ingrese la cantidad en stock (real mayor a 0): ");
        scanf("%f", cant_stock);
    }
}

void CargarStock(TvecStocks stocks, int *ML){
    int contador;

    printf("Cargando Stocks:\n");

    contador = 0;
    ValidarCodigo(&stocks[contador].codigo); // Ya el ValidarCodigo se encarga de cargar a la tabla al struct stock el dato al campo codigo

    while ((contador < MAX) && (stocks[contador].codigo != 0)){
        ValidarCantStock(&stocks[contador].cant_stock); // Ya el ValidarCantStock se encarga de cargar a la tabla al struct stock el dato al campo cant_stock

        contador++;

        ValidarCodigo(&stocks[contador].codigo); 
    }
    *ML = contador;
}

void CargarProductos(TvecProductos productos, int *ML){ 
    int contador;

    printf("Cargando Productos:\n");

    contador = 0;
    ValidarCodigo(&productos[contador].codigo); 

    while ((contador < MAX) && (productos[contador].codigo != 0)){
        printf("Ingrese la descripcion del producto (menor a 100 caracteres): ");
        scanf("%s", productos[contador].descripcion);

        printf("Ingrese el precio unitario del producto: ");
        scanf("%f", &productos[contador].precio_unitario);

        contador++;

        ValidarCodigo(&productos[contador].codigo);
    }
    *ML = contador;
}

void CargarVentas(TvecVentas ventas, int *ML){
    int contador;

    printf("Cargando Ventas:\n");

    contador = 0;
    ValidarCodigo(&ventas[contador].codigo);

    while ((contador < MAX) && (ventas[contador].codigo != 0)){
        printf("Ingrese la cantidad de ventas vendidas hoy: ");
        scanf("%f", &ventas[contador].cant_ventas);

        contador++;

        ValidarCodigo(&ventas[contador].codigo); 
    }
    *ML = contador;
}

void MostrarStock(Tstock stocks){ // Mostramos un struct de stocks
    printf("%i\t", stocks.codigo);
    printf("%f\n", stocks.cant_stock);
}

void MostrarTablaStock(TvecStocks stocks, int ML){
    int contador;
    // Encabezado
    printf("Codigo\t");
    printf("Cant Stock\n");

    for(contador = 0; contador < ML; contador++){
        MostrarStock(stocks[contador]);
        printf("\n");
    }
}

void MostrarProducto(Tproducto productos){ // Mostramos un struct de stocks
    printf("%i\t", productos.codigo);
    printf("%s\t\t", productos.descripcion);
    printf("%f\n", productos.precio_unitario);
}

void MostrarTablaProducto(TvecProductos productos, int ML){
    int contador;
    
    // Encabezado
    printf("Codigo\t");
    printf("Descripcion\t");
    printf("Precio Unitario\n");

    for(contador = 0; contador < ML; contador++){
        MostrarProducto(productos[contador]);
        printf("\n");
    }
}

void MostrarVenta(Tventa ventas){ // Mostramos un struct de stocks
    printf("%i\t", ventas.codigo);
    printf("%f\n", ventas.cant_ventas);
}

void MostrarTablaVenta(TvecVentas ventas, int ML){
    int contador;
        
    // Encabezado
    printf("Codigo\t");
    printf("Cant Ventas\n");

    for(contador = 0; contador < ML; contador++){
        MostrarVenta(ventas[contador]);
        printf("\n");
    }
}

void OrdenarPorCodigodeStocks(TvecStocks stocks, int ML){
    int i,j;
    Tstock aux;

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML-i; j++){
            if (stocks[j].codigo > stocks[j + 1].codigo){
                aux = stocks[j];
                stocks[j] = stocks[j + 1];
                stocks[j + 1] = aux;
            }
        }
    }
}

void OrdenarPorCodigodeProductos(TvecProductos productos, int ML){
    int i,j;
    Tproducto aux;

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML-i; j++){
            if (productos[j].codigo > productos[j + 1].codigo){
                aux = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = aux;
            }
        }
    }
}

// Ayudado por Aria :D

//a) Listar por pantalla la cantidad total vendida por producto.

void MostrarTotalVendidodeProducto(TvecVentas ventas, int ML){ // Completamente Aria (dijo del doble ciclo)
    int i, j;
    float total_vendido;

    for (i = 0; i < ML; i++){
        total_vendido = 0;
        for (j = 0; j < ML; j++){
            if (ventas[i].codigo == ventas[j].codigo){
                total_vendido = total_vendido + ventas[j].cant_ventas; 
            }
        }
        printf("El total vendido del producto (%i) es: %f\n", ventas[i].codigo, total_vendido); // Lo malo es que se repite 
        
    }
}

// b) Listar por pantalla el monto de venta por producto y el monto total.

void MostrarProductoporventaymonto(TvecProductos productos, int ML_productos, TvecVentas ventas, int ML_ventas){
    int i,j;
    float monto_venta, monto_total;

    monto_total = 0;

    for (i = 0; i < ML_productos; i++){
        monto_venta = 0;
        for (j = 0; j < ML_ventas; j++){
            if (productos[i].codigo == ventas[j].codigo){
                monto_venta = monto_venta + (ventas[j].cant_ventas * productos[i].precio_unitario); // Monto de venta por producto, se calcula: monto + (cant_ventas * precio) (de un producto)
            }
        }

        if (monto_venta > 0){
            printf("EL monto vendido del producto es: %f\n", monto_venta);
            monto_total = monto_total + monto_venta;
        }
    }
    printf("EL monto total de las ventas es: %f\n", monto_total);
}

// c) Listar por pantalla el stock actualizado por producto, eliminando de la misma aquellos productos sin existencia y generando una lista aparte de faltantes.

void CargarsinStock(TvecStocks sin_stocks, int *ML, Tstock stock, int contador){

    sin_stocks[contador].codigo = stock.codigo;
    sin_stocks[contador].cant_stock = stock.cant_stock;
    (*ML)++;
}

void MostrarProductosConySinStock(TvecStocks stocks, int ML_stocks, TvecVentas ventas, int ML_ventas){ // En productos se refiere a los codigos de los productos de las listas stock y ventas
    int i,j, ML_sin_stocks, k;
    TvecStocks sin_stocks;
    float cant_vendidos;
    
    k = 0;
    ML_sin_stocks = 0;

    printf("\nProductos con stock:\n");
    for (i = 0; i < ML_stocks; i++){ // Recorremos los stocks
        cant_vendidos = 0;

        for (j = 0; j < ML_ventas; j++){ // Recorremos las ventas
            if (stocks[i].codigo == ventas[j].codigo){
                cant_vendidos = cant_vendidos + ventas[j].cant_ventas;
            }
        }
        
        // Restamos los vendidos al stock:
        stocks[i].cant_stock = stocks[i].cant_stock - cant_vendidos;
        if (stocks[i].cant_stock < 0){
            stocks[i].cant_stock = 0;
        }

        if(stocks[i].cant_stock > 0){
            MostrarStock(stocks[i]);
        }
        else{
            CargarsinStock(sin_stocks, &ML_sin_stocks, stocks[i], k); // Guardamos un registro de stocks a sin stocks con el contador k que es el contador de sin stocks
            k++;
        }
    }
    printf("\nProductos sin stock:\n");
    MostrarTablaStock(sin_stocks, ML_sin_stocks);
}

void main(){
    TvecStocks stocks;
    TvecProductos productos;
    TvecVentas ventas;
    int ML_stocks, ML_productos, ML_ventas;

    CargarStock(stocks, &ML_stocks); 
    CargarProductos(productos, &ML_productos);
    CargarVentas(ventas, &ML_ventas);

    OrdenarPorCodigodeStocks(stocks, ML_stocks);
    OrdenarPorCodigodeProductos(productos, ML_productos);

    // a) Se repite si pones mas de una vez un producto (habria que mejorarlo)
    MostrarTotalVendidodeProducto(ventas, ML_ventas);

    // b)
    MostrarProductoporventaymonto(productos, ML_productos, ventas, ML_ventas);

    // c)
    MostrarStockActualizadoySinStock(stocks, ML_stocks, ventas, ML_ventas);
}