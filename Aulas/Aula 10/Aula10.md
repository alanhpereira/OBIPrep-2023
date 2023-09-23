# Grafos: Dijkstra, e MST

## Dijkstra
* Algoritmo para encontra caminho minimo em grafo com peso
* Similar a uma BFS
* Temos uma fila de nós a serem computados
* Um vetor de menor distância já achada para cada nó
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