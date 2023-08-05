#include <stdio.h>
#include <vector>
#define MAX 11234
using namespace std;

vector<int> filhos[MAX];
int nivel[MAX];
int vis[MAX];
int totNiv[MAX];
int inNiv[MAX];

void dfs(int a, int nv) {
	if (vis[a])
		return;
	vis[a] = 1;
	nivel[a] = nv;
	totNiv[nv]++;
	for (int i = 0; i < filhos[a].size(); i++) {
		dfs(filhos[a][i], nv + 1);
	}
}

int main() {
	int n, m, a;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		filhos[a].push_back(i + 1);
	}
	dfs(0, 0);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		inNiv[nivel[a]]++;
	}
	for (int i = 1; totNiv[i] != 0; i++) {
		printf("%.2f ", (100.0 * inNiv[i] / totNiv[i]));
	}
	printf("\n");
	return 0;
}
