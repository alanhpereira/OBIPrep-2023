# Resolução comentada

## Problema 1: [Estatísticas](https://neps.academy/br/exercise/1904)

### Ideia geral

Neste problema, temos que falsificar dados jogando fora casos reportados, ou seja, o número de casos reportados em um dia pode apenas diminuir ou ficar estável, nunca subir. O problema pede que os dados de um dia nunca seja maior ao dia anterior, logo, se o número de casos abaixa, ele não pode voltar a subir, então todos os próximos dias devem ser menores ou iguais ao menor número de casos reportado em dias anteriores. A partir do segundo dia, comparamos com o menor numero de casos até agora, se o número de casos do dia atual for maior que o menor até agora, ajustamos o número de casos para o menor já observado e seguimos para o próximo dia, se for menor, atualizamos o menor. A solução final é a soma de todos as alterações que fizemos.  

### Vamos analisar as entradas dadas de exemplo: 

*  Entrada 1:  
100, 150, 200  
O primeiro dia define o menor como 100. No segundo dia, o número de casos é maior que o menor, logo alteramos ele para o menor, 150 - 100 -> 50 alterações. No terceiro dia, o número de casos também é maior, logo também alteramos, 200 - 100 -> 100 alterações. No total, 150 alterações.
*  Entrada 2  
5, 4  
O primeiro dia define o menor como 5. No segundo dia, o número de casos é menor que o menor até agora, logo atualizamos o menor. No total, 0 alterações.  
*  Entrada 3  
10, 0, 9, 8  
O primeiro dia define o menor como 10. No segundo dia, o número de casos é menor que o menor até agora, logo atualizamos o menor para 0. No terceiro dia, o número de casos é maior, logo alteramos para o menor, 9 - 0 -> 9 alterações. No quarto dia, o número de casos é maior, logo alteramos para o menor, 8 - 0 -> 8 alterações. No total, 17 alterações.  

### Implementação

```cpp
#include <stdio.h>
#define MAX 11234 //Limite de tamanho da entrada (é sempre bom deixar uma sobra)

int v[MAX];

int main() {
	int n, mn;
	int ans = 0;

	scanf("%d", &n);

    // Leitura do vetor
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

    // define o minimo inicial como o número de casos do primeiro dia
	mn = v[0];

    // para cada dia após o primeiro
	for (int i = 0; i < n; i++) {
		if (v[i] > mn) {        // se for maior que o menor atual
			ans += v[i] - mn;   // faz alteraçoes
		}
		else {                  //senão
			mn = v[i];          // redefine o menor
		}
	}
    // imprime a resposta
	printf("%d\n", ans);
	return 0;
}

```

## Problema 2: [Senha 2018](https://neps.academy/br/exercise/153)

### Ideia geral

Ler elemento por elemento até achar 2018 e contar quantos foram.

### Implementação:

```c++
#include <stdio.h>

int main() {
	int n, i = 0;
    // faz a leitura dentro da própria condição do while, e já compara
    // extremannte compacto, não necessáriamente o mais intuitivo
    // a conferencia de EOF serve apenas para deixar o scanf dentro do while e não necessáriamente ocorrerá
	while (scanf("%d", &n) != EOF && n != 2018) i++; 
	printf("%d\n", i);
	return 0;
}
```

## Problema 3 [Manchas](https://neps.academy/br/exercise/567)

### Ideia geral  

Nesse problema temos uma matriz preto e branco, e o que queremos saber é quantas manchas pretas distintas existem nas imagens. O problema da por escrito de uma forma meio complexa que dois pixeis estão na mesma mancha se é possível chegar de um a outro passando apenas por pixeis pretos, movendo apenas de maneira ortogonal(cima, baixo, direita, esquerda, sem diagonais). Isso pode ser simplificado para uma contagem de compontes conexas de um grafo, similar o problema [Gincana](https://neps.academy/br/exercise/309), entretanto, estamos trabalhando em uma matriz, não um grafo tradicional com arestas. Essa operação com matrizes é similar ao problema [Toca do Saci](https://neps.academy/br/exercise/57).  
Para a resolução da contagem de componentes conexas, percorremos a lista de nós, e quando achamos um nó não visitado, contamos mais uma componente e fazemos uma busca nesse nó para achar todos os nós que se é possível chegar a partir desse nó inicial não visitado. No enunciado desse problema, é recomendado evitar uma implementação recursiva, que seria uma dfs(busca em profundidade), entretanto, se bem implementada, essa solução consegue os 100 pontos. Como é recomendado uma implementação não recursiva, usaremos a BFS(Busca em largura) que usa filas.  
Para fazer a busca em grafos matriciais, conferimos para cada direção se a posição vizinha é válida (se não está fora na matriz), e se for um nó valido, se ele já foi visitado. Se não tiver sido visitado, no caso da BFS, a gente marca a distancia e colocamos na fila, ser fosse uma DFS, chamariamos a dfs desse novo elemento.  
Mesmo que não fosse possível uma solução para 100 pontos, há tambem pontuações parciais, que as vezes podem ser o diferencial entre passar ou não, a primeira parcial, valendo 10 pontos, era basicamente uma matriz 2x2, que pode ser facilmente conferida manualmente, e outra parcial valendo +20 pontos é basicamente uma unica linha. Na OBI, é possível enviar as duas separadamente e o sistema soma automaticamente as parciais.

### Implementação:

```c++
#include <stdio.h>

#include <queue>
#include <utility>
#define MAX 1123
using namespace std;

// utilidade para não precisar escrever toda vez por extenso o pair
typedef pair<int, int> pii;

// matriz dos pixeis
int p[MAX][MAX];
// matriz de distancia (se não foi visitado estará com -1)
int dist[MAX][MAX];

int n, m;
// vetores para determinar a direção
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

void bfs(int i, int j) {
	// iniciliza a fila vazia
	queue<pii> q;
	// insere o elemento inicial não visitado
	q.push({i, j});
	// marca o elemento inicial como visitado
	dist[i][j] = 0;
	while (q.size()) {		  // enquanto há coisa na fila
		i = q.front().first;  // atualiza a posição para o que está na fila
		j = q.front().second;
		q.pop();					   // remove da fila
		for (int k = 0; k < 4; k++) {  // para cada uma das 4 direções
			if (i + di[k] >= 0 && i + di[k] < n && j + dj[k] >= 0 && j + dj[k] < m) // confere se não vai sair da matriz
				if (dist[i + di[k]][j + dj[k]] == -1 && p[i + di[k]][j + dj[k]]) {  // confere se não foi visitado e o pixel é preto
					q.push({i + di[k], j + dj[k]}); // insere na fila
					dist[i + di[k]][j + dj[k]] = dist[i][j] + 1; //define a distancia
				}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &p[i][j]);  // leitura da matriz
			dist[i][j] = -1;        // inicialização da matriz de distancia
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (p[i][j] && dist[i][j] == -1) { // se um pixel é preto e não foi visitado
				ans++; // conta componente
				bfs(i, j); // procura todos da mesma componente
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

```