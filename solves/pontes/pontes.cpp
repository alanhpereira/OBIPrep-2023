#include <stdio.h>

#include <queue>
#include <vector>
#define MAX 1123
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

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

int main() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(pii(w, v));
		adj[v].push_back(pii(w, u));
	}
	printf("%d\n", dijkstra());
	return 0;
}