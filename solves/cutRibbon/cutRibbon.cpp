#include <stdio.h>
#define MAX 4123

int mem[MAX];

int max(int a, int b) {
	if (a < b) return b;
	return a;
}

int main() {
	int n, a, b, c;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	mem[0] = 0;
	for (int i = 1; i <= n; i++) {
		mem[i] = -1;
		if (i >= a && mem[i - a] != -1) {
			mem[i] = max(mem[i], mem[i - a] + 1);
		}
		if (i >= b && mem[i - b] != -1) {
			mem[i] = max(mem[i], mem[i - b] + 1);
		}
		if (i >= c && mem[i - c] != -1) {
			mem[i] = max(mem[i], mem[i - c] + 1);
		}
	}
	printf("%d\n", mem[n]);
	return 0;
}
