# 4. Ingresar tres numeros y hallar el mayor.

# Programa hallar el mayor de 3 numeros (para el 0 == 0 == 0 imprime 3 veces, habria que hacer la correcta validación)
num1 = int(input("Ingrese el 1er número: "))
num2 = int(input("Ingrese el 2do número: "))
num3 = int(input("Ingrese el 3er número: "))

if (num1 >= num2) and (num1 >= num3):
    print(f"{num1} es el mayor a todos")
if (num1 <= num2) and (num2 >= num3):
    print(f"{num2} es el mayor a todos")
if (num3 >= num2) and (num1 <= num3):
    print(f"{num3} es el mayor a todos")

# Fin programa