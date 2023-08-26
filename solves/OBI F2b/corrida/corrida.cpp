#include <stdio.h>
#define MAX 112345

int min(int a, int b) {
	if (a < b) return a;
	return b;
}
int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	int n, l;
	char d;
	int minx, maxx, miny, maxy, x, y;
	minx = maxx = miny = maxy = x = y = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c", &l, &d);
		if (d == 'L')
			x += l;
		else if (d == 'O')
			x -= l;
		else if (d == 'N')
			y += l;
		else if (d == 'S')
			y -= l;
		minx = min(minx, x);
		maxx = max(maxx, x);
		miny = min(miny, y);
		maxy = max(maxy, y);
	}
	printf("%d\n", (maxx - minx + 2 + maxy - miny + 2) * 2);
	return 0;
}