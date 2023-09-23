#include <stdio.h>

#include <algorithm>
#include <vector>

#define MAX 512
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

vector<piii> edges;

int p[MAX], cSize[MAX];

int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);  // path compression
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;			// previne uniões caso já seja do msmo conjunto
	if (cSize[a] > cSize[b]) {	// Union by rank
		p[b] = a;
		cSize[a] += cSize[b];
	}
	else {
		p[a] = b;
		cSize[b] += cSize[a];
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		cSize[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges.push_back(piii(w, pii(u, v)));
	}
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
	printf("%d\n", ans);
	return 0;
}