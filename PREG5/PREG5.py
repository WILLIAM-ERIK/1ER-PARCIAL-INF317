compara=0
aux=0

palabra = input("Verifica si es palindromo el siguiente texto: ")
for i in reversed(range(0, len(palabra))):
  if palabra[i].lower() == palabra[aux].lower():
    compara = compara + 1
  aux = aux + 1


if len(palabra) == compara:
  print("VERDADERO")
else:
  print("FALSO")