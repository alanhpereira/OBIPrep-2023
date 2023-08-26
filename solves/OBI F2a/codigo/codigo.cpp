#include <stdio.h>
#define MAX 1123

char s[MAX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &s[i]);
	}
	char c = s[0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == c) {
			cnt++;
		}
		else {
			printf("%d %c ", cnt, c);
			cnt = 1;
			c = s[i];
		}
	}
	printf("%d %c\n", cnt, c);
	return 0;
}