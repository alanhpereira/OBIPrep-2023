#include <stdio.h>
#define MAX 112345

int delta[MAX];

int main() {
	int n, tmax = 0;
	scanf("%d", &n);
	int a, b;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		delta[a]++;
		delta[b]--;
		tmax = tmax > b ? tmax : b;
	}
	int cnt = 0, ans = 0;
	for (int i = 0; i < tmax; i++) {
		cnt += delta[i];
		if (cnt > ans) ans = cnt;
	}
	printf("%d\n", ans * 20);
	return 0;
}