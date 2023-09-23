# Grafos: Dijkstra, e MST

## Dijkstra
* Algoritmo para encontra caminho minimo em grafo com peso
* Similar a uma BFS
* Temos uma fila de nós a serem computados
* Um vetor de menor distância já achada para cada nó
* O Truque de botar os elementos na fila com a distância total negativada para deixar em ordem crescente, uma vez que priority_queue por padráo ordena de maneira decrescente
```c++

vector<pii> adj[MAX];
int dist[MAX];
int vis[MAX];
int n;

int dijkstra() {
	priority_queue<pii> pq;
	for (int i = 0; i <= n + 1; i++) {
		dist[i] = -1;
		vis[i] = 0;
	}
	dist[0] = 0;
	pq.push(pii(0, 0));
	while (!pq.empty()) {
		int a, d;
		d = -pq.top().F;
		a = pq.top().S;
		pq.pop();
		if (vis[a]) continue;
		vis[a] = true;
		dist[a] = d;
		for (int i = 0; i < adj[a].size(); i++) {
			int e = adj[a][i].S;
			int w = adj[a][i].F;
			if (dist[e] == -1 || dist[e] > d + w) {
				pq.push(pii(-(d + w), e));
			}
		}
	}
	return dist[n + 1];
}
```

## Union Find
O estrutura de Union Find consiste em varios conjuntos de nós, e possui dois tipos de operação: Consulta e união
* Consulta: confere se dois nós estão no mesmo conjunto
* União: caso dois nós não estejam no mesmo conjunto, junta os componentes.  
[Artigo de refêrencia](https://www.geeksforgeeks.org/union-by-rank-and-path-compression-in-union-find-algorithm/)
### Implementação:

* Cada nó tem um pai, inicialmente o próprio nó.
* Cada conjunto tem um representante cujo pai é ele mesmo.
* O representante de um conjunto pode ser achado percorrendo a estrutura subindo para os pais até encontrar um qual o pai é si próprio
* Dois nós pertecem ao mesmo conjunto caso tenham o mesmo representante
* Para juntar dois conjuntos, se diz que o pai de um dos representantes é o outro representante.

### Otimizações

* Path compression  
    * Em operações de consulta, se comprime o caminho para futuras operações; Essa compressão é realizada redefinindo-se o pai para o representante do grupo
* Union by rank
    * Em uniões escolhe o representante com maior rank para ser o novo representante, e o de menor rank vai ser filho do de maior rank
    * Existem vários tipos de ranking, como altura total, número de elementos, entre outros

### Código

```c++
//inicialização
void init(int n){    
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		rank[i] = 1;
	}
}

//find com path compression
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}

//join com union by rank
void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (rank[a] > rank[b]) {
		p[b] = a;
		rank[a] += rank[b];
	}
	else {
		p[a] = b;
		rank[b] += rank[a];
	}
}
```

## Árvores geradoras: Algoritmo de Kruskal

Árvores geradoras são utilizadas para alguns algoritmos gulosos, consistem em selecionar arestas de um grafo de forma que o resultado seja uma árvore(grafo acíclico)

O algoritmo de Kruskal consiste em:  
1. Ordenar arestas por peso
2. Processar arestas em sequência:  
    1. Se as duas pontas da arestas forem de compontentes distintos:
    2. Adicionar aresta no grafo
    3. Juntar as duas components

```c++
	sort(edges.begin(), edges.end());
	int ans = 0;
	for (int i = 0; i < edges.size(); i++) {
		int u, v, w;
		w = edges[i].F;
		u = edges[i].S.F;
		v = edges[i].S.S;
		if (find(u) != find(v)) {
			ans += w;
			join(u, v);
		}
	}
```