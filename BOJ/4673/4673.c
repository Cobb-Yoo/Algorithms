#include <stdio.h>

int num[10001] = { 0 };

int search_selfnum(int n) {
	int add = n;

	if (n / 1000) { //4자리 수 일때
		add += n / 1000;
		add += (n / 100) % 10;
		add += (n / 10) % 10;
		add += n % 10;
	}

	else if (n / 100) {//3자리
		add += n / 100;
		add += (n / 10) % 10;
		add += n % 10;
	}

	else if (n / 10) {//2자리
		add += n / 10;
		add += n % 10;
	}
	else
		add += n;

	if (add <= 10000) num[add] = 1;
	else return add;
}

main() {
	int n,i;

	for (i = 1; i <= 10000; i++) {
		n = i;
		for (;;) {
			n = search_selfnum(n);
			if (n <= 10000) continue;
			else break;
		}
	}

	for (i = 1; i <= 10000; i++) {
		if (num[i] == 0) printf("%d\n", i);
	}
}
