#include <stdio.h>
#define MAX 112345

int lo[MAX];
int v[MAX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		lo[i] = -1;
	}
	int ans = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (lo[v[i]] >= j) {
			j = lo[v[i]] + 1;
		}
		lo[v[i]] = i;
		if (i - j + 1 > ans) ans = i - j + 1;
	}
	printf("%d\n", ans);
	return 0;
}