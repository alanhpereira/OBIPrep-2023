#include <stdio.h>

#include <vector>
#define MAX 1123456
using namespace std;

vector<int> g[MAX], ng[MAX];

int check(int e1, int e2, int e3) {
	int r = 0;
	for (int i = 0; i < g[e1].size(); i++) {
		if (g[e1][i] != e2 && g[e1][i] != e3) r++;
	}
	for (int i = 0; i < ng[e1].size(); i++) {
		if (ng[e1][i] == e2 || ng[e1][i] == e3) r++;
	}
	return r;
}

int main() {
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < d; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ng[a].push_back(b);
		ng[b].push_back(a);
	}
	int e1, e2, e3;
	int ans = 0;
	for (int i = 0; i < n / 3; i++) {
		scanf("%d %d %d", &e1, &e2, &e3);
		ans += check(e1, e2, e3);
		ans += check(e2, e1, e3);
		ans += check(e3, e1, e2);
	}
	printf("%d\n", ans / 2);
	return 0;
}