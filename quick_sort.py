def troca(v, i, j):
    v[i], v[j] = v[j], v[i]

def particao(v, inicio, fim):
    pivot = inicio
    indice = fim

    for i in range(fim, inicio, -1):
        if v[i] >= v[pivot]:
            troca(v, i, indice)
            indice -= 1

    troca(v, pivot, indice)
    return indice

def quick_sort(v, inicio, fim):
    if inicio < fim:
        p = particao(v, inicio, fim)
        quick_sort(v, inicio, p - 1)
        quick_sort(v, p + 1, fim)

# Exemplo de uso
if __name__ == "__main__":
    lista = [9, 4, 6, 2, 8, 1, 3]
    print("Lista original:")
    print(lista)

    quick_sort(lista, 0, len(lista) - 1)

    print("Lista ordenada:")
    print(lista)
