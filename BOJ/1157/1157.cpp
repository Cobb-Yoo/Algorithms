#include <stdio.h>
#include <string.h>

main() {
	int alpha[26] = { 0 };
	char line[1000001];
	int i;
	int count = 0;// �ߺ�Ƚ���� �Ǵ���
	int max=0; 
	int point=0;// �ִ밪�� �κ��� ����Ŵ
    int len;
    
	scanf("%s",line);
    len = strlen(line);
	for (i = 0; i < len; i++) { //�迭�� ������ ����.
		if ('a' <= line[i] && line[i] <= 'z') {
			alpha[line[i] - 'a']++;
		}
		else if ('A' <= line[i] && line[i] <= 'Z') {
			alpha[line[i] - 'A']++;
		}
	}

	for (i = 0; i < 26; i++) { //�ִ밪�� ã�� �ִ밪�� �ش��ϴ� ��ġ�� ����.
		if (max < alpha[i]) {
			max = alpha[i];
			point = i;
		}
	}

	for (i = 0; i < 26; i++) { //�ִ밪�� ���� ���� �ߺ�Ƚ���� ����.
		if (max == alpha[i]) {
			count++;
		}
	}

	if (count == 1) {
		printf("%c\n", 'A' + point);
	}
	else {
		printf("?\n");
	}
}
