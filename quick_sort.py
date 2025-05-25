import random
import time

TAMANHO_PEQUENO = 10000
TAMANHO_MEDIO = 200000
TAMANHO_GRANDE = 1000000

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

def gerar_vetor(tamanho):
    return [random.randint(0, 1000000) for _ in range(tamanho)]

def main():
    print("Escolha o tamanho da entrada:")
    print(f"1 - Pequena ({TAMANHO_PEQUENO} elementos)")
    print(f"2 - Média   ({TAMANHO_MEDIO} elementos)")
    print(f"3 - Grande  ({TAMANHO_GRANDE} elementos)")
    
    opcao = input("Opção: ").strip()
    
    if opcao == '1':
        tamanho = TAMANHO_PEQUENO
        descricao = "pequena"
    elif opcao == '2':
        tamanho = TAMANHO_MEDIO
        descricao = "média"
    elif opcao == '3':
        tamanho = TAMANHO_GRANDE
        descricao = "grande"
    else:
        print("Opção inválida.")
        return

    vetor = gerar_vetor(tamanho)
    print(f"Ordenando vetor de entrada {descricao} ({tamanho} elementos)...")

    ini = time.perf_counter()
    quick_sort(vetor, 0, len(vetor) - 1)
    fim = time.perf_counter()

    tempo = fim - ini
    print(f"Tempo de execução: {tempo:.6f} segundos")

if __name__ == "__main__":
    main()
