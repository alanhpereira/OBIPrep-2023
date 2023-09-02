#include <stdio.h>

#include <vector>
#define MAX 2123
using namespace std;

vector<int> sub[MAX];
int chefe[MAX], salario[MAX];
int n;

int cont() {
	int insat = 0;
	for (int i = 1; i <= n; i++) {
		int flag = false;
		for (int j = 0; j < sub[i].size(); j++) {
			if (salario[i] < salario[sub[i][j]]) flag = true;
		}
		insat += flag;
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
		scanf("%d%d", &a, &b);
		salario[a] = b;

		printf("%d\n", cont());
	}
	return 0;
}