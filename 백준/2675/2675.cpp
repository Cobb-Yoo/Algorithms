#include <stdio.h>
#include <string.h>

main() {
	int n,m;
	int i,j,k;
	char line[21];
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %s", &m, line);

		for (j = 0; j < strlen(line); j++) {
			for (k = 0; k < m; k++) {
				printf("%c", line[j]);
			}
		}
		printf("\n");
	}
}
