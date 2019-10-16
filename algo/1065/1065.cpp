#include <stdio.h>

main() {
	int n;
	int a, b, c;
	int count = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		if (i == 1000) {
			break;
		}
		else if (i / 100) {
			a = i / 100;
			b = (i / 10) % 10;
			c = i % 10;

			if (a - b == b - c) {
				count++;
			}
		}
		else if (i / 10) {
			count++;
		}
		else
			count++;

	}

	printf("%d\n", count);
}
