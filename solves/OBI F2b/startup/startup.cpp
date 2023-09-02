#include <stdio.h>

#include <vector>
#define MAX 2123
using namespace std;

vector<int> sub[MAX];
int chefe[MAX], salario[MAX];
int sm[MAX];
int insat = 0;
int n;

int cont() {
	for (int i = 1; i <= n; i++) {
		int flag = false;
		for (int j = 0; j < sub[i].size(); j++) {
			if (salario[i] < salario[sub[i][j]]) {
				flag = true;
				sm[i]++;
			}
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
		int sa, isa;
		scanf("%d%d", &a, &b);
		sa = salario[a];
		isa = sm[a];

		if (sa > salario[chefe[a]] && b <= salario[chefe[a]]) {
			sm[chefe[a]]--;
			if (sm[chefe[a]] == 0) insat--;
		}
		if (sa <= salario[chefe[a]] && b > salario[chefe[a]]) {
			sm[chefe[a]]++;
			if (sm[chefe[a]] == 1) insat++;
		}

		salario[a] = b;

		sm[a] = 0;
		for (int j = 0; j < sub[a].size(); j++) {
			if (salario[a] < salario[sub[a][j]]) {
				sm[i]++;
			}
		}
		if (isa > 0 && sm[i] == 0) insat--;

		if (isa == 0 && sm[i] > 0) insat++;
		printf("%d\n", insat);
	}
	return 0;
}