#include <stdio.h>
#define MAX 112345

int p[MAX], rank[MAX];

int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);  // path compression
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;		  // previne uniões caso já seja do msmo conjunto
	if (rank[a] > rank[b]) {  // Union by rank
		p[b] = a;
		rank[a] += rank[b];
	}
	else {
		p[a] = b;
		rank[b] += rank[a];
	}
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		rank[i] = 1;
	}
	for (int i = 0; i < k; i++) {
		char c;
		int a, b;
		scanf(" %c%d%d", &c, &a, &b);
		if (c == 'C') {
			printf("%c\n", find(a) == find(b) ? 'S' : 'N');
		}
		else {
			join(a, b);
		}
	}
	return 0;
}