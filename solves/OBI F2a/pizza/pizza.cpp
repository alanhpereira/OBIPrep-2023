#include <stdio.h>

int main() {
	int n, m, g;
	scanf("%d%d%d", &n, &g, &m);
	int ans = (g * 8 + m * 6) - n;
	if (ans < 0) ans = 0;
	printf("%d\n", ans);
	return 0;
}