import random
import time
import statistics

# Tamanhos de entrada
TAMANHO_PEQUENO = 10000
TAMANHO_MEDIO = 200000
TAMANHO_GRANDE = 1000000
REPETICOES = 30

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

def testar_quick_sort(tamanho, descricao):
    tempos = []

    print(f"===== Testando entrada {descricao} ({tamanho} elementos) =====")

    for i in range(REPETICOES):
        vetor = gerar_vetor(tamanho)

        ini = time.perf_counter()
        quick_sort(vetor, 0, len(vetor) - 1)
        fim = time.perf_counter()

        tempo = fim - ini
        tempos.append(tempo)
        print(f"Execução {i + 1:02d} concluída em {tempo:.4f} segundos")

    tempo_total = sum(tempos)
    media = statistics.mean(tempos)
    desvio = statistics.stdev(tempos)

    print(f"\nTempo TOTAL: {tempo_total:.6f} segundos")
    print(f"Tempo médio: {media:.6f} segundos")
    print(f"Desvio padrão: {desvio:.6f}")
    print("===============================================\n")

if __name__ == "__main__":
    testar_quick_sort(TAMANHO_PEQUENO, "pequena")
    testar_quick_sort(TAMANHO_MEDIO, "média")
    testar_quick_sort(TAMANHO_GRANDE, "grande")
