#include <stdio.h>
#define MAX 1123

char s1[MAX], s2[MAX];

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &s1[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &s2[i]);
	}
	int i = 0;
	for (i = 0; i < n && i < m && s1[i] == s2[i]; i++)
		;
	printf("%d\n", i);
	return 0;
}