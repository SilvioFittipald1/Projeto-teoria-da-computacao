def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        # Escolhe o pivô como o elemento do meio (pode ser ajustado para aleatório, etc.)
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quick_sort(left) + middle + quick_sort(right)

import random

# Criando uma lista aleatória com 10 elementos
lista = random.sample(range(0, 100), 10)

print("Lista original:")
print(lista)

ordenada = quick_sort(lista)

print("Lista ordenada:")
print(ordenada)
