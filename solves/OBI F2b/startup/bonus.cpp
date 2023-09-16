#include <stdio.h>

#include <map>
#include <vector>
#define MAX 2123
using namespace std;

vector<int> sub[MAX];
map<int, int> salsub[MAX];
int chefe[MAX], salario[MAX];
int sm[MAX];
int insat = 0;
int n;

int cont() {
	for (int i = 1; i <= n; i++) {
		int flag = false;
		for (int j = 0; j < sub[i].size(); j++) {
			salsub[i][salario[sub[i][j]]] += 1;
		}
		if (salsub[i].upper_bound(salario[i]) != salsub[i].end()) {
			insat++;
			sm[i] = 1;
		}
	}
	return insat;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &chefe[i], &salario[i]);
		sub[chefe[i]].push_back(i);
	}
	printf("%d\n", cont());
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		int sa, isa;
		scanf("%d%d", &a, &b);
		sa = salario[a];
		isa = sm[a];

		salsub[chefe[a]][sa] -= 1;
		if (salsub[chefe[a]][sa] <= 0) salsub[chefe[a]].erase(sa);
		salsub[chefe[a]][b] += 1;
		if (a != 1) {
			insat -= sm[chefe[a]];
		}
		insat -= sm[a];
		salario[a] = b;
		sm[chefe[a]] = sm[a] = 0;
		if (salsub[a].upper_bound(salario[a]) != salsub[a].end()) {
			sm[a] = 1;
			insat++;
		}
		if (a != 1 && salsub[chefe[a]].upper_bound(salario[chefe[a]]) != salsub[chefe[a]].end()) {
			sm[chefe[a]] = 1;
			insat++;
		}

		printf("%d\n", insat);
	}
	return 0;
}