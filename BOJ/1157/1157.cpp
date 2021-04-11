#include <stdio.h>
#include <string.h>

main() {
	int alpha[26] = { 0 };
	char line[1000001];
	int i;
	int count = 0;// 중복횟수를 판단함
	int max=0; 
	int point=0;// 최대값인 부분을 가르킴
    int len;
    
	scanf("%s",line);
    len = strlen(line);
	for (i = 0; i < len; i++) { //배열에 데이터 저장.
		if ('a' <= line[i] && line[i] <= 'z') {
			alpha[line[i] - 'a']++;
		}
		else if ('A' <= line[i] && line[i] <= 'Z') {
			alpha[line[i] - 'A']++;
		}
	}

	for (i = 0; i < 26; i++) { //최대값을 찾고 최대값에 해당하는 위치를 저장.
		if (max < alpha[i]) {
			max = alpha[i];
			point = i;
		}
	}

	for (i = 0; i < 26; i++) { //최대값과 같은 값의 중복횟수를 저장.
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
