# 6. Calcular la suma de los n primeros numeros naturales.

# Programa Calcular la suma de los n primeros numeros naturales (en duda):

n = int(input("Ingrese los n numeros naturales: "))
suma = 0

while n <= 0:
    print("Usted ingreso un n menor/igual a 0, vuelva a ingresarlo")
    n = int(input("Ingrese los n numeros naturales: "))

for i in range(1, n+1):
    suma = suma + i
    print(suma)
print(f"La suma de los primeros {n} numeros naturales es {suma}")

# Fin programa