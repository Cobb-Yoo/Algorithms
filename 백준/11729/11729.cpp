#include <stdio.h>

void hanoi(int n, int a, int b, int c) {
	if (n == 1) {
		printf("%d %d\n", a, c);
	}
	else {
		hanoi(n - 1, a, c, b);
		printf("%d %d\n",a,c);
		hanoi(n - 1, b, a, c);
	}
}

main() {
	int n;
	int i;
	int count = 1;
	scanf("%d", &n);
	const int a = 1, b = 2, c = 3;

	for (i = 0; i < n; i++) {
		count *= 2;
	}
	printf("%d\n", count - 1);
	hanoi(n, a, b, c);
}
