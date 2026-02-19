# 7. Ingresar un numero que representa un mes, escribir el nombre del mes correspondiente. Puede haber error en el numero dado.

# Programa representar un mes
numero_mes = int(input("Ingrese un número de un mes del año: "))
while (numero_mes < 1 or numero_mes > 12):
    print("Usted ingreso un número del mes no válido, por favor ingreselo nuevamente")
    numero_mes = int(input("Ingrese un número de un mes del año: "))
if numero_mes == 1:
    print("Enero")
elif numero_mes == 2:
    print("Febrero")
elif numero_mes == 3:
    print("Marzo")
elif numero_mes == 4:
    print("Abril")
elif numero_mes == 5:
    print("Mayo")
elif numero_mes == 6:
    print("Junio")
elif numero_mes == 7:
    print("Julio")
elif numero_mes == 8:
    print("Agosto")
elif numero_mes == 9:
    print("Septiembre")
elif numero_mes == 10:
    print("Octubre")
elif numero_mes == 11:
    print("Noviembre")
else:
    print("Diciembre")

# Fin programa