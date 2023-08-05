#include <stdio.h>

#include <vector>
#define MAX 112
using namespace std;

int x[MAX], y[MAX], vis[MAX];
vector<int> adj[MAX];

void dfs(int a) {
	if (vis[a]) return;
	vis[a] = true;
	for (int i = 0; i < adj[a].size(); i++) {
		dfs(adj[a][i]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && (x[i] == x[j] || y[i] == y[j])) {
				adj[i].push_back(j);
			}
		}
	}
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i);
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
