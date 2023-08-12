# Programação dinâmica

Programação dinâmica é uma técnica que combina a eficiencia de um algoritmo guloso com a certeza de um algoritmo de busca completa(força bruta).  
A programação dinâmica tem dois usos principais:  
* Achar soluções ótimas
* Contar soluções possíveis

Um dos fundamentos das técnicas de PD é a memoização, que consiste em guardar respostas obtidas anteriormente para que não seja necessáro recalcular.
### Um exemplo:

Temos a sequência de fibonacci, que é uma função recursiva f(n) = f(n-1) + f(n-2), com condição de parara, n<=1 f(n) = 1. Vamos supor que queremos calcular f(5), f(5) chama f(4) e f(3), f(4), por sua vez chama f(3) novamente, e f(2), cada chamada de f(3) por sua vez chama f(2) novamente e f(1), e cada chamada f(2) chama f(1) e f(0), f(0) e f(1) são condição de parada, então não chamam mais nada; Contagem de chamadas:  
* f(5) -> 1  
* f(4) -> 1  
* f(3) -> 2  
* f(2) -> 3  
* f(1) -> 5  
* f(0) -> 3  
Podemos perceber que há chamadas desnecessárias, cada uma poderia só chamar as outras na primeira chamada, e depois salvar o valor. Para fazer isso usamos memoização.
```c++
int mem[MAX];
int calc[MAX];

int fib(int n){
    if(calc[n]) return mem[n];
    calc[n] = 1;
    if(n <= 1) return 1;
    return mem[n] = fib(n-1) + fib(n-2);
}
```

# Problemas

## Muro

Queremos saber de quantas maneiras é possível construir um muro de tamanho N com os blocos dados. Usaremos a função F(n), que é a maneira de construir muro de tamanho N. Por definição F(0) = 1. Conforme dado no enunciado, existem 7 formas de acabar um muro de tamanho N, uma que depende de f(N-1), 4 que dependem de f(N-2), e 2 que dependem de f(N-3), com isso a recursão fica: $$f(N) = f(N-1) + 4 * f(n-2) + 2 * f(N-3)$$

Passando isso pra código:

```c++
#include <stdio.h>
#define MAX 11234
#define MOD 1000000007
typedef long long ll;

ll mem[MAX], n;

ll dp(int i) {
	if (i < 0) return 0;
	if (mem[i] == -1) {
		if (i == 0) return mem[i] = 1;
		mem[i] = dp(i - 1);
		mem[i] += 4 * dp(i - 2);
		mem[i] += 2 * dp(i - 3);
		mem[i] %= MOD;
	}
	return mem[i];
}

int main() {
	scanf("%lld", &n);
	for (int i = 0; i <= n; i++) {
		mem[i] = -1;
	}
	printf("%lld\n", dp(n));
	return 0;
}
```

---

## Cut Ribbon

Temos uma fita de comprimento n, queremos cortar a fita de tal forma que no final cada tira tenha comprimento a, b ou c e que o número de tiras seja máximo. Temos f(x) que é o número máximo de tiras para uma fita de tamanho x. f(x) vai ser o máximo entre os 3 cortes possíveis a, b e c; Logo:  
$$f(x) = max(f(x-a), f(x-b), f(x-c))+1$$  
E também é necessário tomar cuidado para que o comprimento da tira seja válido.

```c++
#include <stdio.h>
#define MAX 4123

int mem[MAX];

int max(int a, int b) {
	if (a < b) return b;
	return a;
}

int main() {
	int n, a, b, c;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	mem[0] = 0;
	for (int i = 1; i <= n; i++) {
		mem[i] = -1;
		if (i >= a && mem[i - a] != -1) {
			mem[i] = max(mem[i], mem[i - a] + 1);
		}
		if (i >= b && mem[i - b] != -1) {
			mem[i] = max(mem[i], mem[i - b] + 1);
		}
		if (i >= c && mem[i - c] != -1) {
			mem[i] = max(mem[i], mem[i - c] + 1);
		}
	}
	printf("%d\n", mem[n]);
	return 0;
}

```