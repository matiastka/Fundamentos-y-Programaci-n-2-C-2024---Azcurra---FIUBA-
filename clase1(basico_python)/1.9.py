# 9. Dada una fecha: año, mes y dia. Informar si es correcta o no.

# Programa Informar fecha correcta
dia = int(input("Ingrese un dia: ")) 
mes = int(input("Ingrese un mes: "))
año = int(input("Ingrese un año: "))
if (dia > 0) and (dia < 32) and (mes > 0) and (mes < 13) and (año >= 0):
    print("La fecha es correcta")
else:
    print("La fecha es incorrecta")
# Fin Programa