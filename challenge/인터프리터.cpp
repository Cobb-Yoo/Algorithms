#include <stdio.h>

main() {
	char line[1000]; 
	int reg[10];
	int ram[1000];
	int ram_num;
	int done;
	int case_count; // 케이스 카운트
	int pc;//프로그램 카운트, 지금 보고 있는 레지스터의 주소
	int total_case; // 프로그램이 돌아간 횟수
	int tmp;
	int inst,arr1,arr2;//렘의 각 자리를 계산하기 위함

	scanf("%d", &case_count);

	for (int t = 0; t < case_count; t++) {
		for (tmp = 0; gets(line) && *line; tmp++) {
			sscanf(line, "&d", &ram[tmp]);
		}

		for (; tmp < 1000; tmp++) { // 입력 받은 램값 이후의 램을 초기화
			ram[tmp] = 0;
		}
		for (int i = 0; i < 10; i++) {
			reg[i] = 0;
		}

		done = 0;
		pc = 0;
		total_case = 0;

		gets(line);
		while (!done) {
			pc++;
			total_case = 0;
			inst = ram[pc] / 100;
			arr1 = (ram[pc] / 10) % 10;
			arr2 = ram[pc] % 10;


			switch (inst)
			{
			case 1:
				if (arr1 == 0 && arr2 == 0) {
					done = 1;
					break;
				}
				break;
			case 2:
				reg[arr1] = arr2;
				break;
			case 3:
				reg[arr1] = (reg[arr1] + arr2) % 1000;
				break;
			case 4:
				reg[arr1] = (reg[arr1] * arr2) % 1000;
				break;
			case 5:
				reg[arr1] = reg[arr2];
				break;
			case 6:
				reg[arr1] = (reg[arr1] + reg[arr2]) % 1000;
				break;
			case 7:
				reg[arr1] = (reg[arr1] * reg[arr1]) % 1000;
			case 8:
				reg[arr1] = ram[reg[arr2]];
			case 9:
				ram[reg[arr2]] = reg[arr1];
			case 0:
				if (reg[arr2] != 0)
					pc = reg[arr1];
			}
		}
		printf("%d\n",total_case);
	}
}
