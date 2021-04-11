#include <stdio.h>
#include <stdlib.h>

int compare(void *first, void *second) {
	if (*(int*)first > *(int*)second) {
		return 1;
	}
	else if (*(int*)first < *(int*)second) {
		return -1;
	}
	else
		return 0;
}

main() {
	int n,i;
	int *arr;

	scanf("%d", &n);

	arr = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), compare);

	for (i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
}
