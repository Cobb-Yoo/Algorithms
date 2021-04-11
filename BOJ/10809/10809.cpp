#include <stdio.h>
#include <string.h>

main() {
	int alpha[26] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	char line[100];
	int i;

	gets(line);

	for (i = 0; i < strlen(line); i++) {
		if (alpha[(line[i] - 'a')] == -1)
			alpha[(line[i] - 'a')] = i;
	}

	for (i = 0; i < 26; i++)
		printf("%d ", alpha[i]);
}
