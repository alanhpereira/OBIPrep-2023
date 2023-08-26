#include <stdio.h>

int main() {
	int n, i, p;
	scanf("%d%d%d", &n, &i, &p);
	i += p - 1;
	i %= n;
	printf("%d\n", i + 1);
	return 0;
}